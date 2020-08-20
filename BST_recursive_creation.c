#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
   struct node *left;
   struct node *right;
};
struct node *new_node(int d)
{ struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return(new);
}
struct node *create(struct node *root,int k)
{  if(root==NULL)
    { return(new_node(k));
    }
    else if(root->data>k)
    { root->left=create(root->left,k);
    }
    else
    { root->right=create(root->right,k);
    }
    return(root);
}
int inorder(struct node *root)
   { if(root!=NULL)
      { 
         inorder(root->left);
         printf("%d\t",root->data);
         inorder(root->right);
       }
      
     }
int main()
{ struct node *root=NULL;
  int k,n,i,e;
  printf("enter the first node data\n");
  scanf("%d",&e);
  root=create(root,e);
  printf("enter the no. of nodes after creation of first node\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(root,k);
  }
  inorder(root);
  return 0;
}
  
