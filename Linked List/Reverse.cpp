#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node * next;
};
 void create(struct node**head,int item)
 {
     struct node *newnode;
     newnode=new node;
     newnode->data=item;
     newnode->next=NULL;
     if(*head==NULL)
    {
         *head=newnode;

     }

     else
     {
          struct node *temp=*head;
          while(temp->next!=NULL)
             temp=temp->next;
          temp->next=newnode;

     }
 }

void reversed(struct node **q )
 {
     struct node *temp ,*r,*s;

     temp=*q;
     r=NULL;
     while(temp!=NULL)
     {  s=r;
        r=temp;
        temp=temp->next;
         r->next=s;

     }
     *q=r;

 }

 void display(struct node **q)
 {
      if(*q==NULL)
        cout<<"empty";
      else
      {
          struct node *temp=*q;
          while(temp!=NULL)
          {cout<<temp->data<<"\n";
            temp=temp->next;
          }
      }
 }


int main()
{
    struct node *q=NULL;
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        create(&q,j);

    }
    display(&q);
    cout<<"After reverse"<<"\n";
    reversed(&q);
    display(&q);
}
