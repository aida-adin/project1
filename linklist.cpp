#include<iostream>
using namespace std;

class node{
    int num;
    node *next;
public:
    friend class linklist;
    node(){next=nullptr;}
};

class linklist{
private:
    node *first;
    node *last;
public:
    linklist(){first=nullptr;}
    void insertlast(int n)
    {
        node *newnode=new node;
        if(first==nullptr)
        {
            first=newnode;
            first->num=n;
            last=newnode;
        }
        else{
            last->next=newnode;
            last=newnode;
            last->num=n;
        }
    }

    void print()
    {
        node *temp=first;
        while(temp!=nullptr){
            cout<<temp->num<<" ";
            temp=temp->next;
        }
    }

    void deletefirst(){first=first->next;}

    void deletelast()
    {
        node *p1=first;
        node *p2=first;
        while(p2!=nullptr){
            if(p2->next==nullptr)
                p1->next=nullptr;
            p1=p2;
            p2=p2->next;
        }
    }

    void deletenum(int n)
    {
        node *temp=first;
        node *before=first;
        while(temp!=nullptr){
            if(temp->num==n)
                before->next=temp->next;
            before=temp;
            temp=temp->next;
        }
    }

    void insertfirst(int n){
        node *newnode=new node;
        newnode->next=first;
        newnode->num=n;
        first=newnode;
    }

    void insertnum(int n){
        node *newnode=new node;
        node *temp=first;
        node *before=first;
        while(temp!=nullptr)
        {
            if(temp->num>=n&&before->num<=n)
            {
                newnode->next=before->next;
                before->next=newnode;
                newnode->num=n;
                break;
            }
            before=temp;
            temp=temp->next;
        }
    }

};
main()
{
    int n,x,i,y,z,t;
    linklist a;
    cout<<"enter a number for your elements:\n";
    cin>>t;
    cout<<"enter your elements: \n";
    for(i=0;i<t;i++){
        cin>>n;
        a.insertlast(n);
    }
    cout<<"your elements:\n";
    a.print();
    a.deletefirst();
    cout<<"\ndelete first:"<<endl;
    a.print();
    a.deletelast();
    cout<<"\ndelete last:"<<endl;
    a.print();
    cout<<"\nenter a numer for delete:"<<endl;
    cin>>x;
    a.deletenum(x);
    cout<<endl;
    a.print();
    cout<<"\nenter number for insert first:"<<endl;
    cin>>y;
    a.insertfirst(y);
    cout<<endl;
    a.print();
    cout<<"\nenter number for insert:"<<endl;
    cin>>z;
    a.insertnum(z);
    cout<<endl;
    a.print();
}