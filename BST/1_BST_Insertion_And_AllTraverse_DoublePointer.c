#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};
void InsertInTree(struct tree **rt, int val)
{
    if (*rt == NULL)
    {
        struct tree *node = (struct tree*)malloc(sizeof(struct tree));
        node->data = val;
        node->left = NULL;
        node->right = NULL;

        *rt = node;
    }

    else
    {
      if( val < (*rt)->data)
           InsertInTree(&(*rt)->left, val);
      else
           InsertInTree(&(*rt)->right, val);
    }
}

void Preorder_Traverse(struct tree *rt)         // N-L-R
{
  if(rt == NULL)
    return;
  else
  {
     printf("%d  ", rt->data);
     Preorder_Traverse(rt->left);
     Preorder_Traverse(rt->right);         
  }
}

void Inorder_Traverse(struct tree *rt)           // L-N-R
{
  if(rt == NULL)
    return;
  else
  {
     Inorder_Traverse(rt->left);
     printf("%d  ", rt->data);
     Inorder_Traverse(rt->right);         
  }
}

void Postorder_Traverse(struct tree *rt)          // L-R-N
{
  if(rt == NULL)
    return;
  else
  {
     Postorder_Traverse(rt->left);
     Postorder_Traverse(rt->right);   
     printf("%d  ", rt->data);
 }
}


void main()
{
    struct tree *root;
    root = (struct tree*)malloc(sizeof(struct tree));
    root = NULL;
    InsertInTree(&root, 10);
    InsertInTree(&root, 8);
    InsertInTree(&root, 15);
    InsertInTree(&root, 5);
    InsertInTree(&root, 20);
    InsertInTree(&root, 9);   
    InsertInTree(&root, 14);

    printf("\nElements in the tree array(Preorder Traverse) :\n");
    Preorder_Traverse(root);
  
    printf("\n\nElements in the tree array(Inorder Traverse) :\n");
    Inorder_Traverse(root);

    printf("\n\nElements in the tree array(Postorder Traverse) :\n");
    Postorder_Traverse(root);

    
}
