#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *r,*l;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("malloc fails:\n");
        exit(0);
    }
    return x;
}
NODE createbst(int item,NODE root)
{
    NODE temp,cur,prev;
    temp=getnode();
    temp->info=item;
    temp->l=temp->r=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        cur=((item>cur->info)?cur->r:cur->l);
    }
    if(item<prev->info)
    {
        prev->l=temp;
    }
    else
    {
        prev->r=temp;
        return root;
    }
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf("%d\t",root->info);
        inorder(root->r);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->l);
        preorder(root->r);
    }
}
void postorder(NODE root)
{
    if(root != NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d\t",root->info);
    }
}

void main()
{
    NODE root=NULL;
    int choice,item;
    for(;;)
    {
        printf("\n `Enter 1.Insertbst\n 2.preorder\n 3.postorder\n 4.inorder\n 5.Exit \n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to inserted :\n");
                   scanf("%d",&item);
                   root=createbst(item,root);
                   break;
            case 2:preorder(root);
                   break;
            case 3:postorder(root);
                   break;
            case 4:inorder(root);
                   break;
            case 5:exit(0);
                   break;
         default:printf("lol");
        }


    }
}
