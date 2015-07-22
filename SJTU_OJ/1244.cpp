#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define x first
#define y second
using namespace std;
double cro_prod(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3){
	double x1=p2.x-p1.x,y1=p2.y-p1.y,x2=p3.x-p2.x,y2=p3.y-p2.y;
	double prod=x1*y2-x2*y1;
	return (prod);
}

// void point_sort(pair<double,double> *start,pair<double,double> *end){
// 	if((end-start)<=1)
// 		return;
// 	pair<double,double> *num_small=start,*num_large=end-1,amid=start[0],exchange;
// 	for(int i=1;num_large>num_small;){
// 		if(start[i].x<amid.x||start[i].x==amid.x&&start[i].y<amid.y)
// 			*num_small++=start[i++];
// 		else{
// 			exchange=*num_large;
// 			*num_large--=start[i];
// 			start[i]=exchange;
// 		}
// 	}
// 	point_sort(start,num_small);
// 	point_sort(num_large+1,end);
// 	*num_small=amid;
// }



// void angel_sort(pair<double,double> *start,pair<double,double> *end){
// 	if((end-start)<=1)
// 		return;
// 	pair<double,double> *num_small=start,*num_large=end-1,amid=start[0],exchange;
// 	for(int i=1;num_large>num_small;){
// 		if(atan2(start[i].y,start[i].x)<=atan2(amid.x,amid.y))
// 			*num_small++=start[i++];
// 		else{
// 			exchange=*num_large;
// 			*num_large--=start[i];
// 			start[i]=exchange;
// 		}
// 	}
// 	angel_sort(start,num_small);
// 	angel_sort(num_large+1,end);
// 	*num_small=amid;
// }
inline bool cmp(const pair<double,double> &a,const pair<double,double> &b){
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}
main(){
	int n;
	cin>>n;
	double dis=0;
	if(n<=10000){
		double x[n],y[n];
		for(int i=0;i<n;++i){
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)>dis)
					dis=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
    }
	else{
		pair<double,double> point[n];
		for(int i=0;i<n;++i){
			cin>>point[i].x>>point[i].y;
		}
		sort(point, point+n);
        for (int i = n-1; i >= 0; --i){
            point[i].x -= point[0].x;
            point[i].y -= point[0].y;
        }
		sort(point,point+n,cmp);
		pair<double,double> polygon[n];
		int i_point=0,i_polygon=0;
		for(;i_point<n;){
                if(i_polygon>1&&cro_prod(polygon[i_polygon-2],polygon[i_polygon-1],point[i_point])<0)
                        --i_polygon;
                else
                    polygon[i_polygon++]=point[i_point++];
		}
		for(int i=0;i<i_polygon;++i)
			for(int j=i+1;j<i_polygon;++j)
				if(pow(polygon[i].x-polygon[j].x,2)+pow(polygon[i].y-polygon[j].y,2)>dis)
					dis=pow(polygon[i].x-polygon[j].x,2)+pow(polygon[i].y-polygon[j].y,2);
	}
	cout<<fixed<<setprecision(4)<<sqrt(dis)<<endl;
}
