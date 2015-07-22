#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#define FD 1;
using namespace std;

struct Date{
	int year,month,day;
};
int fdps(int year){
	static int first_day=FD;
	static int fd_year=1900;
	if(fd_year>year){
        first_day=FD;
        fd_year=1900;
	}
	for(int i=fd_year;i<year;++i){
		++fd_year;
		if(!(i%400)||!(i%4)&&(i%100))
			first_day=(first_day+366)%7;
		else
			first_day=(first_day+365)%7;
	}
	return(first_day);
}

int day_num(int year,int month,int day,int first_day){
	int leap_year[]={0,0,31,60,91,121,152,182,213,244,274,305,335,366};
	int not_leap_year[]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};
	int *p=not_leap_year;
	if(!(year%400)||!(year%4)&&(year%100))
		p=leap_year;
    int total_num=p[month]+day,use_num;
	use_num=(total_num+first_day-1)/7*5+((total_num+first_day-1)%7>5?5:(total_num+first_day-1)%7);
	use_num-=first_day<6?first_day-1:5;
	if(first_day<6&&total_num>0)
		--use_num;
	if(total_num>p[5]){
		first_day=(first_day+p[5])%7;
		total_num-=p[5];
		for(int i=0;i<3&&total_num>0;++i,first_day=(first_day+1)%7,--total_num)
			if(first_day!=6&&first_day!=0)
				--use_num;
	}
	if(total_num>p[10]-p[5]-3){
		first_day=(first_day-3+p[10]-p[5])%7;
		total_num-=(p[10]-p[5]-3);
		for(int i=0;i<7&&total_num>0;++i,first_day=(first_day+1)%7,--total_num)
			if(first_day!=6&&first_day!=0)
				--use_num;
	}
	return(use_num);
}

int same_year(Date date1,Date date2){
	int first_day=fdps(date1.year);
	//cout<<day_num(date2.year,date2.month,date2.day,first_day)<<' '<<day_num(date1.year,date1.month,date1.day-1,first_day)<<'\n';
	int day=day_num(date2.year,date2.month,date2.day,first_day)-day_num(date1.year,date1.month,date1.day-1,first_day);
	return(day);
}

int first_year(Date date1){
	int first_day=fdps(date1.year);
	int day=day_num(date1.year,12,31,first_day)-day_num(date1.year,date1.month,date1.day-1,first_day);
	return(day);
}

int amid_year(Date date1,Date date2){
	int first_day,day=0;
	for(int i=date1.year+1;i<date2.year;++i){
		first_day=fdps(i);
		day+=day_num(i,12,31,first_day);
	}
	return(day);
}

int last_year(Date date2){
	int first_day=fdps(date2.year);
	int day=day_num(date2.year,date2.month,date2.day,first_day);
	return(day);
}


main(){
	int n,result=0;
	cin>>n;
	char day[30]={'\0'};
	Date date1,date2;
	for(int i=0;i<n;++i){
		result=0;
		cin>>day;
		date1.year=(day[0]-'0')*1000+(day[1]-'0')*100+(day[2]-'0')*10+(day[3]-'0');
		date1.month=(day[5]-'0')*10+(day[6]-'0');
		date1.day=(day[8]-'0')*10+(day[9]-'0');
		cin>>day;
		date2.year=(day[0]-'0')*1000+(day[1]-'0')*100+(day[2]-'0')*10+(day[3]-'0');
		date2.month=(day[5]-'0')*10+(day[6]-'0');
		date2.day=(day[8]-'0')*10+(day[9]-'0');
		if(date1.year==date2.year)
			result=same_year(date1,date2);
		else{
			result+=first_year(date1);
			result+=amid_year(date1,date2);
			result+=last_year(date2);
		}
		cout<<result<<'\n';
	}
}
