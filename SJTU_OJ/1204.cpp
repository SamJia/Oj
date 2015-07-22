#include "LinkedList.h"
#include "cstring"
#define SIZE 110
#define LEN 2020

LinkedList<char> lines[SIZE];
int total_number = 0;

void Insert(int row, int column, char *content){
	if(row >= total_number || row < 0)
		throw OutOfBound();
	for(int i = 0; content[i]; ++i)
		lines[row].insert(column++, content[i]);
}

void Delete(int row, int column, int num){
	if(row >= total_number || row < 0)
		throw OutOfBound();
	lines[row].remove(column, num);
}

void List(int row, int column){
	if(row >= total_number || row < 0)
		throw OutOfBound();
	if(column >= total_number || column < row)
		throw OutOfBound();
	for(int i = row; i <= column; ++i)
		cout << lines[i];
}

int main(){
	char tmp[LEN];
	for(cin.getline(tmp, LEN, '\n'); strcmp(tmp, "******"); ++total_number, cin.getline(tmp, LEN, '\n'))
		for(int i = 0; tmp[i]; ++i)
			lines[total_number].add(tmp[i]);
	int row, column, num;
	for(cin>> tmp; strcmp(tmp, "quit"); cin >> tmp){
		cin >> row >> column;
		--row;
		--column;
		try{
			if(tmp[0] == 'i'){
				cin.getline(tmp, LEN, '\n');
				Insert(row, column, tmp+1);
			}
			else if(tmp[0] == 'd'){
				cin >> num;
				Delete(row, column, num);
			}
			else if(tmp[0] == 'l')
				List(row, column);
		}
		catch(OutOfBound){
			cout << "Error!\n";
		}
	}
	for(int i = 0; i < total_number; ++i)
		cout << lines[i];
}