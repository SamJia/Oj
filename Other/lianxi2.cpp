#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int create_ques(){
	int num1,num2,fuhao,sol;
	fuhao=rand()%2;
	while (1){
		num1=1+rand()%100;
		num2=1+rand()%100;
		switch (fuhao){
			case 0:if((sol=num1+num2)<=100){cout<<num1<<'+'<<num2<<'=';return(sol);}
				else break;
			case 1:if ((sol=num1-num2)>=0) {cout<<num1<<'-'<<num2<<'=';return(sol);}
				else break;
			/*case 2:if ((sol=num1*num2)<=100){cout<<num1<<'*'<<num2<<'=';return(sol);}
				else break;
			case 3:if ((sol=num1*num2)<=100){cout<<sol<<'/'<<num1<<'=';return(num2);}
				else break;*/
		}
	}
}
void answer(int sol){
	int ans,out;
	while (1){
		cin>>ans;
		if (ans==sol){
			out=rand()%3;
			switch (out){
				case 0:cout<<"you are right!"<<endl;break;
				case 1:cout<<"good"<<endl;break;
				case 2:cout<<"it's ok"<<endl;break;
			}
			break;
		}
		else{
			out=rand()%3;
			switch (out){
				case 0:cout<<"you are wrong!"<<endl;break;
				case 1:cout<<"no"<<endl;break;
				case 2:cout<<"sorry"<<endl;break;
			}
		}
	}

}

main(){
    srand(time(0));
	while (1){
		int sol=create_ques();
		answer(sol);
	}
}
