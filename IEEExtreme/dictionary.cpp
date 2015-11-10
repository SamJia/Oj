#include <cstdio>
#include <cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define SIZE 41000

int word[110][27];
int dic[27];
bool perfect[27];
int lack[27];
char tmp[SIZE];
int total_case, total_word, total_dic;

void Count(char str[], int count[]) {
	for (int i = 0; str[i]; ++i)
		++count[str[i] - 'a'];
}

void Compare(int num) {
	for (int i = 0; i < 26; ++i)
		if (word[num][i] > dic[i])
			lack[i] = MAX(lack[i], word[num][i] - dic[i]);
		else if(word[num][i] == dic[i])
			perfect[i] = true;
}

void Compute() {
	for (int i = 0; i < total_word; ++i)
		Compare(i);
	int sum = 0;
	for (int i = 0; i < 26; ++i)
		sum += lack[i];
	if (!sum) {
		for (int i = 0; i < 26; ++i)
			if (!perfect[i]) {
				printf("Yes No\n");
				return;
			}
		printf("Yes Yes\n");
	}
	else {
		printf("No %d\n", sum);
	}

}

int main() {
	scanf("%d", &total_case);
	for (int i = 0; i < total_case; ++i) {
		scanf("%d%d", &total_word, &total_dic);
		memset(word, 0, sizeof(word[0][0]) * 110 * 27);
		for (int j = 0; j < total_word; ++j) {
			scanf("%s", tmp);
			Count(tmp, word[j]);
		}
		for (int j = 0; j < total_dic; ++j) {
			scanf("%s", tmp);
			memset(dic, 0, sizeof(dic[0]) * 27);
			memset(perfect, 0, sizeof(perfect[0]) * 27);
			memset(lack, 0, sizeof(lack[0]) * 27);
			Count(tmp, dic);
			Compute();
		}
	}
}