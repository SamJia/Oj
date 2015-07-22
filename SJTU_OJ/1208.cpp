#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

main(){
	double r, a, angle, tmp_s, max_s = 0;
	while(cin >> r >> a){
		angle = acos(a / r);
		tmp_s = angle * r * r;
		tmp_s -= sqrt(r * r - a * a) * a;
		max_s = max(max_s, tmp_s);
	}
	printf("%.2f", max_s);
}