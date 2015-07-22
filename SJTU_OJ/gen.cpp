#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 10000000

int main(){
	ofstream fout("data");
	srand(time(0));
	for(int i = 0; i < SIZE; ++i)
		fout << (((rand() << 16) + rand()) % 1000000) << ' ';
}