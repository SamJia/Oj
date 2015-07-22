#include <iostream>
#include <cstring>
using namespace std;

struct OneNumber{
	int number_, uncertain_[10];
};

OneNumber sudoku[9][9];

bool Input(OneNumber tmp_sudoku[9][9]);
bool Affect(OneNumber tmp_sudoku[9][9], int row, int column);
int Check(OneNumber tmp_sudoku[9][9]);
void Copy(OneNumber to[9][9], OneNumber from[9][9]);
void Output(OneNumber tmp_sudoku[9][9]);

main(){
	int sudoku_number;
	cin >> sudoku_number;
	for(int i = 0; i < sudoku_number; ++i){
		memset(sudoku, 0, sizeof(sudoku));
		if(Input(sudoku) && Check(sudoku) == 1)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
		Output(sudoku);
	}
}

bool Input(OneNumber tmp_sudoku[9][9]){
	int flag = 1;
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			cin >> tmp_sudoku[i][j].number_;
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			if(tmp_sudoku[i][j].number_ && flag)
				if(!Affect(tmp_sudoku, i, j))
					flag = 0;
	return flag;
}

bool Affect(OneNumber tmp_sudoku[9][9], int row, int column){
	int i, j, k;
	for(i = 0; i < 9; ++i)
		if(i != row){
			if(tmp_sudoku[i][column].number_ == tmp_sudoku[row][column].number_)
				return 0;
			if(!tmp_sudoku[i][column].number_)
				if(!tmp_sudoku[i][column].uncertain_[tmp_sudoku[row][column].number_]){
					tmp_sudoku[i][column].uncertain_[tmp_sudoku[row][column].number_] = 1;
					++tmp_sudoku[i][column].uncertain_[0];
					if(tmp_sudoku[i][column].uncertain_[0] == 8){
						for(k = 1; tmp_sudoku[i][column].uncertain_[k]; ++k);
						tmp_sudoku[i][column].number_ = k;
						if(!Affect(tmp_sudoku, i, column))
							return 0;
					}
				}
		}
	for(j = 0; j < 9; ++j)
		if(j != column){
			if(tmp_sudoku[row][j].number_ == tmp_sudoku[row][column].number_)
				return 0;
			if(!tmp_sudoku[row][j].number_)
				if(!tmp_sudoku[row][j].uncertain_[tmp_sudoku[row][column].number_]){
					tmp_sudoku[row][j].uncertain_[tmp_sudoku[row][column].number_] = 1;
					++tmp_sudoku[row][j].uncertain_[0];
					if(tmp_sudoku[row][j].uncertain_[0] == 8){
						for(k = 1; tmp_sudoku[row][j].uncertain_[k]; ++k);
						tmp_sudoku[row][j].number_ = k;
						if(!Affect(tmp_sudoku, row, j))
							return 0;
					}
				}
		}
	for(i = row / 3 * 3; i < row / 3 * 3 + 3; ++i)
		for(j = column / 3 * 3; j < column / 3 * 3 + 3; ++j)
			if(!(i == row && j == column)){
				if(tmp_sudoku[i][j].number_ == tmp_sudoku[row][column].number_)
					return 0;
				if(!tmp_sudoku[i][j].number_)
					if(!tmp_sudoku[i][j].uncertain_[tmp_sudoku[row][column].number_]){
						tmp_sudoku[i][j].uncertain_[tmp_sudoku[row][column].number_] = 1;
						++tmp_sudoku[i][j].uncertain_[0];
						if(tmp_sudoku[i][j].uncertain_[0] == 8){
							for(k = 1; tmp_sudoku[i][j].uncertain_[k]; ++k);
							tmp_sudoku[i][j].number_ = k;
							if(!Affect(tmp_sudoku, i, j))
								return 0;
						}
					}
			}
	return 1;
}

int Check(OneNumber tmp_sudoku[9][9]){
	int result = 1;
	for(int i = 0; i < 9 && result < 2; ++i)
		for(int j = 0; j < 9 && result < 2; ++j)
			if(!tmp_sudoku[i][j].number_){
				result = 0;
				OneNumber tmp_sudoku2[9][9];
				for(int k = 1; k < 10 && result < 2; ++k)
					if(!tmp_sudoku[i][j].uncertain_[k]){
						Copy(tmp_sudoku2, tmp_sudoku);
						tmp_sudoku2[i][j].number_ = k;
						if(Affect(tmp_sudoku2, i, j))
							result += Check(tmp_sudoku2);
					}
				return result;
			}
	return result;
}

void Copy(OneNumber to[9][9], OneNumber from[9][9]){
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			to[i][j] = from[i][j];
}

void Output(OneNumber tmp_sudoku[9][9]){
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j)
			cout << tmp_sudoku[i][j].number_ << ' ';
		cout << '\n';
	}
}