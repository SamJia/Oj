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
using namespace std;
#define SIZE 1000

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

void self_plus_high(char result[],char num2[],int inv=0){
	char tmp_result[SIZE]={'\0'};
	if(!inv){
		inverse_num(result);
		inverse_num(num2);
	}
	int i=0,j=0,k=0,sol,state=0;
	for(;result[i]||num2[j];){
		if(!result[i])
			sol=num2[j++]-'0'+state;
		else if(!num2[j])
			sol=result[i++]-'0'+state;
		else
			sol=result[i++]-'0'+num2[j++]-'0'+state;
		tmp_result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		tmp_result[k++]=state+'0';
	tmp_result[k]='\0';
	if(!inv){
		inverse_num(num2);
		inverse_num(tmp_result);
	}
	strcpy(result,tmp_result);
}

char *prod_one(char num[],int one_num,int inv=0,int inv=0){
	char *result;
	result=new char[SIZE];
	if(!inv)
		inverse_num(num);
	int i=0,k=0,sol,state=0;
	for(i=0;num[i];){
		sol=(num[i++]-'0')*one_num;
		result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		result[k++]=state+'0';
	result[k]='\0';
	if(!inv)
		inverse_num(num);
	return(result);
}

char *prod_high(char num1[],char num2[],int inv=0){
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	char *result;
	result=new char[SIZE];
	result[0]='\0';
	char *(num2_prod[10]);
	for(int i=1;i<10;++i)
		num2_prod[i]=prod_one(num2,i);
	for(int i=0;num1[i];++i){
		if(num1[i]=='0')
			continue;
		self_plus_high(result+i,num2_prod[num1[i]-'0']);
	}
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	inverse_num(result);
	}
	return(result);
}

main(){
	char num1[SIZE]={'\0'},num2[SIZE]={'\0'},*num;
	cin.getline(num1,SIZE);
	cin.getline(num2,SIZE);
	num=prod_high(num1,num2);
	cout<<num;
	if(num[0]=='\0')
        cout<<0;
}
