/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/


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
struct student{
	char name[30],number[30];
	double avg_score;
	student *next;
};

void sort_student(student *head){
	double amid_avg;
	char amid_name[30],amid_num[30];
	student *max;
	for(;head->next!=NULL;head=head->next){
		max=head;
        //cout<<1<<'\n';
		for(student *i=head->next;i!=NULL;max=max->avg_score>i->avg_score?max:i,i=i->next);
		amid_avg=head->avg_score;
		head->avg_score=max->avg_score;
		max->avg_score=amid_avg;
		strcpy(amid_name,head->name);
		strcpy(head->name,max->name);
		strcpy(max->name,amid_name);
		strcpy(amid_num,head->number);
		strcpy(head->number,max->number);
		strcpy(max->number,amid_num);
	}
}

int main(){
	char infilename[20]={'\0'},outfilename[20]={'\0'},date[100]={'\0'};
	student *head=new student,*p=head,*q=head;
	head->name[0]='\0';
	head->avg_score=0;
	int i=0,state=0,j=0,score=0;
	cout<<"please input the infilename."<<'\n';
	cin>>infilename;
	cout<<"please input the outfilename."<<'\n';
	cin>>outfilename;
	ifstream fin(infilename);
	ofstream fout(outfilename);
	if(!fin){
		cout<<"file \""<<infilename<<"\" open error.";
		return(0);
	}
	while(fin.getline(date,100)){
		for(i=0;i<100&&date[i+1]!='\0';++i);
		for(;date[i]==' '&&i>=0;--i);
		if(i<=0)
            continue;
		for(j=0;j<8;--i){
			if(date[i]!=' ')
				state=1;
			if(!state&&score){
				p->avg_score+=score;
				score=0;
				++j;
			}
			if(state)
				score=score*10+date[i]-'0';
			state=0;
		}
		date[i+1]='\0';
		for(;i>=0;--i){
			if(date[i]!=' ')
				state=1;
			if(state&&date[i]==' ')
				break;
		}
		strcpy(p->number,date+i+1);
		date[i]='\0';
		strcpy(p->name,date);
		p->avg_score/=8;
		q=p;
		p=new student;
		p->name[0]='\0';
		p->avg_score=0;
		p->next=NULL;
		q->next=p;
	}
	if(p->name[0]=='\0')
		q->next=NULL;
	fout.setf(ios::left);
	fout<<setw(30)<<"name"<<setw(30)<<"student number"<<"average score"<<'\n';
	fout<<"------------------------------------------------------------------------------"<<'\n';
	if(head->name[0]=='\0'){
		fout<<'\0';
		return(0);
	}
	sort_student(head);
	for(;head!=NULL;head=head->next)
		fout<<setw(30)<<head->name<<setw(30)<<head->number<<fixed<<setprecision(2)<<head->avg_score<<'\n';
	fin.close();
	fout.close();
	return(0);
}
