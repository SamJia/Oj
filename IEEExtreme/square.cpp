#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;

int n, m;
char matrix[100][100];
int redirect[10000];
int race[10000];
int playerState[10];
map<char, int> snakeList;
map<int, int> bunnieList;


void terminateGame()
{
	for(int i = 0; i < m; ++i)
		cout << playerState[i]+1 << ' ';
	exit(0);
}

bool move(int player, int step)
{
	int state = playerState[player];
	race[state] = 0;
	for(int i = 0; i < step-1; ++i)
	{
		++state;
		if(state == n*n-1)
		{
			playerState[player] = state;
			terminateGame();
		}
	}
	// for last time:
	bool confirmed = false;
	int prev = state;
	while(!confirmed)
	{
		++state;
		while(race[state])
			++state;
		if(redirect[state] != -1)
			state = redirect[state];
		if(state == prev)
			return false;
		prev = state;
		if(!race[state])
			confirmed = true;
	}
	playerState[player] = state;
	race[state] = 1;
	if(state == n*n-1)
		terminateGame();
	return true;
}

void evilLoop(int player)
{
	cout << "PLAYER " << player+1 << " WINS BY EVIL CYCLE!";
	exit(0);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> matrix[i][j];
	int idx = 0;
	for(int i = 0; i < n*n; ++i)
		redirect[i] = -1;
	for(int i = n-1; i >= 0; --i)
	{
		if(!(i % 2))	// odd row, even idx num
		{
			for(int j = 0; j < n; ++j)
			{
				if(matrix[i][j] == '-')
					++idx;
				else if(isalpha(matrix[i][j]))
				{
					if(snakeList.find(matrix[i][j]) != snakeList.end())
						redirect[idx] = snakeList.find(matrix[i][j])->second;
					else
						snakeList[matrix[i][j]] = idx;
					++idx;
				}
				else
				{
					if(bunnieList.find(matrix[i][j]) != bunnieList.end())
						redirect[bunnieList.find(matrix[i][j])->second] = idx;
					else
						bunnieList[matrix[i][j]] = idx;
					++idx;
				}
			}
				
		}	
		else
		{
			for(int j = n-1; j >= 0; --j)
			{
				if(matrix[i][j] == '-')
					++idx;
				else if(isalpha(matrix[i][j]))
				{
					if(snakeList.find(matrix[i][j]) != snakeList.end())
						redirect[idx] = snakeList.find(matrix[i][j])->second;
					else
						snakeList[matrix[i][j]] = idx;
					++idx;
				}
				else
				{
					if(bunnieList.find(matrix[i][j]) != bunnieList.end())
						redirect[bunnieList.find(matrix[i][j])->second] = idx;
					else
						bunnieList[matrix[i][j]] = idx;
					++idx;
				}
			}
		}
	}
	cin >> m;
	int dice1, dice2;
	int player = -1;
	for(int i = 0; i < m; ++i)
		playerState[i] = -1;
	while(cin >> dice1 && cin >> dice2)
	{
		player = (player + 1) % m;
		if(!move(player, dice1+dice2))
			evilLoop(player);
		if(dice1 == dice2)
		{
			int dice;
			cin >> dice;
			if(!move(player, dice))
				evilLoop(player);
		}
		// cout << player << " in " << playerState[player] << endl;

	}
	terminateGame();
	return 0;
}