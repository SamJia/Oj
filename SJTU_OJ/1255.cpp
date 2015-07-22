#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;
struct Ans{
	int id1, id2, format;
} ans[20];
string name[10],word;
int number_of_hobbit, number_of_lier, number_of_respond, i, talker_id, refered_id, number_of_answer = 0, pos_of_colon = 0, pos_of_space = 0;
char colon = ':', space = ' ';

// ifstream cin("1255.txt");

void Input(){
	cin >> number_of_hobbit >> number_of_lier >> number_of_respond;
	getline(cin, word);
	for(i = 0; i < number_of_hobbit; ++i)
		getline(cin, name[i]);
	for(i = 0; i < number_of_respond; ++i)
		ans[i].id1 = ans[i].id2 = ans[i].format = 0;
}

void SaveAnswer(int type){
	ans[number_of_answer].id1 = talker_id;
	ans[number_of_answer].id2 = refered_id;
	ans[number_of_answer++].format = type;
}

int CheckName(string letter_to_check){
	for(i = 0; i < number_of_hobbit; ++i)
		if(letter_to_check == name[i])
			return(i);
	return(number_of_hobbit);
}

void CheckTalker(){
	pos_of_colon = word.find(colon);
	talker_id = CheckName(word.substr(0, pos_of_colon));
	word = word.substr(pos_of_colon + 2, word.length() - pos_of_colon - 2);
}

void CheckFirstType(){
	static string have = "I have the ring.", have_not = "I have not the ring.";
	refered_id = talker_id;
	if(word == have)
		SaveAnswer(1);
	else if(word == have_not)
		SaveAnswer(2);
}

void CheckSecondType(){
	static string week[7]={"Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.","Today is Sunday."};
	for (i = 0, refered_id = 1; i < 7; ++refered_id, ++i)
		if(word == week[i])
			SaveAnswer(3);
}

bool FirstIsName(){
	pos_of_space = word.find(space);
	refered_id = CheckName(word.substr(0, pos_of_space));
	if(refered_id < number_of_hobbit){
		word = word.substr(pos_of_space + 1, word.length() - pos_of_space - 1);
		return(1);
	}
	return(0);
}

void CheckThirdType(){
	static string has = "has the ring.", has_not = "has not the ring.";
	if(FirstIsName()){
		if(word == has)
			SaveAnswer(1);
		else if(word == has_not)
			SaveAnswer(2);
	}
}

void CheckWords(){
	CheckFirstType();
	CheckSecondType();
	CheckThirdType();
}

void Output(){
	if(!number_of_answer)
		cout << "Orz\n";
	for(i = 0; i < number_of_answer; ++i)
		printf("%d %d %d\n", ans[i].id1, ans[i].id2, ans[i].format);
}

void Check(){
	for(int j = 0; j < number_of_respond; ++j){
		getline(cin, word);
		CheckTalker();
		CheckWords();
	}
}

main(){
	Input();
	Check();
	Output();
}