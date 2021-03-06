#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void create(struct node **root,int d)
{ struct node *p,*new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->left=NULL;
  new->right=NULL;
  p=*root;
  if(*root==NULL)
  { *root=new;
  }
  else
  { struct node *curr=*root;
    while(curr!=NULL)
    { p=curr;
      if(new->data>curr->data)
      { 
        curr=curr->right;
      }
      else
      { 
        curr=curr->left;
      }
    }
    if(new->data>p->data)
    { p->right=new;
    }
    else
    { p->left=new;
    }
  }
}
void display(struct node *root)
{ 
  if(root!=NULL)
  { printf("%d\t",root->data);
    display(root->left);
    display(root->right);
  }
}
int main()
{ int n,i,k;
  struct node *root=NULL;
  printf("no. of nodes you want\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(&root,k);
  }
  display(root);
  return 0;
}
  
  
