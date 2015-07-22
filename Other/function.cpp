#include <iostream>
using namespace std;


//a function to round.
template <typename T>
double round(T num,int digit=0){
	if(num<0)
		return(-round(-num,digit));
	else{
		num=num*(10^digit);
		num+=0.5;
		return((int)num/(10^digit));
	}
}
//sort function
template <class T>
void quick_sort(T *start,T *end){
	if((end-start)<=1)
		return;
	T *num_small=start,*num_large=end-1,amid=start[0],exchange;
	for(int i=1;num_large>num_small;){
		if(start[i]<=amid)
			*num_small++=start[i++];
		else{
			exchange=*num_large;
			*num_large--=start[i];
			start[i]=exchange;
		}
	}
	quick_sort(start,num_small);
	quick_sort(num_large+1,end);
	*num_small=amid;
}

main(){
    int array[]={10,543,76,78,4,76,45,6,54,36,48,65,2,4,8,43,5};
	quick_sort(array,array+17);
	for(int i=0;i<17;++i)
	cout<<array[i]<<endl;
}
