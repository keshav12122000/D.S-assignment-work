#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
        char data[100];
        struct node *left,*right;   //left and right pointer
        int height1; // store height of each node
}node;
//function is used to rotate left
node * rotateleft(node *x)
{
        node *y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->height1=height(x);
        y->height1=height(y);

        return(y);
}
node * rotateright(node *x)
{
        node *y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->height1=height(x);
        y->height1=height(y);
        return(y);
}
//calculate height of tree
int height(node *temp)
{
        int left1,right1;
        if(temp==NULL)
                return(0);

        if(temp->left==NULL)
                left1=0;
        else
                left1=1+temp->left->height1;

        if(temp->right==NULL)
                right1=0;
        else
                right1=1+temp->right->height1;

        if(left1>right1)
                return(left1);

        return(right1);
}
node* RR(node *temp)//RR Rotatioj
{
    temp=rotateleft(temp);
    printf("RR rotation done\n");
    return(temp);
}
node* LL(node *temp)//LL Rotatioj
{
    temp=rotateright(temp);
    printf("LL rotation done\n");
    return(temp);
}
node* LR(node *temp)//LR Rotatioj
{
    temp->left=rotateleft(temp->left);
    printf("RL rotation done\n");
    temp=rotateright(temp);
    printf("RR rotation done\n");
return(temp);
}
node* RL(node *temp)//RL Rotatioj
{
    temp->right=rotateright(temp->right);
    printf("RR rotation done\n");
    temp=rotateleft(temp);
    printf("RL rotation done\n");
return(temp);
}
int balancefactor(node *temp)
{
   int left1,right1;
   if(temp==NULL)
    return(0);
   if(temp->left==NULL)
    left1=0;
else
    left1=1+temp->left->height1;
    if(temp->right==NULL)
    right1=0;
else
    right1=1+temp->right->height1;
    return(left1-right1);
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
    inorder(temp->left);
    printf("data=%s(Bf=%d)",temp->data,balancefactor(temp));
    inorder(temp->right);
    }
}
node * insert(node *temp,char x[100])
{
    if(temp==NULL)
{
    temp=(node*)malloc(sizeof(node));
    strcpy(temp->data,x);
    temp->left=NULL;
    temp->right=NULL;
}
else
{
    if(strcmp(x,temp->data)>0)               // insert in right subtree
    {
    temp->right=insert(temp->right,x);
    int factor=balancefactor(temp);
    if(factor==-2)
    if(strcmp(x,temp->right->data)>0)
    temp=RR(temp);  // performing right right rotation
    else
    temp=RL(temp);  //performing right left rotation
     }
else
    {
    if(strcmp(x,temp->data)<0)   //insert in left subtree
{
    temp->left=insert(temp->left,x);
    if(balancefactor(temp)==2)
    if(strcmp(x,temp->left->data)<0)
    temp=LL(temp);    //performing left left rotation
else
    temp=LR(temp);    //performing left right rotation
}
    }
}
temp->height1 = height(temp);
return(temp);
}
int main()
{
node *root=NULL;
struct node *c;
int x,n,i,flag;
char k[100];
for(int t=1;t>0;t++)
	{
        printf("\n1)Create a tree:");
        printf("\n2)Print tree:");
        printf("\n3)Exit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&flag);
        if(flag==3)
    break;
else
    {     //making conditions!
		switch(flag)
        {
            case 1: printf("\nEnter no. of WORDS:");
                    scanf("%d",&n);
                    printf("\nEnter the value of data:");
                    root=NULL;
                    for(i=0;i<n;i++)
            {
                    scanf("%s",&k);
                    root=insert(root,k);
                    c=root;
            }
    break;
            case 2: printf("\n INORDER SEQUENCE:\n");
                    inorder(root);
                    printf("\n");
    break;
         }
    }
}
int z;
printf("insert new element");
scanf("%d",&z);
if(z==1)
{
    scanf("%s",&k);
    root=insert(root,k);
    inorder(root);
}
else
    printf("Exit the program");
    return 0;
}

