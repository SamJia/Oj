#include <fstream>
using namespace std;
main(){
	ofstream fout("1123");
	// fout << 50000 << ' ' << 1 << '\n';
	for(int i = 1; i <= 250; ++i)
		fout << "STAR";
		// fout << i << ' ' << i << '\n';
	fout.close();
}
