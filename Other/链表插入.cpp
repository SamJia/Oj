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

 /*bool insert (Node *h, int a; int pos);//h is the head position, pos is the position to insert.
 int counter£¨Node *h);
 Node* gettail(Node *h);*/

 int main()
 {
    Node * insert (Node *h, int a/*;*/, int pos);//h is the head position, pos is the position to insert.
    int counter/*£¨*/(Node *h);
    Node* gettail(Node *h);

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
		cout<<"please input the number to insert"<<endl;
		cin>>a;
		cout<<"please input the position to insert"<<endl;
		cin>>pos;
		h=insert (h,a,pos);
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
		for ( ; p->next!= NULL; p=p->next,i++)/*lack of }*/;
		return i;
	}

	//find the tail of the list.
	Node* gettail(Node *h)
	{
		Node *p=h;
		while (p->next!=NULL)
            p=p->next;
		return p;
	}
	//insert a new element
	Node * insert(Node *h, int a, int pos)
	{
		Node *p=new Node;
		p->content =a;

//		int i;
//		i=counter(/*Node *  */h);

//		Node *tail;
//		tail=gettail(/*Node *  */h);

		if (h==NULL)  //NULL list
		{///it should be able to insert only when pos=0 by logical.
		    if(!pos){
                h=p;
                p->next=NULL;
                cout<<"insert success"<<endl;
                return h;
		    }
		    else{
                cout<<"insert fault"<<'\n';
                return h;
		    }
		}

		else  //not NULL list
		{
			int i;
			i=counter(/*Node *  */h);

			Node *tail;
			tail=gettail(/*Node *  */h);
			if (pos==0)
			{
				p->next=h;
				h=p;
				cout<<"insert success"<<endl;
                return h;
			}
			/*elseif  remember the space*/else if  (pos>i){
                cout<<"insert fault"<<'\n';
                return h;
			}
			/*elseif  remember the space*/else if (pos==i)
			{
				tail->next=p;
				p->next=NULL;
				cout<<"insert success"<<endl;
                return h;
			}
			else
			{
				Node*q=h;
				while (pos>1)
				{
					q=q->next;
					pos--;
				}
				p->next=q->next;
				q->next=p;
				cout<<"insert success"<<endl;
                return h;
			}
		}
//lack of }
    }


///this is the code i write.
/*Node *insert(Node *h,int a,int pos){
    Node *p=h,*q=new Node;
    q->content=a;
    if(!pos){
        cout<<"insert success"<<'\n';
        q->next=p;
        return q;
    }
    if(!p){
        cout<<"insert fault"<<'\n';
        return p;
    }
    for(--pos;pos;--pos){
        if(p->next==NULL){
            cout<<"insert fault"<<'\n';
            return h;
        }
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
    cout<<"insert success"<<'\n';
    return h;
}*/
