/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//--------------------------

main(){
	ofstream fout("1088.txt");
	srand(time(0));
	int a, b, c;
	// a = rand() % 15 + 1;
	a = 5;
	fout << a << '\n';
	int post[a][a];
	for (int i = 0; i < a; ++i){
		post[i][i] = 0;
	}
	for(int i = 0; i < a; ++i)
		for(int j = i + 1; j < a; ++j)
			post[i][j] = post[j][i] = rand() % 21;
	for(int i = 0; i < a; ++i){
		for(int j = 0; j < a; ++j)
			fout << post[i][j] << ' ';
		fout << '\n';
	}
}
