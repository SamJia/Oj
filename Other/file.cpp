/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/





#include <iostream>
#include <fstream>
using namespace std;

int search(char line_of_file[],char teststr[],int position[],int len){
	static int i=0,line=0,k=0;
	int count=0;
	++line;
	for(int j=0;j<300&&line_of_file[j]!='\0';++j){
		if(line_of_file[j]==teststr[i]){
			if(i==len-1){
				++count;
				position[k]=line;
				position[k+1]=j+1-i;
				k+=2;
				i=0;
			}
			else
				++i;
		}
		else
			i=0;
	}
	return count;
}
main(){
	int i;
	char filename[20]={'\0'},teststr[100]={'\0'};
	cout<<"please input the infile name"<<endl;
	for(i=0;(filename[i]=cin.get())!='\n';++i);
	filename[i]='\0';
	cout<<"please input the test string"<<endl;
	for(i=0;(teststr[i]=cin.get())!='\n';++i);
	fstream fin(filename,ios::in);
	if (!fin)
		cout<<"file open errer!";
	else{
		int len=i,count=0,position[200]={0};
		char line_of_file[300]={'\0'};
		while(fin.getline(line_of_file,300,'\n')!=NULL)
			count+=search(line_of_file,teststr,position,len);
		cout<<"the occur time is "<<count<<endl;
		for(i=0;position[i]!=0;i+=2)
			cout<<"line "<<position[i]<<" column "<<position[i+1]<<endl;
	}
	fin.close();
}
