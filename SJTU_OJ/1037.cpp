#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 10010

main(){
	int good_gress[SIZE], bad_gress[SIZE], good, bad, result = 0;
	cin >> good >> bad;
	for(int i = 0; i  < good; ++i)
		cin >> good_gress[i];
	sort(good_gress, good_gress + good);
	for(int i = 0; i < bad; ++i)
		cin >> bad_gress[i];
	sort(bad_gress, bad_gress + bad);
	for(--good; good >= 0; --good){
		for(--bad; bad >= 0 && good_gress[good] <= bad_gress[bad]; --bad);
		result += (bad >= 0 ? 2 : 1);
	}
	cout << result;
}