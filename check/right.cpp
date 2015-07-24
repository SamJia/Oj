#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MOD_NUM 10007

int T, n, tmp;
long long res;
priority_queue<long long> q;

int main() {
    // cin >> T;
    // while (T--) {
        cin >> n;
        res = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            q.push(tmp);
        }
        unsigned long long i = n;
        while (!q.empty()) {
            res = (res + (q.top() * i)) % MOD_NUM;
            res = (res - (q.top() * (n - i + 1))) % MOD_NUM;
            --i;
            q.pop();
        }
        cout << res << endl;
    // }
    return 0;
}