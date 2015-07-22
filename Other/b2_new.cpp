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
#define SIZE 200
using namespace std;

struct Divide{
	char *quo,*rem;
};

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

void move(char num[],int n){
	int i=0;
	for(;num[i];++i);
	if(n>0)
		for(int j=0;j<n;++j)
			num[i++]='0';
	else
		i-=n;
	num[i]='\n';
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

char *minus_high(char num1[],char num2[],int inv=0){
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
		if(!num2[j])
			sol=num1[i++]-'0'+state;
		else
			sol=num1[i++]-num2[j++]+state;
		result[k++]=(sol<0?(sol+10):sol)+'0';
		state=sol<0?-1:0;
	}
	for(;k>1&&result[k-1]=='0';--k);
	result[k]='\0';
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	inverse_num(result);
	}
	return(result);
}

void self_minus_high(char result[],char num2[],int inv=0){
    char *tmp_result=minus_high(result,num2,inv);
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

void self_prod_one(char result[],int one_num,int inv=0){
	char *tmp_result=prod_one(result,one_num,inv);
	strcpy(result,tmp_result);
	delete(tmp_result);
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
	char *(num2_prod[10]);
	for(i=0;i<10;++i)
		num2_prod[i]=prod_one(num2,i,1);
	for(i=0;num1[i];++i)
		self_plus_high(result+i,num2_prod[num1[i]-'0'],1);
    int length=len(result);
    for(i=length;i>1&&result[i-1]=='0';--i);
    result[i]='\0';
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	inverse_num(result);
	}
	return(result);
}

void self_prod_high(char result[],char num2[],int inv=0){
	char *tmp_result=prod_high(result,num2,inv);
	strcpy(result,tmp_result);
	delete(tmp_result);
}

char *pow_high(char num[],int n=2){
	char *result=new char [SIZE];
	strcpy(result,num);
	for(int i=1;i<n;++i)
		self_prod_one(result,n);
	return(result);
}

void self_pow_high(char result[],int n=2){
	char *tmp_result=pow_high(result,n);
	strcpy(result,tmp_result);
	delete(tmp_result);
}

Divide *divide_high(char num1[],char num2[],int inv=0){
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	int i=0,j=0,state=0,sol,next_pos,len1=len(num1),len2=len(num2),lenr;
	Divide *result=new Divide;
	result->quo=new char[SIZE];
	result->rem=new char[SIZE];
	result->quo[0]='0';
	result->quo[1]='\0';
	strncpy(result->rem,num1,len2-1);
	result->rem[len2-1]='\0';
	char *(num2_prod[10]);
	for(i=1;i<10;++i)
		num2_prod[i]=prod_one(num2,i);
	for(i=0;len1-i>=len2;++i){
        if(result->rem[0]=='0')
            ++(result->rem);
	    lenr=len(result->rem);
		result->rem[lenr+1]='\0';
		result->rem[lenr]=num1[i+len2-1];
		for(j=9;j>0&&!cmp_char_num(result->rem,num2_prod[j]);--j);
		result->quo[i]=j+'0';
		if(j)
			self_minus_high(result->rem,num2_prod[j]);
	}
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	result->quo[i>0?i:1]='\0';
	for(;result->quo[1]&&result->quo[0]=='0';++(result->quo));
    return(result);
}

void self_divide_high(char result[],char num2[],int inv=0){
	Divide *tmp_result=divide_high(result,num2,inv);
	strcpy(result,tmp_result->quo);
	delete(tmp_result);
}

void self_mod_high(char result[],char num2[],int inv=0){
	Divide *tmp_result=divide_high(result,num2,inv);
	strcpy(result,tmp_result->rem);
	delete(tmp_result);
}

char *calculate(char n[]){
	char *(n_n[10]),max[SIZE]={'1','0','0','0','0','0','0','0','0','7'},num_8[SIZE]={'8'};
	n_n[1]=new char [SIZE];
	strcpy(n_n[1],n);
	for(int i=2;i<7;++i)
		n_n[i]=prod_high(n_n[i-1],n);
	self_prod_one(n_n[3],5);
	self_prod_one(n_n[2],4);
	self_plus_high(n_n[6],n_n[3]);
	self_plus_high(n_n[6],n_n[2]);
	self_minus_high(n_n[6],n_n[5]);
	self_minus_high(n_n[6],n_n[4]);
	self_divide_high(n_n[6],num_8);
	self_mod_high(n_n[6],max);
	for(int i=1;i<6;++i)
		delete(n_n[i]);
	return(n_n[6]);
}

int small_cal(int num){
    return(((num*num*(((((num-1)*num-1))*num+5)*num+4))/8)%1000000007);
}

main(){
	int t,i;;
	char n[SIZE]={'\0'};
    scanf("%d",&t);
	getchar();
	char *result;
	for(i=0;i<t;++i){
        // scanf("%d",&n);
		// cout<<result[0]-'0';
		cin.getline(n,SIZE);
		result=calculate(n);
		cout<<"case "<<i+1<<": "<<result<<'\n';
		delete(result);
        // printf("case %d: %d",i+1,small_cal(n));
	}
}
