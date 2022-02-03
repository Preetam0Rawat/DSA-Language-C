#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};
 struct tree *InsertInTree(struct tree *rt, int val)
{   
    if (rt == NULL)
    {
        struct tree *node = (struct tree*)malloc(sizeof(struct tree));
        node->data = val;
        node->left = NULL;
        node->right = NULL;

        rt =  node;// "return node" is also correct
    }

    else
    {
      if( val < rt->data)
         rt->left =  InsertInTree(rt->left, val);
      else
         rt->right = InsertInTree(rt->right, val);
    }

    return rt;
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

    root = InsertInTree(root, 10);
    root = InsertInTree(root, 8);
    root = InsertInTree(root, 15);
    root = InsertInTree(root, 5);
    root = InsertInTree(root, 20);
    root = InsertInTree(root, 9);   
    root = InsertInTree(root, 14);

    
  
     printf("\nElements in the tree array(Preorder Traverse) :\n");
    Preorder_Traverse(root);
  
    printf("\n\nElements in the tree array(Inorder Traverse) :\n");
    Inorder_Traverse(root);

    printf("\n\nElements in the tree array(Postorder Traverse) :\n");
    Postorder_Traverse(root);

}


