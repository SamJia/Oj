#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Player{
public:
	int number_, years_, chosed_, role_;
	char name_[22];
};

Player players[22];
char used_in_transform[] = {"\0GDMS"};

void Input();
int Transform(char role);
bool GetRoll();
inline bool cmp(const Player & p1, const Player &p2);
inline bool cmp2(const Player & p1, const Player &p2);
void Output();


main(){
	Input();
	if(GetRoll())
		Output();
	else
		cout << "IMPOSSIBLE TO ARRANGE";
}

void Input(){
	char tmp_char;
	int min_year, max_year;
	for(int i = 0; i < 22; ++i){
		cin >> players[i].number_ >> players[i].name_ >> tmp_char;
		players[i].role_ = Transform(tmp_char);
		players[i].chosed_ = 1;
		do{
			cin >> min_year >> tmp_char >> max_year;
			tmp_char = getchar();
			players[i].years_ +=(max_year - min_year + 1);
		}while(tmp_char == ' ');
	}
}

int Transform(char role){
	for(int i = 1; i < 5; ++i)
		if(used_in_transform[i] == role)
			return i;
}

bool GetRoll(){
	sort(players, players + 22, cmp);
	int i, j, number;
	if(players[0].role_ != 1)
		return 0;
	players[0].chosed_ = 0;
	for(i = 2, j = 1; i < 5;getchar(), ++i){
		cin >> number;
		for(; players[j].role_ < i; ++j);
		for(; number > 0; --number){
			if(players[j].role_ != i)
				return 0;
			players[j++].chosed_ = 0;
		}
	}
	sort(players, players + 22, cmp);
	sort(players, players + 11, cmp2);
	sort(players + 1, players + 11, cmp);
	return 1;
}

inline bool cmp(const Player & p1,const Player &p2){
	if(p1.chosed_ == p2.chosed_)
		if(p1.role_ == p2.role_)
			return p1.number_ < p2.number_;
		else
			return p1.role_ < p2.role_;
	else
		return p1.chosed_ < p2.chosed_;
}

inline bool cmp2(const Player & p1, const Player &p2){
	if(p1.years_ == p2.years_)
		return p1.number_ > p2.number_;
	return p1.years_ > p2.years_;
}

void Output(){
	for(int i = 0; i < 11; ++i)
		cout << players[i].number_ << ' ' << players[i].name_ << ' ' << used_in_transform[players[i].role_] <<'\n';
}