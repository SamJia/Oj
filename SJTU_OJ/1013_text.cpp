#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
main(){
	ofstream fout("1013.txt");
	fout << 10000 << ' ' << 1000 << '\n';
	srand(time(0));
	for (int i = 0; i < 1000; ++i){
		fout << rand() << ' ' << rand() << '\n';
	}
	fout.close();
}