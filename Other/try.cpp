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
class Try
{
public:
	Try(int num = 0) : num_(num){
		cout << num_ << "con\n";
	}
	Try(const Try& tmp) : num_(tmp.num_){
		cout << num_ << "copy\n";
	}
	Try &operator=(const Try & tmp){
		cout << num_ << "===\n";
		return *this;
	}
	~Try(){
		cout << num_ << "de\n";
	}

	int num_;
};
template <typename t, int a>
void fun(t qw){
	cout << qw;
}

bool f(){
	cout << 2;
	return 1;
}

int main(){
    int x = 1;
    cout << (x += 1) + (x += 1);
}
