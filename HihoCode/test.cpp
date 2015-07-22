#include<cstdio>
struct point{
	int x,y,z;
};
int n;
void operation1(point *,int,int);
void operation2(point *,int,int);
int operation3(point *,int,int);
int main()
{
	int m,operation,row,column;
	scanf("%d",&n);
	point *a=new point[n];
	int *b=new int[n];
	for(int i=0;i<n;++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	scanf("%d",&m);
	int j=0;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&operation,&row,&column);
		if(operation==0)operation1(a,row,column);
		else if(operation==1)operation2(a,row,column);
		else if(operation==2){
			b[j++]=operation3(a,row,column);}
	}
	for(int i=0;i<j;++i)printf("%d\n",b[i]);
	delete[] a;
	delete[] b;
	return 0;
}
void operation1(point *a,int row,int column)
{
	for(int i=0;i<n;++i){
		if(a[i].x==row)a[i].x=column;
		else if(a[i].x==column)a[i].x=row;}
}
void operation2(point *a,int row,int column)
{
	for(int i=0;i<n;++i){
		if(a[i].y==row)a[i].y=column;
		else if(a[i].y==column)a[i].y=row;}
}
int operation3(point *a,int row,int column)
{
	for(int i=0;i<n;++i)
		if(a[i].x==row&&a[i].y==column)return a[i].z;
}