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
   int preorder(struct node *root)
   { if(root!=NULL)
      { printf("%d\t",root->data);
         preorder(root->left);
         preorder(root->right);
       }
      
     }
 int inorder(struct node *root)
   { if(root!=NULL)
      { 
         inorder(root->left);
         printf("%d\t",root->data);
         inorder(root->right);
       }
      
     }
  int postorder(struct node *root)
   { if(root!=NULL)
      { 
         postorder(root->left);
         postorder(root->right);
         printf("%d\t",root->data);
       }
     
     }
     struct node *minvalue(struct node *root)
     { struct node *curr=root;
        while(curr!=NULL&&curr->left!=NULL)
        { curr=curr->left;
        }
        return (curr);
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
          return (root);
     }
          
void main()
{ struct node *root=NULL;
   int ele,a,b,m;
   printf("enter the first element\n");
   scanf("%d",&ele);
   root=create(root,ele);
   int flag=0;
   while(flag!=1)
   { printf("\nenter your choice\n");
      scanf("%d",&a);
      switch(a)
      { case 1: printf("1.CREATION\n");
                     printf("enter the element\n");
                     scanf("%d",&b);
                     create(root,b);
                     break;
         case 2: printf("2.INORDER TRAVERSAL\n");
                     inorder(root);
                     break;
         case 3: printf("3.PREORDER TRAVERSAL\n");
                     preorder(root);
                     break;
         case 4:printf("4.POSTORDER TRAVERSAL\n");
                    postorder(root);
                    break;
         case 5: printf("5.DELETION\n");
                     printf("enter the data to be deleted\n");
                     scanf("%d",&m);
                     root=delete(root,m);
                     break;
         default: flag=1;
                       break;
         }
       }
   }
