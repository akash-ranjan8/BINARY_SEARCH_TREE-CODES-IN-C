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
int display(struct node *root)
{ 
   if(root!=NULL)
    { printf("%d\t",root->data);
      display(root->left);
      display(root->right);
    }
  
}
struct node *minvalue(struct node *root)
{ struct node *curr=root;
  while(curr!=NULL&&curr->left!=NULL)
  { curr=curr->left;
  }
  return curr;
}
struct node *delete(struct node *root,int k)
{ if(k<root->data)
  { root->left=delete(root->left,k);
  }
  else if(k>root->data)
  { root->right=delete(root->right,k);
  }
  else
  { if(root->left==NULL)
    { struct node *temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL)
    { struct node *temp=root->left;
      free(root);
      return temp;
    }
   struct node *temp=minvalue(root->right);
   root->data=temp->data;
   root->right=delete(root->right,temp->data);
  }
  return root;
}
void main()
{ struct node *ptr=NULL;
  int n,i,k,e;
  printf("enter the no. of nodes want to create\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(&ptr,k);
  }
  display(ptr);
  printf("\nenter the element to be deleted\n");
  scanf("%d",&e);
  ptr=delete(ptr,e);
  printf("\nResultant After Deletion is as follows..\n");
  display(ptr);
}
   
