#include "iostream"
using namespace std;

class a
{
public:
	a(int num = 0) : num_(num){}
	
};

main(){
	int a = 1;
	a = 2 + a++;
	cout << a;
}