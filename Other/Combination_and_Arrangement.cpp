#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 10
struct Choice{
	int order[SIZE];
	Choice *next;
};

class CombanitonAndArrangement{
	private:
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

		void copy(int to[], int from[], int how_many_to_copy){
			for(int i = 0; i < how_many_to_copy; to[i] = from[i], ++i);
		}

		Choice *Save_choice(int chosen_number_group[], int how_many_need, Choice *p){
			p->next = new Choice;
			p = p->next;
			copy(p->order, chosen_number_group, how_many_need);
			p->next = NULL;
			return(p);
		}
	public:
		Choice *Combination(int how_many_provide, int how_many_need, int which_number_choose_now = 0){
			static Choice *head = ChoiceInit(), *p = head;
			if(!how_many_need)
				return(head);
			static int *chosen_number_group = ChosenNumberInit(how_many_need);
			int min_choice_now = chosen_number_group[which_number_choose_now - 1] + 1, max_choice_now = how_many_provide + which_number_choose_now - how_many_need;
			for(int i = min_choice_now; i <= max_choice_now; ++i){
				chosen_number_group[which_number_choose_now] = i;
				if(which_number_choose_now == how_many_need - 1)
					p = Save_choice(chosen_number_group, how_many_need, p);
				else
					Combination(how_many_provide, how_many_need, which_number_choose_now + 1);
			}
			return(head);
		}
};


main(){
	Choice *head, *p;
	int a = 20, b = 10, count = 0;
	CombanitonAndArrangement c;
	head = c.Combination(a, b);
	for(p = head->next; p; p = p->next){
		// for(int i = 0; i < b; ++i)
		// 	cout << p->order[i] << ' ';
		// cout << '\n';
		++count;
	}
	cout << count;
}