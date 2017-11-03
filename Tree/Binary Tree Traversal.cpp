#include <iostream>

using namespace std;

struct node
{

    int data;
    struct node *leftchild;
    struct node *rightchild;
};
struct node *Binarytree(char *,int ,int);
void display(struct node*,int);
void preorder(struct node*);
void inorder (struct node *);
void postorder(struct node*);

struct node * Binarytree( int *list ,int lower ,int upper)
{   
    struct  node *newnode;
    int mid=(lower+upper)/2;
    newnode=new node;
    newnode->data=list [mid];
      
    if(lower>=upper)
   {   
        newnode->leftchild=NULL;
        newnode->rightchild=NULL;
        return (newnode);

    }
 

    if(lower<=mid-1)
		 newnode->leftchild=Binarytree(list,lower,mid-1);
    else
          newnode->leftchild=NULL;
    if(mid+1<=upper)
         newnode->rightchild=Binarytree(list ,mid+1,upper);
    else
    	newnode->rightchild=NULL;
    	
    
    return (newnode);
    

}

void display(struct node* t,int level)
{
	
	int i;
	 if(t)
	 {
	 	
	 	display(t->rightchild,level+1);
	 	  cout<<"\n";
	 	for(i=0;i<level;i++)
	 	   cout<<" ";
	 	cout<<t->data;
	 	display(t->leftchild,level+1);
	 }
}


void preorder(struct node *n)
{
	if(n)
	{
		
		cout<<n->data<<" ";
		preorder(n->leftchild);
		preorder(n->rightchild);
		
	}
}	 	
	 

void inorder(struct node *n)
{
	
	if(n)
	{
		inorder(n->leftchild);
		cout<<n->data<<" ";
		inorder(n->rightchild);
	}
}


void postorder(struct node*n)
{
	
	if(n)
	{
		postorder(n->leftchild);
		postorder(n->rightchild);
		cout<<n->data<<" ";
	}
}

	
int main()
{
    int  list[100], number=0,info=0;

	struct node * d= new node;
	d=NULL;
    cin>>info;
	
	while(info)
	{
	    list[number++]=info;
		cin>>info;
	}
	
	number--;

	cout<<"Number of element in the list is :"<<number<<"\n";
	d=Binarytree(list,0,number);

	display(d,1);
	cout<<"\n";

	cout<<"Preorder Traversal"<<"\n";
	preorder(d);
	cout<<"\n";

	cout<<"inorder Traversal"<<"\n";
	inorder(d);
	cout<<"\n";

	cout<<"postorder Traversal"<<"\n";
	postorder(d);
	
    return 0;
}
