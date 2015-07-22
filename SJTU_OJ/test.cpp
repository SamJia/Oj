//1053
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
 
map <pair <int,int> , int> m1;
int orig_row[100000],orig_col[100000];    //the Original line/row of altered lines/rows. 
void swap_x(int x1, int x2 ,int n){
    /*for (int i=0;i<n;++i){
        if (datas[i].x==x1)
            datas[i].x=x2;
        else if (datas[i].x==x2)
            datas[i].x=x1;
    }*/
    swap(orig_row[x1],orig_row[x2]);
}
 
void swap_y(int y1, int y2 ,int n){
    /*for (int i=0;i<n;++i){
        if (datas[i].y==y1)
            datas[i].y=y2;
        else if (datas[i].y==y2)
            datas[i].y=y1;
    }*/
    swap(orig_col[y1],orig_col[y2]);
}
 
void show(int x,int y,int n){
    int x1=orig_row[x];int y1=orig_col[y];
    /*for (int i=0;i<n;++i){
        if (datas[i].x==x1 && datas[i].y==y1){
            cout << datas[i].value << endl;
            return;
        }
    }*/
    cout << m1[make_pair(x1,y1)] << '\n';
    
}
 
int main(){
    int n,m;
 
    for (int i=0;i<100000;++i){
        orig_row[i]=i;
        orig_col[i]=i;
    }
    cin >> n;
    for (int i=0;i<n;++i){
        int x,y,value;
        scanf("%d%d%d",&x,&y,&value);
        m1.insert(make_pair(make_pair(x,y),value));
    }
    cin >> m;
    for (int i=0;i<m;++i){
        int ope,x,y;
        scanf("%d%d%d",&ope,&x,&y);
        switch (ope){
            case 0: swap_x(x,y,n);break;
            case 1: swap_y(x,y,n);break;
            case 2: show(x,y,n); break;
        }
        
    }
    return 0;
}