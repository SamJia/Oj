#include <cstdio>
#define SIZE 1010
#define LEN 50
#define UP 1000000000

int father[SIZE];
int total_number, total_pair_number, tmp1, tmp2;

class LongInt{
public:
	LongInt(){
		number_[0] = 1;
		for(int i = 1; i < LEN; ++i)
			number_[i] = 0;
	}
	void Double(){
		for(int i = 0, flag = 0; i < LEN; ++i){
			number_[i] = 2 * number_[i] + flag;
			flag = (number_[i] >= UP);
			number_[i] = flag ? number_[i] - UP : number_[i];
		}
	}
	void Print(){
		int pos = LEN - 1;
		for(; pos >= 0 && !number_[pos]; --pos);
		printf("%d", number_[pos--]);
		for(; pos >= 0; --pos){
			for(int j = UP / 10; j > 0; number_[pos] %= j, j /= 10)
				printf("%d", number_[pos] / j);
		}
	}
	int number_[LEN];
};

int Find(int node){
	// printf("Find done\n");
	int root = node;
	for(; father[root] >= 0; root = father[root]);
	for(int i = node, j; father[i] >= 0; j = father[i], father[i] = root, i = j);
	return root;
}

void Union(int root1, int root2){
	if(root1 == root2)
		return;
	if(father[root1] < father[root2]){
		father[root2] += father[root1];
		father[root1] = root2;
	}
	else{
		father[root1] += father[root2];
		father[root2] = root1;
	}
}

int main(){
	for(int i = 0; i < SIZE; ++i)
		father[i] = -1;
	scanf("%d%d", &total_number, &total_pair_number);
	for(int i = 0; i < total_pair_number; ++i){
		scanf("%d%d", &tmp1, &tmp2);
		Union(Find(tmp1), Find(tmp2));
	}
	int times = total_number;
	for(int i = 1; i <= total_number; ++i){
		times -= (father[i] < 0);
	}
	LongInt result;
	for(int i = 0; i < times; ++i)
		result.Double();
	result.Print();
}