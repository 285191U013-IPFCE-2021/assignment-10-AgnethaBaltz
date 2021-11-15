#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//Function to keep track of the data of the children. Running to the last child
int min_right (struct tree_node *t){
  struct tree_node *temp = t;
  while(t->left != NULL){
    temp = t->left;
  }
  return temp->item;
}

// Insert item x into the tree t
struct tree_node * Insert (int x, struct tree_node *t)
{
  /*Creating a new tree node, that consists of the item x,
  and its left and right child points at NULL
  */
  struct tree_node *item_x = malloc(sizeof(struct tree_node));
  item_x->item = x;
  item_x->left = NULL;
  item_x->right = NULL;
  /*If the tree is empty, insert the tree node 
  which consists of the item to be inserted*/
  if(t == NULL) {
    return item_x;
  }
  /*Comparing the item x with the current tree item.
  If it is greater then we look at the right child and keep comparing it. 
  This is accomplished with recursion.
  If it is smaller then we look at the left child and keep comparing it.*/
  if(x > t->item) {
    t->right = Insert(x, t->right);
  } else {
    t->left = Insert(x, t->left);
  }  
  //Return the new tree with the number to be be inserted
  return t;
}

// Remove one item from the tree t
struct tree_node * Remove (int x, struct tree_node *t)
{
 //If the tree is empty, then return the root
  if(t == NULL) {
    return t;
  } 
  /*First we need to search for the item that shall be removed.
  */
  if(x > t->item){
    t->right = Remove(x, t->right);
  } else if(x < t->item){
      t->left = Remove(x, t->left);
  } else { //(x = t->item) 
      /*If we found the item, there can be three cases:
      1. The item hasn't got any children
      2. The item has just one child
      3. The item has two children, which again can have children
      */
     //Has no children, which means the item to be removed is in last place
      if(t->left == NULL && t->right == NULL){
        //Freeing memory
        free(t);
        //The previous item should now be the last element. 
        return NULL;
        //Has got just one child
      } else if (t->right == NULL || t->left == NULL) {
          //Create new temporary node, that keeps track of the following nodes, if there are any
          struct tree_node *temp_t = NULL;
          //Depending on which child is missing the other, which is the only child, is stored in the temporary node
          if(t->right == NULL){
            temp_t = t->left;
          } else {
              temp_t = t->right;
            }
            //Freeing memory
            free(t);
            //Move the child up
            return temp_t;
      } else { //Has two children
      /*For this case we need to keep track of the two children.
      Moving the largest number out of both children up.
      Removing the searched item.
      */
          int min_largest = min_right(t->right);
          t->item = min_largest;
          t->right = Remove(t->item, t->right);
        }
    }    
  //Returning the new tree 
  return t;
}

// Return true if the tree t contains item x. Return false otherwise.
int Contains (int x, struct tree_node *t)
{
  //If the tree is empty return false
  if(t == NULL) {
    return 0;
  }
  /*If the first item in the tree is the element that is searched for, 
  return true*/
  if(t->item == x){
    return 1;
  } 
  /*If the searched element is smaller than the first tree item, 
  then we go into the left direction and check each item for x*/
  if(x < t->item){
    return Contains(x, t->left);
    /*If the searched element is greater than the first tree item,
    then we go into the right direction and check each item for x */
  } else { //(x > t->item)
    return Contains(x, t->right);
  }
}

// Create an empty tree
struct tree_node * Initialize (struct tree_node *t)
{
  //Returning an empty tree
  return t = NULL;
}

// Test if empty
int Empty (struct tree_node *t)
{
  //If the tree doesn't consists of anything it is empty
  if(t == NULL) {
    return 1;
  }
  //If the tree isn't empty return false
  return 0;
}

// Test if full
int Full (struct tree_node *t)
{
  /*The tree is build of linked lists, this means
  that a new leaf/node can be added into the tree
  */   
    return 0;
}
