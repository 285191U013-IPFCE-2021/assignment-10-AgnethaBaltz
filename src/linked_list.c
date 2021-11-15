#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  //create space for a new node pointer
  node *p = malloc (sizeof (node));
  //new node has the value v
  p->value = v;
  /*if the current node is empty, the new node should point at null,
  otherwise the new node should point at the current node*/
  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  //returning a linked list
  return p;
}

/* free all nodes in the list p */
node *free_list (node * p)
{
  //initialise a new node pointer to the list p
  node *q = p;
  //freeing a node in the list by making a new node that takes the data from freed node 
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
  //return the new list
  return q;
}


/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    //Test cases are in main

  /*If the node p points at NULL or 
  if the node doesn't contain a number then NULL is printed*/
  if(p == NULL) {
    printf("NULL\n");
  } else {
    /*If p contains a value different to 0 then this value is printed, 
    or if p doesn't points at NULL
    */
    printf("%d, ", p->value);
  }
  //Continue printing the next value in the list
  print_list(p->next); 
}

// Add your code for excercise 2 
int sum_squares (node * p)
{
    /*If the node points at NULL or it doesn't contain a value,
    then don't calculate anything, just return */
    if(p == NULL){
      return 0;
    } 
    //if the last element in the list is reached
    if(p->next == NULL){
      return square(p->value);
    } else {
      /*as long as the end isn't reached yet keep multiplying and adding the next number.
      Using recursion */
      return(square(p->value) + sum_squares(p->next));
    }
}
// Add your code for excercise 3
/*General higher order funktion that takes a list and a pointer to the function 
which takes an int argument and returns an int*/
node *map (node * p, int (*f) (int))
{
    /*If the node doesn't consists of anything,
    then return*/
    if(p == NULL){
      return 0;
    } else {
      /*returning a list to which each node consists of an applied pointer to a function 
      which takes an int argument and returns an int
      */
      return (make_node((*f)(p->value), map(p->next, f)));
    }
}
//taking the power of 2
int square (int x)
{
  return x * x;
}

