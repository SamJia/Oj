#include "LinkedList.h"

int main(){
	LinkedList<int> a,b;
	a.add(1);
	a.add(2);
	a.add(3);
	b = a;
	int c = 3;
	cout << sizeof(c);
	cout << b;
}