#include <iostream>
#include <cstdlib>
using namespace std;

int n;
char num_mines[100100];
int mines[100100];
//bool bool_m[100100];

bool check(int x, int num)
{
	if (x == n-1)
	{
		if (num_mines[x] != '*')
			if (num > num_mines[x] - '0' || !num && num_mines[x] == '2')
				return false;
		if (num_mines[x-1] != '*')
			if (num > num_mines[x-1] - '0' || !num && num_mines[x-1] == '3')
				return false;
	}

	else if (x > 0)
	{
		if (num_mines[x] != '*')
			if (num + mines[x+1] > num_mines[x] - '0' || num + mines[x+1] < num_mines[x] - '1')
				return false;
		if (num_mines[x+1] != '*')
			if (num + mines[x+1] + mines[x+2] != num_mines[x+1] - '0')
				return false;
		if (num_mines[x-1] != '*')
			if ((num > num_mines[x-1] - '0') || !num && num_mines[x-1] == '3')
				return false;
	}

	else if (x == 0)
	{
		if (num_mines[x] != '*')
			if (num + mines[x+1] != num_mines[x] - '0')
				return false;
		if (num_mines[x+1] != '*')
			if (num + mines[x+1] + mines[x+2] != num_mines[x+1] - '0')
				return false;
	}
	return true;
}

bool dfs(int x)
{
	mines[x] = 1;
	if (x < 0)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if(mines[i] == 1)
				sum++;
		cout << sum << endl;
		for (int i = 0; i < n; ++i)
			cout << mines[i] ;
		exit(0);
	}

	else
	{
		if(check(x, 1))
		{
			mines[x] = 1;
			dfs(x-1);
		}
		if (check(x, 0))
		{
			mines[x] = 0;
			dfs(x-1);
		}
	}
}

int main()
{
	cin >> n;
	cin >> num_mines;
	dfs(n-1);
}
