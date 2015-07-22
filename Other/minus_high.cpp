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
#define SIZE 100010
using namespace std;

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

char *minus_high(char num1[],char num2[],int inv=0){
	static char result[SIZE]={'\0'};
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	int i=0,j=0,k=0,sol,state=0;
	for(;num1[i]||num2[j];){
		if(!num2[j])
			sol=num1[i++]-'0'+state;
		else
			sol=num1[i++]-num2[j++]+state;
		result[k++]=(sol<0?(sol+10):sol)+'0';
		state=sol<0?-1:0;
	}
	for(;k>0&&result[k-1]=='0';--k);
	result[k]='\0';
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	inverse_num(result);
	}
	return(result);
}

void self_minus_high(char result[],char num2[],int inv=0){
    if(!inv){
	inverse_num(result);
	inverse_num(num2);
	}
	static char tmp_result[SIZE]={'\0'};
	int i=0,j=0,k=0,sol,state=0;
	for(;result[i]||num2[j];){
		if(!num2[j])
			sol=result[i++]-'0'+state;
		else
			sol=result[i++]-num2[j++]+state;
		tmp_result[k++]=(sol<0?(sol+10):sol)+'0';
//        cout<<'0'+(sol<0?(sol+10):sol)<<'\n';
		state=sol<0?-1:0;
	}
	for(;k>0&&tmp_result[k-1]=='0';--k);
	tmp_result[k]='\0';
	if(!inv){
	inverse_num(result);
	inverse_num(num2);
	inverse_num(tmp_result);
	}
	strcpy(result,tmp_result);
}

main(){
	char num1[SIZE]={'\0'},num2[SIZE]={'\0'},*num;
	cin.getline(num1,SIZE);
	cin.getline(num2,SIZE);
	self_minus_high(num1,num2);
	cout<<num1;
	if(num1[0]=='\0')
        cout<<0;
}
