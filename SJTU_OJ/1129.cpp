#include <iostream>
#include <fstream>
using namespace std;
struct Hw{
	int hw[62];
	Hw *next;
};
//--------------------------
Hw *saved[62];
int hw_of_deity[62][62] = {0}, hw_done[62] = {0}, tmp_hw_done[62] = {0}, Belong[2][2]={1, -1, 1, 0};
int  number_of_hw, number_of_deity, min_deity;
// ifstream fin(".txt");
//--------------------------
void Input();
void Init();
void FindMinDeity();
void AddThisDeity(int nth_deity);
void AddToHwDone(int nth_deity);
void AddToThisCase(int selected_deity);
void ModifyTmp(Hw *pos);
bool AllHwDone();
void ModifySavedList(int number_to_change);
int BelongTo(Hw *p);
void Output();
//--------------------------

main(){
	Input();
	Init();
	FindMinDeity();
	Output();
}

void Input(){
	cin >> number_of_hw >> number_of_deity;
	for(int i = 0; i < number_of_deity; ++i){
		cin >> hw_of_deity[i][0];
		for(int j = 1; j <= hw_of_deity[i][0]; ++j)
			cin >> hw_of_deity[i][j];
	}
}

void Init(){
	for(int i = 0; i <= number_of_deity; ++i){
		saved[i] = new Hw;
		saved[i]->next = NULL;
	}
	saved[0]->next = new Hw;
	Hw *p = saved[0]->next;
	p->next = NULL;
	for(int i = 1; i <= number_of_hw; ++i)
		p->hw[i] = 0;
}

void FindMinDeity(){
	min_deity = number_of_deity;
	for(int i = 0; i < number_of_deity; ++i)
		AddThisDeity(i);
}

void AddThisDeity(int nth_deity){
	int max_index = min(min_deity - 2, nth_deity);
	AddToHwDone(nth_deity);
	for(int i = max_index; i >= 0; --i)
		AddToThisCase(i);
}

void AddToHwDone(int nth_deity){
	for(int i = 0; i <= number_of_hw; ++i)
		hw_done[i] = 0;
	for(int i = 1; i <= hw_of_deity[nth_deity][0]; ++i)
		hw_done[hw_of_deity[nth_deity][i]] = 1;
}

void AddToThisCase(int selected_deity){
	for(Hw *p = saved[selected_deity]->next; p; p = p->next){
		ModifyTmp(p);
		if(AllHwDone()){
			min_deity = selected_deity + 1;
			break;
		}
		ModifySavedList(selected_deity + 1);
	}
}

void ModifyTmp(Hw *pos){
	for(int i = 1; i <= number_of_hw; ++i)
		tmp_hw_done[i] = hw_done[i] + pos->hw[i];
}

bool AllHwDone(){
	for(int i = 1; i < number_of_hw; ++i)
		if(!tmp_hw_done[i])
			return(0);
	return(1);
}

void ModifySavedList(int number_to_change){
	// cout << 1;
	Hw *p = saved[number_to_change], *q = p->next;
	int belongstate = 0;
	for(; q; p = q, q = q->next){
		belongstate = BelongTo(q);
		if(belongstate == 1)
			break;
		else if(belongstate == -1){
			p->next = q->next;
			delete q;
			q = p;
		}
	}
	if(!q){
		p->next = new Hw;
		p = p->next;
		p->next = NULL;
		for(int i = 1; i <= number_of_hw; ++i)
			p->hw[i] = tmp_hw_done[i];
	}
}

int BelongTo(Hw *p){
	int belong = 0, contain = 0;
	for(int i = 1; i <= number_of_hw; ++i)
		if(tmp_hw_done[i] && !p->hw[i])
			contain = 1;
		else if(!tmp_hw_done[i] && p->hw[i])
			belong = 1;
	return(Belong[belong][contain]);
}

void Output(){
	cout << min_deity;
}