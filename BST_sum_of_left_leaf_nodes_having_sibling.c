#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void create(struct node **root,int d)
{ struct node *new,*p,*curr;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->left=NULL;
  new->right=NULL;
  if(*root==NULL)
  { *root=new;
  }
  else
  { curr=*root;
    while(curr!=NULL)
    { p=curr;
      if(curr->data>new->data)
      { curr=curr->left;
      }
      else
      { curr=curr->right;
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
{ if(root)
  { printf("%d\t",root->data);
    display(root->left);
    display(root->right);
  }
}
bool isLeaf(struct node *root)
{ if(root==NULL)
  { return false;
  }
  else if(root->left==NULL && root->right==NULL)
  { return true;
  }
  return false;
}
int sumofleafnodes(struct node *root)
{ int sum=0;
  if(root==NULL)
  { return 0;
  }
  else
  { if(root!=NULL)
    { if(isLeaf(root->left) && root->right!=NULL)
      { sum+=root->left->data;
      }
      else
      { sum+=sumofleafnodes(root->left);
      }
      sum+=sumofleafnodes(root->right);
    }
    return sum;
  }
}
int main()
{ int n,e;
  struct node *root=NULL;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the value\n");
    scanf("%d",&e);
    create(&root,e);
  }
  display(root);
  int k=sumofleafnodes(root);
  printf("sum of left leaf nodes :%d\n",k);
  return 0;
}

   
