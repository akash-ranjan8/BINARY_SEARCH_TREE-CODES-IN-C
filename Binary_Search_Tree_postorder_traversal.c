#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void create(struct node **root,int d)
{ struct node *new,*curr,*p;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->left=NULL;
  new->right=NULL;
  p=*root;
  if(*root==NULL)
  { *root=new;
  }
  else
  { curr=*root;
    while(curr!=NULL)
    { p=curr;
      if(new->data>curr->data)
      { curr=curr->right;
      }
      else
      { curr=curr->left;
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
void postorder(struct node *root)
{ if(root!=NULL)
  { 
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
  }
}
int main()
{ int n,i,k;
  struct node *root=NULL;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(&root,k);
  }
  postorder(root);
  return 0;
}
