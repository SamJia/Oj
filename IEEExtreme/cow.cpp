#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
long long K;
int f[4] = {1, 0, 0, 0};
int mod = 1000000007;
struct matrix
{
	long long m[4][4];
	matrix() {
		memset(m, 0, sizeof(m));
		m[0][0] = m[0][1] = m[1][0] = m[1][1] = m[1][2] = m[2][1] = m[2][2] = m[2][3] = m[3][3] = m[3][2] = 1;
	}
	matrix(matrix &a) {
		for (int i = 0; i < 4; ++i)for (int j = 0; j < 4; ++j)m[i][j] = a.m[i][j];
	}
	void print() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				cout << m[i][j] << ' ';
			cout << endl;
		}
	}
};

pair<long long, long long> c[105];

void mul(matrix &a, matrix &b, matrix &n) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			n.m[i][j] = 0;
			for (int k = 0; k < 4; ++k) {
				n.m[i][j] = (n.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
			}
		}
	}
}

void power(matrix &m, long long n, matrix &res) {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (i == j)res.m[i][j] = 1;
			else res.m[i][j] = 0;

	while (n>0) {
		if (n & 1) {
			matrix a(res);
			mul(a, m, res);
		}
		n >>= 1;
		matrix a(m);
		matrix b(m);
		mul(a, b, m);
	}
}

void init() {
	for (int i = 0; i < N; ++i) {
		cin >> c[i].second >> c[i].first;
		--c[i].second;
	}
	sort(c, c + N);
	// for(int i = 0; i < N; ++i)
	// 	cout<<c[i].first<<' ';
	// cout<<endl;
}
int main() {
	cin >> K >> N;
	init();
	long long cur = 1;
	long long ci, cj;
	for (int ii = 0; ii <= N; ++ii) {
		ci = c[ii].second, cj = c[ii].first;
		matrix A;
		matrix tmp_matrix;
		long long tmp;
		if (N > ii) {
			tmp = cj - cur;
		} else {
			tmp = K - cur;
		}
		{

			power(A, tmp, tmp_matrix);
			// tmp_matrix.print();
			// cout << "before "; for (int i = 0; i < 4; ++i)cout << f[i] << ' '; cout << endl;
			// cout << "middle ";
			int r[4];
			for (int i = 0; i < 4; ++i) {
				int temp = 0;
				for (int j = 0; j < 4; ++j)
					temp = (temp + f[j] * tmp_matrix.m[i][j]) % mod;
				r[i] = temp;
				// cout << r[i] << ' ';
			}
			for (int i = 0; i < 4; ++i)f[i] = r[i];
			// cout << "ci:" << ci << '\n';
			if(ii < N)
				f[ci] = 0;
			cur = cj;
			// for(int i = 0; i < 4; ++i)
			// 	cout << f[i] << ' ';
			// cout << '\n';
		}
		// cout << endl;
		// if (N > ii) {
		// 	int t[4];
		// 	while (ii < N - 1 && c[ii + 1].j == c[ii].first)f[c[ii++].i] = 0;
		// 	if (f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0) {cout << 0 << endl; return 0;}
		// 	t[0] = (f[1] + f[0]) % mod, t[1] = (f[0] + f[1] + f[2]) % mod, t[2] = (f[2] + f[3] + f[1]) % mod, t[3] = (f[2] + f[3]) % mod;
		// 	for (int i = 0; i < 4; ++i)f[i] = t[i];
		// 	cout << "after "; for (int i = 0; i < 4; ++i)cout << f[i] << ' '; cout << endl;
		// 	cur = c[ii].first;
		// }
	}
	cout << f[0] << endl;
}