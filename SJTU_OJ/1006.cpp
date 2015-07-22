#include <iostream>
using namespace std;
int main(){
	int n,state=0,max=0,count=0;
	cin>>n;
	int num[n];
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	for(int i=0;i<n;++i){
		count+=num[i];
		if(i<n-2)
            if(count<0){
                count=0;
                if((num[i]+num[i+1])>max)
                    max=num[i]+num[i+1];
                state=0;
                continue;
            }
		if(state&&(count>max))
			max=count;
		state=1;
	}
	if(max<=0)
        cout<<"Game Over";
    else
        cout<<max;
	/*if(n>20){
		if(num[0]>0)
			state=1;
		for(int i=0;i<n;++i)
			if((num[i]>0)&&(state==1)||(num[i]<=0)&&(state==0)){
				sum+=num[i];
				++len;
			}
			else{
				if(max<(num[i-1]+num[i]))
					max=num[i-1]+num[i];
				if(max<(num[i-1]+num[i-2]))
					max=num[i-1]+num[i-2];
				num[k]=sum;
				length[k]=len;
				len=1;
				++k;
				sum=num[i];
				state=!state;
			}
		if(sum!=0){
			num[k]=sum;
			length[k]=len;
			++k;
			sum=0;
		}
		if(num[0]<=0)
			begin=1;
		if(num[k-1]<=0)
			--k;
		for(int i=begin;i<(k-2)&&(num[i]+num[i+1]<=0);i+=2){
			if(length[i]>1){
	            if(max<num[i])
	                max=num[i];
			}
			else{
				if(max<(num[i]+num[i+1]+num[i+2]))
					max=(num[i]+num[i+1]+num[i+2]);
			}
			begin+=2;
		}
		for(int i=k-1;i>(begin+1)&&(num[i]+num[i-1]<=0);i-=2){
			if(length[i]>1){
	            if(max<num[i])
	                max=num[i];
			}
			else{
				if(max<(num[i]+num[i-1]+num[i-2]))
					max=(num[i]+num[i-1]+num[i-2]);
			}
			k-=2;
		}
	    for(int i=begin;i<k;i+=2){
			count=num[i];
			if(count>max&&length[i]>1)
				max=count;
			for(int j=1;j<k-i;j+=2){
				count+=(num[i+j]+num[i+j+1]);
				if(count>max)
					max=count;
			}
		}
		if(max<=0)
			cout<<"Game Over";
		else
			cout<<max;
	}
	else{
		for(int i=0;i<(n-1);i++){
			count=num[i]+num[i+1];
			if(count>max)
				max=count;
			for(int j=2;j<n-i;j++){
				count+=num[i+j];
				if(count>max)
					max=count;
			}
		}
		if(max<=0)
			cout<<"Game Over";
		else
			cout<<max;
	}*/

	return 0;
}
