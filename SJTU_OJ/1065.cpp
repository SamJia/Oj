#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 1010
char first_dna[SIZE], second_dna[SIZE];
int lcs_is_calculated[SIZE][SIZE] = {0};

void input(){
	// ifstream fin("1065.txt");
	cin >> first_dna;
	cin >> second_dna;
}

int find_lcs(int first_dna_begin = 0, int second_dna_begin = 0){
	if(lcs_is_calculated[first_dna_begin][second_dna_begin])
		return(lcs_is_calculated[first_dna_begin][second_dna_begin]);
	int lcs_now = 0, throw_first = 0, throw_second = 0, i, j;
	for(i = first_dna_begin, j = second_dna_begin; first_dna[i] == second_dna[j] && first_dna[i]; ++lcs_now, ++i, ++j);
	if(first_dna[i] && second_dna[j]){
		throw_first = find_lcs(i + 1, j);
		throw_second = find_lcs(i, j + 1);
		lcs_now += max(throw_first, throw_second);
	}
	lcs_is_calculated[first_dna_begin][second_dna_begin] = lcs_now;
	return(lcs_now);
}

void output(){
	cout << lcs_is_calculated[0][0];
}

main(){
	input();
	find_lcs();
	output();
}