#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;
struct Ans{
	int id1, id2, form;
} ans[20];
string name[10],word;
int m, n, p, i, id_1, id_2, ans_num = 0;

ifstream fin("1255.txt");

void input(){
	fin >> m >> n >> p;
	for(i = 0; i < m; ++i)
		fin >> name[i];
	for(i = 0; i < p; ++i)
		ans[i].id1 = ans[i].id2 = ans[i].form = 0;
}

int check_name(int state = 0){
	for(i = 0; i < m; ++i)
		if(word == name[i] + (state > 0 ? "" : ":"))
			return(i);
	return(m);
}

void save_ans(int state){
	ans[ans_num].id1 = id_1;
	ans[ans_num].id2 = id_2;
	ans[ans_num++].form = state;
}

void check_I_have(){
	static string have = " have the ring.", have_not = " have not the ring.";
	getline(fin,word);
	if(word == have)
		save_ans(1);
	else if(word == have_not)
		save_ans(2);
}

void check_today(){
	static string week[7]={"Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
	getline(fin,word);
	if(word.substr(0, 4) == " is ")
		for (i = 0, word = word.substr(4, word.length()); i < 7; id_2 = ++i + 1)
			if(word == week[i])
				save_ans(3);
}

void check_other(){
	static string has = " has the ring.", has_not = " has not the ring.";
	id_2 = check_name(1);
	getline(fin,word);
	if(id_2 < m){
		if(word == has)
			save_ans(1);
		else if(word == has_not)
			save_ans(2);
	}
}

void check(){
	fin >> word;
	id_2 = id_1 = check_name();
	fin >> word;
	if(word=="I")
		check_I_have();
	else if(word=="Today")
		check_today();
	else
		check_other();
}

void output(){
	if(!ans_num)
		cout << "Orz\n";
	for(i = 0; i < ans_num; ++i)
		printf("%d %d %d\n", ans[i].id1, ans[i].id2, ans[i].form);
}

main(){
	input();
	for(int j = 0; j < p; ++j)
		check();
	output();
}