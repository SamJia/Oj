#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
main(){
	char name[]={'a','b','b','c','\0'};
	ofstream fout("name.txt");
	for(int i=0;i<500;++i)
		fout<<name;
}
