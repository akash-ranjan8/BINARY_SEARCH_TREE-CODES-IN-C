#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void create(struct node **root,int d)
{ struct node *new,*p;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->left=NULL;
  new->right=NULL;
  p=*root;
  if(*root==NULL)
  { *root=new;
  }
  else
  { struct node *curr;
    curr=*root;
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
void display(struct node *root)
{ if(root!=NULL)
  { printf("%d\t",root->data);
    display(root->left);
    display(root->right);
  }
}
int search(struct node *root,int k)
{ struct node *curr;
  curr=root;
  while(curr!=NULL)
  { 
    if(curr->data>k)
    { curr=curr->left;
    }
    else if(curr->data<k)
    { curr=curr->right;
    }
    else
    { return 1;
      break;
    }
  }
    
}
void main()
{ struct node *root=NULL;
  int n,i,m,e;
  printf("enter the no. of nodes wanted to create\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&m);
    create(&root,m);
  }
  display(root);
  printf("\n");
  printf("\nenter data to be searched\n");
  scanf("%d",&e);
  int k=search(root,e);
  if(k==1)
  { printf("\n found\n");
  }
  else
  { printf("\n not found\n");
  }
}
