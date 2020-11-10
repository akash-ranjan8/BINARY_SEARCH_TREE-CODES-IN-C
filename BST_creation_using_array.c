#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void insert(struct node **root,int d)
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
   printf("inserted\n");
}
void display_inorder(struct node *t)
{
 
     if(t)
     {display_inorder(t->left);
      printf("%d\t",t->data);
      display_inorder(t->right);
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
int main()
{ int n,i,k;
  struct node *root=NULL;
  printf("\nenter the no. of elements\n");
  scanf("%d",&n);
  int a[n];
  printf("\nenter the element to inserted in BST\n");
  for(i=0;i<n;++i)
  { scanf("%d",&a[i]);
    insert(&root,a[i]);
  }
  printf("\nDisplaying the elememts\n");
  display_inorder(root);
  printf("\nenter the element to be searched\n");
  scanf("%d",&k);
  int m=search(root,k);
  if(m==1)
  { if(k>a[0])
    { printf("element found and it is present in right subtree\n");
    }
    else
    { printf("element found and it is present in left subtree\n");
    }
  }
  else
  { printf("element not found\n");
  }
  return 0;
}
  
  
    
