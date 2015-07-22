/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------
int no_student = 0, student = 1, arrived_last_time = 2, arrived = 3, need_arrive = 4, total_column = 0, total_row = 0, times = 0, not_completed = 1;
int row_next[] = {0, 1, -1, 0}, column_next[] = {-1, 0, 0, 1}, field[1000][1000];
//--------------------------
void Input();
bool SuccessOrNot();
bool NotExistStudent();
void ArriveAllPoint();
void AllPointNeedArrive();
void ArriveNextPoint(int row, int column, int mark);
bool InField(int row, int column);
bool CanArrive(int row, int column);
bool CanCrossOrNot();
int CanCrossThisPoint(int row, int column);
void Output(bool result);
//--------------------------

main(){
	cin >> times;
	for (int i = 0; i < times; ++i){
		Input();
		bool result = SuccessOrNot();
		Output(result);
	}
}

void Input(){
	cin >> total_row >> total_column;
	for (int i = 0; i < total_row; ++i)
		for(int j = 0; j < total_column; ++j)
			cin >> field[i][j];
}

bool SuccessOrNot(){
	if(NotExistStudent())
		return(1);
	ArriveAllPoint();
	AllPointNeedArrive();
	return(CanCrossOrNot());
}

bool NotExistStudent(){
	for(int i = 0; i < total_row; ++i)
		for(int j = 0; j < total_column; ++j)
			if(field[i][j] == student)
				return(0);
	return(1);
}

void ArriveAllPoint(){
	field[0][0] = arrived_last_time;
	not_completed = 1;
	while(not_completed){
		not_completed = 0;
		for(int i = 0; i < total_row; ++i)
			for(int j = 0; j < total_column; ++j)
				if(field[i][j] == arrived_last_time)
					ArriveNextPoint(i, j, arrived);
	}
}

void AllPointNeedArrive(){
	field[total_row - 1][total_column - 1] = arrived_last_time;
	not_completed = 1;
	while(not_completed){
		not_completed = 0;
		for(int i = total_row - 1; i >= 0; --i)
			for(int j = total_column - 1; j >= 0; --j)
				if(field[i][j] == arrived_last_time)
					ArriveNextPoint(i, j, need_arrive);
	}
}

void ArriveNextPoint(int row, int column, int mark){
	field[row][column] = mark;
	for(int i = 0; i < 4; ++i)
		if(InField(row + row_next[i], column + column_next[i]) && CanArrive(row + row_next[i], column + column_next[i])){
			not_completed = 1;
			field[row + row_next[i]][column + column_next[i]] = arrived_last_time;
		}
}

bool InField(int row, int column){
	return(row >= 0 && row < total_row && column >= 0 && column < total_column);
}

bool CanArrive(int row, int column){
	return(field[row][column] == no_student);
}

bool CanCrossOrNot(){
	for(int i = 0; i < total_row; ++i)
		for(int j = 0; j < total_column; ++j)
			if(field[i][j] == student)
				if(CanCrossThisPoint(i, j))
					return(1);
	return(0);
}

int CanCrossThisPoint(int row, int column){
	int have_arrived = 0, can_arrive_end = 0;
	for(int i = 0; i < 4; ++i)
		if(InField(row + row_next[i], column + column_next[i])){
			if(field[row + row_next[i]][column + column_next[i]] == arrived)
				have_arrived = 1;
			else if(field[row + row_next[i]][column + column_next[i]] == need_arrive)
				can_arrive_end = 1;
		}
	return(have_arrived * can_arrive_end);
}

void Output(bool result){
	cout << result << '\n';
}