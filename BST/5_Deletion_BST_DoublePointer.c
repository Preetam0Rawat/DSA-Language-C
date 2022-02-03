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


struct tree *inorder_successor(struct tree *root)                      //Now to find the left most node
{
   while(root->left != NULL)
     root = root->left;

    return root;
}

// struct tree *inorder_predecessor(struct tree *root)
// {
//    while(root->right != NULL)
//      root = root->right;

//     return root;
// }


void delete_node(struct tree **rt, int val)
{
    if(*rt == NULL)
       return NULL;

    else if( val < (*rt)->data)
          delete_node(&(*rt)->left, val);  
    
    else if(val > (*rt)->data)
          delete_node(&(*rt)->right, val); 
    
    else    // Found the value to be deleted
    {
         if((*rt)->left == NULL && (*rt)->right == NULL)          //CASE 1: Data found at leaf node.
             {
               free(rt);
               return NULL;
             }

          else if((*rt)->left == NULL)                         //CASE 2: Data found atnode with only 1 child.
          {
              struct tree *temp;
              temp = rt;
              rt = (*rt)->right;
              free(temp);
              return rt;    
          }
          else if((*rt)->right == NULL)
          {   
              struct tree *temp;
              temp = rt;
              rt = (*rt)->left;
              free(temp);
              return rt;
          }

          else                                              //CASE 3: Data found at node with 2 children. 
          {
             struct tree * temp = inorder_successor((*rt)->right);    //Successor is basically left most node in right sub tree, that is why rt->right(right subtree) is sent.
             (*rt)->data = temp->data;
             delete_node(&(*rt)->right, temp->data);       //Deleting the duplicte node

        /*----------------PREDECESSOR METHOD-------------------*/
            //  struct tree * temp = inorder_predecessor(rt->left);                          
            //  rt->data = temp->data;
            //  printf("temp is %d", temp->data);
            //  rt->left = delete_node(rt->left, temp->data);
        /*----------------------------------------------------*/       
          }
    }

    return rt;
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
    root = InsertInTree(root, 13);
    root = InsertInTree(root, 25);   
    root = InsertInTree(root, 18);

    
    printf("Elements in the tree array(Inorder Traverse) :\n");
    Inorder_Traverse(root);

    delete_node(&root, 15);

     printf("\n\nElements in the tree array(Inorder Traverse) :\n");
    Inorder_Traverse(root);

}


