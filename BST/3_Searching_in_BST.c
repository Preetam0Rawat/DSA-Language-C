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

struct tree *search(struct tree *rt, int key)
{
     if(rt == NULL)
        return NULL;

     else if(rt->data == key)
            return rt;

    else if(key < rt->data)
            return search(rt->left, key);
    else 
            return search(rt->right, key);
  
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
  
    printf("Elements in the tree array(Inorder Traverse) :\n");
    Inorder_Traverse(root);
    
    struct tree *n;
    n = search(root, 15);
    if(n == NULL)
       printf("\nData not found in the BST  :(\n");
    else
       printf("\n%d found in the BST :)\n", n->data);
}


