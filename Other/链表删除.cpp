/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
using namespace std;

struct Node
{int content;
 Node *next;
 };

 /*bool delete_one (Node *h, int pos);//h is the head position, pos is the position to delete.
 int counter£¨Node *h);
 Node* gettail(Node *h);*/

 int main()
 {
    Node * delete_one (Node *h/*;*/, int pos);//h is the head position, pos is the position to delete.
    int counter/*£¨*/(Node *h);
    Node* getinferior(Node *h);

	int a;
	int pos=0;
	int i=0;
	Node *h=new Node,*p=h,*q=h;
	int state=0,go_on=1,empty=1;
	h->content=0;
    cout<<"please input a list, using space to separate two number"<<'\n';
    char num[1000]={'\0'};
    cin.getline(num,1000);
    for(int i=0;i<1000&&num[i]!='\0';++i){
        if(num[i]==' '){
            state=1;
            continue;
        }
        if(state){
            q=new Node;
            p->next=q;
            p=q;
            p->content=0;
            state=0;
        }
        p->content=p->content*10+num[i]-'0';
        empty=0;
    }
    p->next=NULL;
    if(empty)
        h=NULL;
	while (go_on)
	{
		char x;
		cout<<"please input the position to delete"<<endl;
		cin>>pos;
		h=delete_one (h,pos);
		cout<<"now the list is:"<<'\n';
		for(p=h;p!=NULL;p=p->next)
            cout<<p->content<<' ';
        cout<<'\n';
        cout<<"do you want to go on? 1(yes),0(no)"<<'\n';
        cin>>go_on;
	}
	return 0;
///lack of }
 }
	//count the length of the list.
	///int counter£¨Node *h£©
	int counter(Node *h)
	{
		Node *p=h;
		///int i=0;
		int i=1;
		for ( ; p->next!= NULL; p=p->next,i++)/*lack of ;*/;
		return i;
	}

	//find the inferior of the list.
	Node* getinferior(Node *&h)
	{
		Node *p=h;
		Node *q=NULL;
		while (p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		return q;
	}
	//delete an element.
	Node * delete_one1(Node *h, int pos)
	{

//		int i;
//		i=counter(/*Node *  */h);

//		Node *tail;
//		tail=gettail(/*Node *  */h);

		if (h==NULL)  //NULL list
		{
            cout<<"delete fault"<<'\n';
            return h;
		}

		else  //not NULL list
		{
			int i;
			i=counter(/*Node *  */h);

			Node *inferior;
			inferior=getinferior(/*Node *  */h);
			/*elseif  remember the space*/if  (pos>i){
                cout<<"delete fault"<<'\n';
                return h;
			}
			/*elseif  remember the space*/else if (pos==i)
			{
				inferior->next=NULL;
				cout<<"delete success"<<endl;
                return h;
			}
			else if (pos==0)
			{
				h=h->next;
				cout<<"delete success"<<endl;
				return h;
			}
			else
			{
				Node *v=NULL;
				Node *q=h;
				/*while (pos>1)
				{
					q=q->next;
					pos--;
				}
				v=q->next;
				q->next=v->next;
				v->next=NULL;*/
				///the origin code will delete the element whose position is pos+1.
				while (pos>1)
				{
					q=q->next;
					pos--;
				}
				v=q->next;
				q->next=v->next;
				v->next=NULL;
				cout<<"delete success"<<endl;
                return h;
			}
		}
//lack of }
    }


///this is the code i write.
/*Node *delete_one(Node *h,int pos){
    Node *p=h,*q=p;
    if(!p){
        cout<<"delete fault"<<'\n';
        return h;
    }
    if(!pos){
        cout<<"delete success"<<'\n';
        return h->next;
    }
    for(;pos;--pos){
        if(p->next==NULL){
            cout<<"delete fault"<<'\n';
            return h;
        }
        q=p;
        p=p->next;
    }
    q->next=p->next;
    cout<<"delete success"<<'\n';
    return h;
}*/

