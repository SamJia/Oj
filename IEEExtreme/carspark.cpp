#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 3000
#define MAX(x,y) ((x)>(y)?(x):(y))

struct Book{
	int begin_, end_, value_;
};

bool cmp(const Book &book1, const Book &book2){
	return book1.end_ < book2.end_;
}

int total_case, total_book;
Book books[SIZE];
int result[SIZE] = {};

int main(){
	scanf("%d", &total_case);
	int tmp;
	for(int i = 0; i < total_case; ++i){
		memset(result, 0, sizeof(result[0]) * SIZE);
		scanf("%d", &total_book);
		for(int j = 0; j < total_book; ++j)
			scanf("%d%d%d", &books[j].begin_, &books[j].end_, &books[j].value_);
		sort(books, books + total_book, cmp);
		for(int j = 0; j < total_book; ++j){
			tmp = 0;
			for(int k = 0; k <= books[j].begin_; ++k)
				tmp = MAX(tmp, result[k]);
			result[books[j].end_] = MAX(result[books[j].end_], tmp + books[j].value_);
		}
		tmp = 0;
		for(int j = 0; j <= 48; ++j)
			tmp = MAX(tmp, result[j]);
		printf("%d\n", tmp);
	}
}