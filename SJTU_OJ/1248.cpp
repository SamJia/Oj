#include <iostream>
using namespace std;
int main(){
	int n,state=1;
	cin>>n;
	char square1[n][n],square2[n][n];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>square1[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>square2[i][j];
//*****************************************
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(square1[i][j]!=square2[j][n-1-i])
				state=0;
	if(state){
		cout<<1;
		return(0);
	}
//*****************************************
	state=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(square1[i][j]!=square2[n-1-i][n-1-j])
				state=0;
	if(state){
		cout<<2;
		return(0);
	}
//*****************************************
	state=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(square1[i][j]!=square2[n-1-j][i])
				state=0;
	if(state){
		cout<<3;
		return(0);
	}
//*****************************************
	state=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(square1[i][j]!=square2[i][n-1-j])
				state=0;
	if(state){
		cout<<4;
		return(0);
	}
//*****************************************
    int s1=1,s2=1,s3=1;
	state=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			if(square1[i][j]!=square2[j][i])
				s1=0;
            if(square1[i][j]!=square2[n-1-i][j])
				s2=0;
            if(square1[i][j]!=square2[n-1-j][n-1-i])
				s3=0;
        }
	if(s1||s2||s3){
		cout<<5;
		return(0);
	}
//*****************************************
	state=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(square1[i][j]!=square2[i][j])
				state=0;
	if(state){
		cout<<6;
		return(0);
	}
//*****************************************
	cout<<7;
	return(0);
}
