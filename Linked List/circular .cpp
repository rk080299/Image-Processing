#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
};


void create(struct node **f,struct node**r,int item)
{
    struct node *newnode;
    newnode= new node;
    newnode->data=item;
    newnode->next=NULL;
    if(*f==NULL)

         *f=newnode;
    else
      (*r)->next=newnode;
    *r=newnode;
    (*r)->next=*f;

}


void deleted(struct node**f,struct node**r)
{struct node*temp=*f;

 if(*f==NULL)
    cout<<"empty";
 else
     {

    if(*f==*r)
      {
          *f=NULL;
          *r=NULL;
      }

       else
       {
           *f=(*f)->next;
           (*r)->next=*f;
       }

}
}

void display(struct node *f)
{  struct node * temp=f,*p=NULL;
   //cout<<"no";
     while(temp!=p)
     {   // cout<<"yes";
        cout<<temp->data<<"\n";
         temp=temp->next;
         p=f;
     }

}
int main()
{
 struct node *f,*r;
 f=r=NULL;
 int n,i,j;
 cin>>n;
 for(i=0;i<n;i++)
 {
     cin>>j;
     create(&f,&r,j);

 }
display(f);
cout<<"After deletion"<<"\n";
for(i=0;i<n-2;i++)
deleted(&f,&r);
display(f);

return 0;
}
