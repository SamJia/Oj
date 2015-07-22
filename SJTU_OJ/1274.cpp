
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
#define SIZE 220
using namespace std;

// pair<char[SIZE], int>saved_data[SIZE] = {};
char *num2_prod[10];

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

template <typename T>
int len(T num[]){
    int i;
	for(i=0;num[i];++i);
	return(i);
}

bool cmp_char_num(char num1[],char num2[],int inv=0){
	if(inv){
		inverse_num(num1);
		inverse_num(num2);
	}
	int state=0;
	if(len(num1)>len(num2))
		state=1;
	else if(len(num2)>len(num1))
		state=2;
	for(int i=0;!state;++i)
		if(num1[i]>num2[i]||!num2[i])
			state=1;
		else if(num1[i]<num2[i])
			state=2;
	if(inv){
		inverse_num(num1);
		inverse_num(num2);
	}
	if(state==1)
		return(1);
	return(0);
}

char *plus_high(char num1[],char num2[],int inv=0){
	char *result;
	result=new char[SIZE];
	result[0]='0';
	result[1]='\0';
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

void self_plus_high(char result[],char num2[],int inv=0){
	char *tmp_result=plus_high(result,num2,inv);
	strcpy(result,tmp_result);
	delete(tmp_result);
}

char *prod_one(char num[],int one_num,int inv=0){
	if(!inv)
		inverse_num(num);
	char *result;
	result=new char[SIZE];
	result[0]='0';
	result[1]='\0';
	int i=0,k=0,sol,state=0;
	for(i=0;num[i];){
		sol=(num[i++]-'0')*one_num+state;
		result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		result[k++]=state+'0';
    for(;k>1&&result[k-1]=='0';--k);
	result[k]='\0';
	if(!inv){
		inverse_num(num);
		inverse_num(result);
	}
	return(result);
}

char *prod_high(char num1[],char num2[],int inv=0){
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	int i=0;
	char *result;
	result=new char[SIZE];
	result[0]='0';
	result[1]='\0';
	for(i=0;i<10;++i)
		num2_prod[i]=prod_one(num2,i,1);
	for(i=0;num1[i];++i)
		self_plus_high(result+i,num2_prod[num1[i]-'0'],1);
    int length=len(result);
    for(i=length;i>1&&result[i-1]=='0';--i);
    result[i]='\0';
	// if(!inv){
	// inverse_num(num1);
	// inverse_num(num2);
	// inverse_num(result);
	// }
	return(result);
}

void Delete0(char *num){
	inverse_num(num);
	int length = len(num), i;
	for(i = length; i > 1 && num[i - 1] == '0'; --i);
	num[i] = '\0';
	inverse_num(num);
}

void Output(char *number, int length, int pos){
	// cout << pos;
	char output_char[SIZE];
	for(int i = 0; i < length; ++i)
		output_char[i] = ' ';
	output_char[length] = '\0';
	for(int i = 0; number[i]; ++i)
		output_char[length - pos - i - 1] = number[i];
	// cout << number;
	cout << output_char << '\n';
}

void Output_(int length){
	for(int i = 0; i < length; ++i)
		cout << '-';
	cout << '\n';
}

main(){
	char num1[SIZE]={'\0'},num2[SIZE]={'\0'},*num;
	cin.getline(num1,SIZE);
	cin.getline(num2,SIZE);
	Delete0(num1);
	Delete0(num2);
	char *result = prod_high(num2,num1);
	int length = len(result), len2 = len(num2), len2_not0 = 0;
	// cout << len2;
	Output(num1, length, 0);
	Output(num2, length, 0);
	for(int i = 0; i < len2; ++i)
		if(num2[i] != '0')
			++len2_not0;
	if(len2_not0 > 1){
		Output_(length);
		for(int i = 0; i < len2; ++i)
			if(num2[i] - '0')
				Output(num2_prod[num2[i] - '0'], length, i);
	}
	Output_(length);
	Output(result, length, 0);
}