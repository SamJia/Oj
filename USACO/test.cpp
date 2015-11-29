/*
ID: sammail1
PROG: lamps
LANG: C++
*/
#include <cstdio>
#define SIZE 150
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int button[10] = {};
int lamp[SIZE] = {}, require[SIZE] = {};
int total_lamp, total_button, tmp;
bool flag = false;

bool Operate(){
    // tmp = button[0] + button[1] + button[2] + button[3];
    // if(tmp > total_button || (total_button - tmp) % 2 != 0)
    //     return false;
    for(int i = 0; i < SIZE; ++i)
        lamp[i] = 1;
    if(button[0])
        for(int i = 1; i <= total_lamp; ++i)
            lamp[i] = 1 - lamp[i];
    if(button[1])
        for(int i = 1; i <= total_lamp; i += 2)
            lamp[i] = 1 - lamp[i];
    if(button[2])
        for(int i = 2; i <= total_lamp; i += 2)
            lamp[i] = 1 - lamp[i];
    if(button[3])
        for(int i = 1; i <= total_lamp; i += 3)
            lamp[i] = 1 - lamp[i];
    return true;
}

bool Check(){
    for(int i = 1; i <= total_lamp; ++i)
        if(require[i] >= 0 && require[i] != lamp[i])
            return false;
    return true;
}

void Print(){
    flag = true;
    for(int i = 1; i <= total_lamp; ++i)
        printf("%d", lamp[i]);
    printf("\t");
    printf("%d, %d, %d, %d\n", button[0], button[1], button[2], button[3]);
}

int main() {
    // freopen("lamps.in", "r", stdin);
    // freopen("lamps.out", "w", stdout);
    for (int i = 0; i < SIZE; ++i)
        require[i] = -1;
    scanf("%d%d", &total_lamp, &total_button);
    // for (scanf("%d", &tmp); tmp != -1; scanf("%d", &tmp))
    //     require[tmp] = 1;
    // for (scanf("%d", &tmp); tmp != -1; scanf("%d", &tmp))
    //     require[tmp] = 0;
    for (button[0] = 0; button[0] < 2; ++button[0])
        for (button[1] = 0; button[1] < 2; ++button[1])
            for (button[2] = 0; button[2] < 2; ++button[2])
                for (button[3] = 0; button[3] < 2; ++button[3])
                    if (Operate())
                        Print();
    if(!flag)
        printf("IMPOSSIBLE\n");
    return 0;
}