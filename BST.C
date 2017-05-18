#include<stdio.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
	}*root=NULL;
void insert(struct node *p,struct node *temp)
{
    //printf("temp data is %d and p data is %d\n",temp->data,root->data);
    if(temp->data<=p->data)
      {
	if(p->left==NULL)
	  {/*printf("on left");*/p->left=temp;return;}
	else
	  insert(p->left,temp);
      }
    if(temp->data>p->data)
      {
	if(p->right==NULL)
	  {/*printf("on right");*/p->right=temp;return;}
	else
	  insert(p->right,temp);
      }

}

void display(struct node *p)
{
  if(p==NULL)return;
  printf("%d\t",p->data);
  display(p->left);
  //printf("%d\t",p->data);
  display(p->right);
  //printf("%d\t",p->data);
}
struct node* get_node(){struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node));
			temp->left=NULL;
			temp->right=NULL;
			return temp;
			}
int main()
{
  struct node *temp;
  int ch,i,n=0;
  char c='y';
  clrscr();
  do{
  printf("Press 1 to insert\nPress 2 for displaying\n");
  scanf("%d",&ch);
  switch(ch)
  { case 1 :for(;n!=-1;)
	    {
	     printf("enter the number you wish to insert\n");
	     scanf("%d",&n);
	     if(n==-1)break;
	     temp=get_node();
	     temp->data=n;
	     if(root==NULL){/*printf("on null");*/root=temp;}
	     else
	     insert(root,temp);
	     }
	     break;
    case 2 : display(root);
	     break;
  }
  printf("press y to continue and n to halt\n");
  c=getch();
  }while(c=='y');
	return 0;
}