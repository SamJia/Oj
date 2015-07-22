#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 21000
#define number first
#define price second
int by_number[SIZE], stock_number, command_number, number_to_modify, price_to_modify;
pair<int, int> by_ranking[SIZE];

void Input();
void RunCommands();
void Modify();
void Quest();
void Copy();
inline bool Cmp(const pair<int, int> & stock1, const pair<int, int> & stock2);

main(){
	Input();
	RunCommands();
}

void Input(){
	cin >> stock_number;
	for(int i = 0; i < stock_number; ++i)
		cin >> by_number[i];
	cin >> command_number;
}

void RunCommands(){
	char command;
	for(int i = 0; i < command_number; ++i){
		cin >>command;
		if(command == 'M')
			Modify();
		else
			Quest();
	}
}

void Modify(){
	cin >> number_to_modify>> price_to_modify;
	by_number[number_to_modify - 1] = price_to_modify;
}

void Quest(){
	Copy();
	sort(by_ranking, by_ranking + stock_number, Cmp);
	int request_number, number_to_cout;
	cin >> request_number;
	for(int i = 0; i < request_number; ++i){
		cin >> number_to_cout;
		cout << by_ranking[number_to_cout - 1].number + 1 << ' ';
	}
	cout << '\n';
}

void Copy(){
	for(int i = 0; i < stock_number; ++i){
		by_ranking[i].number = i;
		by_ranking[i].price = by_number[i];
	}
}

inline bool Cmp(const pair<int, int> & stock1, const pair<int, int> & stock2){
	if(stock1.price == stock2.price)
		return (stock1.number < stock2.number);
	return (stock1.price > stock2.price);
}