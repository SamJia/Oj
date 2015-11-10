#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
using namespace std;

int main(){
	int begin_time = clock();
	FILE *fp = fopen("test.txt", "w");
	ofstream fout("test.txt");
	char c[] = {"qwer"};
	int a = 123;
	// for(int i = 0; i < 1000000; ++i)
	// 	fout.write((char *)&a,4);
	// 	fout.write("\n",1);
		// fout << c << '\n';
		// fprintf(fp, "%s\n", c);
	for(int i = 0; i < 1000; ++i)
		printf("%d\t%d\t%d\n", a, a, a);
		// cout << a << '\t' << a << '\t' << a << '\n';
	printf("%d\n", clock() - begin_time);
	fclose(fp);
}