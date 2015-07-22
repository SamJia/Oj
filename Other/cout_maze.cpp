#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 50
main(){
	srand(time(0));
	ofstream fout("1031.txt");
	fout<<N<<'\n';
	for(int i=0;i<N*N;++i){
		fout<<rand()%111<<' ';
		if((i+1)%N==0)
			fout<<'\n';
	}
	fout.close();
}
