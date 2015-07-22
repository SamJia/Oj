#include <cstdio>
#define SIZE 201

int min_cost[SIZE][SIZE][SIZE] = {0}, p2q_cost[SIZE][SIZE], pos_num, command_num, command, last_command = 1;

void InputAndInit();
void Server();
inline void ModifyCost(int pos1, int pos2, int pos3, int cost);
void Output();


main(){
	InputAndInit();
	Server();
	Output();
}

void InputAndInit(){
	scanf("%d %d", &pos_num, &command_num);
	for(int i = 1; i <= pos_num; ++i)
		for(int j = 1; j <= pos_num; ++j)
			scanf("%d", &p2q_cost[i][j]);
	min_cost[1][2][3] = 1;
}

void Server(){
	for(; command_num > 0; --command_num, last_command = command){
		scanf("%d", &command);
		for(int i = last_command + 1; i <= pos_num; ++i)
			for(int j = i + 1; j <= pos_num; ++j)
				if(min_cost[last_command][i][j]){
					if(last_command == command || i == command || j == command)
						continue;
					ModifyCost(command, i, j, p2q_cost[last_command][command] + min_cost[last_command][i][j]);
					ModifyCost(command, last_command, j, p2q_cost[i][command] + min_cost[last_command][i][j]);
					ModifyCost(command, i, last_command, p2q_cost[j][command] + min_cost[last_command][i][j]);
					min_cost[last_command][i][j] = 0;
				}
		for(int i = 1; i <= last_command; ++i)
			for(int j = last_command + 1; j <= pos_num; ++j)
				if(min_cost[i][last_command][j]){
					if(last_command == command || i == command || j == command)
						continue;
					ModifyCost(command, i, j, p2q_cost[last_command][command] + min_cost[i][last_command][j]);
					ModifyCost(command, last_command, j, p2q_cost[i][command] + min_cost[i][last_command][j]);
					ModifyCost(command, i, last_command, p2q_cost[j][command] + min_cost[i][last_command][j]);
					min_cost[i][last_command][j] = 0;
				}
		for(int i = 1; i <= last_command; ++i)
			for(int j = i + 1; j <= last_command; ++j)
				if(min_cost[i][j][last_command]){
					if(last_command == command || i == command || j == command)
						continue;
					ModifyCost(command, i, j, p2q_cost[last_command][command] + min_cost[i][j][last_command]);
					ModifyCost(command, last_command, j, p2q_cost[i][command] + min_cost[i][j][last_command]);
					ModifyCost(command, i, last_command, p2q_cost[j][command] + min_cost[i][j][last_command]);
					min_cost[i][j][last_command] = 0;
				}
	}
}

inline void ModifyCost(int pos1, int pos2, int pos3, int cost){
	if(pos1 > pos2)
		pos1 = pos2 + pos1 - (pos2 = pos1);
	if(pos2 > pos3)
		pos2 = pos3 + pos2 - (pos3 = pos2);
	if(pos1 > pos2)
		pos1 = pos2 + pos1 - (pos2 = pos1);
	if(min_cost[pos1][pos2][pos3] > cost || !min_cost[pos1][pos2][pos3]){
		min_cost[pos1][pos2][pos3] = cost;
	}
}

void Output(){
	int min_cost_to_output = 0x7fffffff;
	for(int i = last_command + 1; i <= pos_num; ++i)
		for(int j = i + 1; j <= pos_num; ++j)
			if(min_cost[last_command][i][j])
				if(min_cost[last_command][i][j] < min_cost_to_output)
					min_cost_to_output = min_cost[last_command][i][j];
	for(int i = 1; i < last_command; ++i)
		for(int j = last_command + 1; j <= pos_num; ++j)
			if(min_cost[i][last_command][j])
				if(min_cost[i][last_command][j] < min_cost_to_output)
					min_cost_to_output = min_cost[i][last_command][j];
	for(int i = 1; i < last_command; ++i)
		for(int j = i + 1; j < last_command; ++j)
			if(min_cost[i][j][last_command])
				if(min_cost[i][j][last_command] < min_cost_to_output)
					min_cost_to_output = min_cost[i][j][last_command];
	printf("%d\n", min_cost_to_output - 1);
}