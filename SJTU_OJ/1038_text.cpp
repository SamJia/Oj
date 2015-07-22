#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
main(){
	ofstream fout("1038.txt");
	int a = 1000;
	fout << a << '\n';
	srand(time(0));
	for(int i = 0; i < a - 1; ++i)
		fout << rand() << '\n';
}