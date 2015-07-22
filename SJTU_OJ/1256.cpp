#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;
#define MAX_HOBBIT 10
struct Choice{
	int order[MAX_HOBBIT];
	Choice *next;
};

struct Ans{
	int talker, refered, format;
} answer[20];

string name[10],word;
int number_of_hobbit = 0, number_of_lier = 0, number_of_respond = 0, i = 0, talker_id = 0, refered_id = 0, number_of_answer = 0;
char colon = ':', space = ' ';

// ifstream cin("1255.txt");


//------------------------------------------------------------------------------------------------------------------------------------
void SaveAnswer(int type){
	answer[number_of_answer].talker = talker_id;
	answer[number_of_answer].refered = refered_id;
	answer[number_of_answer++].format = type;
}

int CheckName(string letter_to_check){
	for(i = 0; i < number_of_hobbit; ++i)
		if(letter_to_check == name[i])
			return(i);
	return(number_of_hobbit);
}

void CheckTalker(){
	int pos_of_colon = word.find(colon);
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
	int pos_of_space = word.find(space);
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

void CheckRespond(){
	for(int j = 0; j < number_of_respond; ++j){
		getline(cin, word);
		CheckTalker();
		CheckWords();
	}
}
//------------------------------------------------------------------------------------------------------------------------------
int *ChosenNumberInit(int how_many_need){
	int *chosen_number_group = new int[how_many_need +1];
	chosen_number_group[0] = -1;
	return(chosen_number_group + 1);
}

Choice *ChoiceInit(){
	Choice *head = new Choice;
	head->next = NULL;
	return(head);
}

Choice *Save_choice(int chosen_number_group[], int how_many_need, Choice *p){
	p->next = new Choice;
	p = p->next;
	for(int j = 0; j < how_many_need; (p->order)[j] = chosen_number_group[j], ++j);
	p->next = NULL;
	return(p);
}

Choice *Combination(int how_many_provide, int how_many_need, int which_number_choose_now = 0){
	static Choice *head = ChoiceInit(), *p = head;
	static int *chosen_number_group = ChosenNumberInit(how_many_need);
	if(!how_many_need){
		p = Save_choice(chosen_number_group, how_many_need, p);
		return(head);
	}
	int min_choice_now = chosen_number_group[which_number_choose_now - 1] + 1;
	int max_choice_now = how_many_provide + which_number_choose_now - how_many_need;
	for(int j = min_choice_now; j <= max_choice_now; ++j){
		chosen_number_group[which_number_choose_now] = j;
		if(which_number_choose_now == how_many_need - 1)
			p = Save_choice(chosen_number_group, how_many_need, p);
		else
			Combination(how_many_provide, how_many_need, which_number_choose_now + 1);
	}
	return(head);
}
//-------------------------------------------------------------------------------------------------------------------------------
int confused = -1, impossible = -2, unknown = 0, yes = 1, no = 2, honesty = 0, lier = 1;

bool ConfusedThisTime(int lier_group[], int & conclusion_collected){
	int who_has_ring[MAX_HOBBIT] = {unknown}, date_of_today[8] = {unknown}, lier_table[MAX_HOBBIT]={unknown};
	for(i = 0; i < number_of_lier; ++i)
		lier_table[lier_group[i]] = lier;
	// for(int k = 0; k < number_of_hobbit; ++k)
	// 	cout << 1 << ' ';
	for(i = 0; i < number_of_answer; ++i){
		if(answer[i].format == 3){
			if(date_of_today[answer[i].refered] == (lier_table[answer[i].talker] == lier ? yes : no))
				return(0);
			date_of_today[answer[i].refered] = (lier_table[answer[i].talker] == lier ? no : yes);
		}
		else if(answer[i].format == 2){
			if(who_has_ring[answer[i].refered] == (lier_table[answer[i].talker] == lier ? no : yes))
				return(0);
			who_has_ring[answer[i].refered] = (lier_table[answer[i].talker] == lier ? yes : no);
		}
		else{
			if(who_has_ring[answer[i].refered] == (lier_table[answer[i].talker] == lier ? yes : no))
				return(0);
			who_has_ring[answer[i].refered] = (lier_table[answer[i].talker] == lier ? no : yes);
		}
	}
	int count_of_right_day = 0, count_of_wrong_day = 0, count_of_right_person = 0, count_of_unknown_person = 0, person_have_ring = number_of_hobbit;
	for(i = 1; i < 8; ++i)
		if(date_of_today[i] == yes)
			++count_of_right_day;
		else if(date_of_today[i] == no)
			++count_of_wrong_day;
	if(count_of_right_day > 1 || count_of_wrong_day == 7)
		return(0);
	for(i = 0; i < number_of_hobbit; ++i)
		if(who_has_ring[i] == yes){
			++count_of_right_person;
			person_have_ring = i;
		}
		else if(who_has_ring[i] == unknown){
			++count_of_unknown_person;
			if(!count_of_right_person)
				person_have_ring = i;
		}
	if(count_of_right_person > 1 )
		return(0);
	if(count_of_right_person == 0 && count_of_unknown_person > 1)
		return(1);
	if(person_have_ring < number_of_hobbit){
		if(person_have_ring != conclusion_collected && conclusion_collected < number_of_hobbit)
			return(1);
		conclusion_collected = person_have_ring;
	}
	return(0);
}

int FindTheRing(){
	Choice *lier_group_head = Combination(number_of_hobbit, number_of_lier);
	int conclusion_collected = number_of_hobbit;
	for(Choice *p = lier_group_head->next; p != NULL; p = p->next)
		if(ConfusedThisTime(p->order, conclusion_collected))
			return(confused);
	if(conclusion_collected == number_of_hobbit)
		return(impossible);
	return(conclusion_collected);
}
//---------------------------------------------------------------------------------------------------------------------------------
void Input(){
	cin >> number_of_hobbit >> number_of_lier >> number_of_respond;
	getline(cin, word);
	for(i = 0; i < number_of_hobbit; ++i)
		getline(cin, name[i]);
	for(i = 0; i < number_of_respond; ++i)
		answer[i].talker = answer[i].refered = answer[i].format = 0;
}

void Output(int person_have_ring){
	if(person_have_ring == confused)
		cout << "I am confused.";
	else if(person_have_ring == impossible)
		cout << "It is impossible!";
	else
		cout << name[person_have_ring];
}
//-------------------------------------------------------------------------------------------------------------------------------
main(){
	Input();
	CheckRespond();
	int person_have_ring = FindTheRing();
	Output(person_have_ring);
}