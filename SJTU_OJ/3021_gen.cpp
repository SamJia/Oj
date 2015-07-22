#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio>
using namespace std;

main(){
	int a = 100000;
	ofstream fout("3021.txt");
	while(a)
		fout << a-- << '\n';
}
