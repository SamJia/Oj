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
	tmp_result[0]='\0';
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

char *minus_high(char num1[],char num2[],int inv=0){
	char *result;
	result=new char[SIZE];
	tmp_result[0]='\0';
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
	char tmp_result[SIZE]={'\0'};
	int i=0,j=0,k=0,sol,state=0;
	for(;result[i]||num2[j];){
		if(!num2[j])
			sol=result[i++]-'0'+state;
		else
			sol=result[i++]-num2[j++]+state;
		tmp_result[k++]=(sol<0?(sol+10):sol)+'0';
		state=sol<0?-1:0;
	}
	for(;k>0&&tmp_result[k-1]=='0';--k);
	tmp_result[k]='\0';
	if(!inv){
	inverse_num(num2);
	inverse_num(tmp_result);
	}
	strcpy(result,tmp_result);
}

char *prod_one(char num[],int one_num,int inv=0){
	if(!inv)
		inverse_num(num);
	char *result;
	result=new char[SIZE];
	tmp_result[0]='\0';
	int i=0,k=0,sol,state=0;
	for(i=0;num[i];){
		sol=(num[i++]-'0')*one_num;
		result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		result[k++]=state+'0';
	result[k]='\0';
	if(!inv){
		inverse_num(num);
		inverse_num(result);
	}
	return(result);
}

void self_prod_one(char result[],int one_num,int inv=0){
	if(!inv)
		inverse_num(result);
	char tmp_result[SIZE]={'\0'};
	int i=0,k=0,sol,state=0;
	for(i=0;result[i];){
		sol=(result[i++]-'0')*one_num;
		tmp_result[k++]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		tmp_result[k++]=state+'0';
	tmp_result[k]='\0';
	if(!inv)
		inverse_num(tmp_result);
	strcpy(result,tmp_result);
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
		self_plus_high(result+i,num2_prod[num1[i]-'0'],1);
	}
	if(!inv){
	inverse_num(num1);
	inverse_num(num2);
	inverse_num(result);
	}
	return(result);
}

void self_prod_high(char result[],char num2[],int inv=0){
	if(!inv){
	inverse_num(result);
	inverse_num(num2);
	}
	char tmp_result[SIZE]={'\0'};
	tmp_result[0]='\0';
	char *(num2_prod[10]);
	for(int i=1;i<10;++i)
		num2_prod[i]=prod_one(num2,i);
	for(int i=0;result[i];++i){
		if(result[i]=='0')
			continue;
		self_plus_high(tmp_result+i,num2_prod[result[i]-'0'],1);
	}
	if(!inv){
	inverse_num(num2);
	inverse_num(tmp_result);
	}
	strcpy(result,tmp_result);
}

char *over_high(char num1[],char num2[],int inv=0){
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	int i=0,j=0,state=0,sol;
	char *result;
	result=new char[SIZE];
	result[0]='\0';
	char *(num2_prod[10]);
	int len1=len(num1),len2=len(num2);
	for(i=1;i<10;++i){
		num2_prod[i]=prod_one(num2,i);
		if(len(num2_prod[i])>len2){
			num2_prod[i][1]+=(num2_prod[i][0]-'0')*10;
			++num2_prod[i];
		}
	}
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	for(i=0;len1-i>=len2;++i){
		for(j=9;j>0&&!cmp_char_num(num1+i,num2_prod[j]);--j);
		result[i]=j+'0';
		if(j)
            for(int k=len2+i-1;k>=i;--k){
                sol=num1[k]-num2_prod[j][k-i]+state;
                num1[k]=(sol<0?(sol+10):sol)+'0';
				state=sol<0?-1:0;
            }
		num1[i+1]=num1[i+1]+(num1[i]-'0')*10;
        num1[i]='0';
	}
	result[i]='\0';
	for(i=0;result[i];++i)
		if(result[i]!='0')
			return(result+i);
}

void self_over_high(char result[],char num2[],int inv=0){
	if(inv){
	inverse_num(result);
	inverse_num(num2);
	}
	int i=0,j=0,state=0,sol;
	char tmp_result[SIZE]={'\0'};
	tmp_result[0]='\0';
	char *(num2_prod[10]);
	int len1=len(result),len2=len(num2);
	for(i=1;i<10;++i){
		num2_prod[i]=prod_one(num2,i);
		if(len(num2_prod[i])>len2){
			num2_prod[i][1]+=(num2_prod[i][0]-'0')*10;
			++num2_prod[i];
		}
	}
	if(inv){
	inverse_num(result);
	inverse_num(num2);
	}
	for(i=0;len1-i>=len2;++i){
		for(j=9;j>0&&!cmp_char_num(result+i,num2_prod[j]);--j);
		tmp_result[i]=j+'0';
		if(j)
            for(int k=len2+i-1;k>=i;--k){
                sol=result[k]-num2_prod[j][k-i]+state;
                result[k]=(sol<0?(sol+10):sol)+'0';
				state=sol<0?-1:0;
            }
		result[i+1]=result[i+1]+(result[i]-'0')*10;
        result[i]='0';
	}
	tmp_result[i]='\0';
	for(i=0;tmp_result[i];++i)
		if(tmp_result[i]!='0')
			strcpy(result,tmp_result+i);
}

char *mod_high(char num1[],char num2[],int inv=0){
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	int i=0,j=0,state=0,sol;
	char *result;
	result=new char[SIZE];
	result[0]='\0';
	char *(num2_prod[10]);
	int len1=len(num1),len2=len(num2);
	for(i=1;i<10;++i){
		num2_prod[i]=prod_one(num2,i);
		if(len(num2_prod[i])>len2){
			num2_prod[i][1]+=(num2_prod[i][0]-'0')*10;
			++num2_prod[i];
		}
	}
	if(inv){
	inverse_num(num1);
	inverse_num(num2);
	}
	for(i=0;len1-i>=len2;++i){
		for(j=9;j>0&&!cmp_char_num(num1+i,num2_prod[j]);--j);
		result[i]=j+'0';
		if(j)
            for(int k=len2+i-1;k>=i;--k){
                sol=num1[k]-num2_prod[j][k-i]+state;
                num1[k]=(sol<0?(sol+10):sol)+'0';
				state=sol<0?-1:0;
            }
		num1[i+1]=num1[i+1]+(num1[i]-'0')*10;
        num1[i]='0';
	}
	result[i]='\0';
	for(i=0;num1[i];++i)
		if(num1[i]!='0')
			return(num1+i);
}

void self_mod_high(char result[],char num2[],int inv=0){
	if(inv){
	inverse_num(result);
	inverse_num(num2);
	}
	int i=0,j=0,state=0,sol;
	char tmp_result[SIZE]={'\0'};
	tmp_result[0]='\0';
	char *(num2_prod[10]);
	int len1=len(result),len2=len(num2);
	for(i=1;i<10;++i){
		num2_prod[i]=prod_one(num2,i);
		if(len(num2_prod[i])>len2){
			num2_prod[i][1]+=(num2_prod[i][0]-'0')*10;
			++num2_prod[i];
		}
	}
	if(inv){
	inverse_num(result);
	inverse_num(num2);
	}
	for(i=0;len1-i>=len2;++i){
		for(j=9;j>0&&!cmp_char_num(result+i,num2_prod[j]);--j);
		tmp_result[i]=j+'0';
		if(j)
            for(int k=len2+i-1;k>=i;--k){
                sol=result[k]-num2_prod[j][k-i]+state;
                result[k]=(sol<0?(sol+10):sol)+'0';
				state=sol<0?-1:0;
            }
		result[i+1]=result[i+1]+(result[i]-'0')*10;
        result[i]='0';
	}
	tmp_result[i]='\0';
	for(i=0;result[i];++i)
		if(result[i]!='0')
			strcpy(result,result+i);
}

main(){
	char num1[SIZE]={'\0'},num2[SIZE]={'\0'},*num;
	cin.getline(num1,SIZE);
	cin.getline(num2,SIZE);
	num=plus_high(num1,num2);
	cout<<num;
	if(num[0]=='\0')
        cout<<0;
}
