#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
struct ll{
	int num;
	struct ll *next;
};
void sort_ll(ll *list){
	int amid;
	ll *min;
	for(;list->next!=NULL;list=list->next){
		min=list;
		for(ll *i=list->next;i!=NULL;min=min->num<i->num?min:i,i=i->next);
		amid=list->num;
		list->num=min->num;
		min->num=amid;
	}
}
main(){
	int len=sizeof(ll),n;
	ll *head=(ll *)malloc(len),*l2=head;
	cout<<"please input the number of the date you want to sort"<<'\n';
	cin>>n;
	for(int i=0;i<n-1;++i){
		cin>>l2->num;
		l2->next=(ll *)malloc(len);
		l2=l2->next;
	}
	cin>>l2->num;
	l2->next=NULL;
	cout<<"this is the list sorted:"<<'\n';
	sort_ll(head);
	for(l2=head;l2!=NULL;l2=l2->next)
		cout<<l2->num<<'\n';

}
