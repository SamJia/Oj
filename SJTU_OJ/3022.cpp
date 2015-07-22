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
#define SIZE 11000
using namespace std;
char char1[SIZE] = {'1', '\0'}, char2[SIZE] = {'1', '\0'}, char3[SIZE] = {'0', '\0'};
char *day0 = char1, *day1 = char2, *day2 = char3, *amid;

void inverse_num(char num[]){
	int i=0,amid;
	for(i=0;num[i];++i);
	--i;
	for(int j=0;j<i;++j,--i){
		amid=num[i];
		num[i]=num[j];
		num[j]=amid;
	}
}

char *plus_high(char num1[],char num2[]){
	char *result;
	result=new char[SIZE];
	result[0]='0';
	result[1]='\0';
	int i=0,j=0,k=0,sol,state=0;
	for(;num1[i]||num2[j];){
		if(!num1[i])
			sol=num2[j++]-'0'+state;
		else if(!num2[j])
			sol=num1[i++]-'0'+state;
		else
			sol=num1[i++]-'0'+num2[j++]-'0'+state;
		result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		result[k++]=state+'0';
	result[k]='\0';
	return(result);
}

void self_plus_high(char result[],char num2[]){
	char *tmp_result=plus_high(result,num2);
	strcpy(result,tmp_result);
	delete(tmp_result);
}

void Exchange(){
	amid = day2;
	day2 = day1;
	day1 = day0;
	day0 = amid;
}

main(){
	int day_number;
	cin >> day_number;
	for(int i = 0; i < day_number; ++i){
		Exchange();
		self_plus_high(day0, day1);
		self_plus_high(day0, day2);
	}
	inverse_num(day0);
	cout << day0;
}