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

char *plus_high(char num1[],char num2[],int inv=0){
	static char result[SIZE]={'\0'};
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	}
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
	num=plus_high(num1,num2,2);
	cout<<num;
}
