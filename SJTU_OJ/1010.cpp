#include <iostream>
using namespace std;
int main(){
	int money[13],money_my=0,money_mom=0;
	for(int i=1;i<=12;++i)
		cin>>money[i];
	for(int i=1;i<=12;++i){
		if((money_my+300-money[i])<0){
			cout<<-i;
			return 0;
		}
		money_mom+=(money_my+300-money[i])/100*100;
		money_my=(money_my+300-money[i])%100;
	}
	cout<<(money_mom*6/5+money_my);
	return 0;
}