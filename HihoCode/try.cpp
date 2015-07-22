#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
	int a;
};

class Try{
public:
	// typedef bool (*CMP)(const Node &a, const Node &b);

	bool comp(const Node &a, const Node &b){
		return true;
	}

	void sort(bool (*cmp)(const Node &a, const Node &b) = comp){
		cout << "ok";
	}

};

int main(){
	// Node a, b;
	// sort();
	// long long a = 1000000007;
	// cout << a * a;
	// return 0;
}