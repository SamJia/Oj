#include <cstdio>
#define SIZE 1000500
#define UP 10007

int total_number, tmp;
unsigned long long result = 0, count[SIZE] = {};

int main(){
    scanf("%d", &total_number);
    for(int i = 0; i < total_number; ++i){
        scanf("%d", &tmp);
        ++count[tmp];
    }
    for(int i = 0; i < SIZE - 10; ++i){
        result = (result + count[i] * (total_number - count[i])) % UP;
        count[i+1] += count[i];
    }
    printf("%lld\n", result);
}