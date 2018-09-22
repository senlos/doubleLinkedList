/* Version 2 of Double linked list in C */

/*I try to modify this file to check how to do version control */

/* Obviously I got two branches */

/* Still got much unknown, but not stopping me to go a step forward */

/* Fistly, what we define is not the list itself, but its component: node */
/* Second, seems to be a little tricky, what type of pointer should nodes conclude? */

/* printf fuction in this header */
#include <stdio.h>
/* malloc function in this header */
#include <stdlib.h>

/* A recursion struture */

/* This structure contains data body and a pointer to the next struture */

typedef struct Node{
  /* as an extention, data type can be differ from int to more complicated */
  int data;
  struct Node * next;
  /* got a type name, then can use it to define variable directly */
}node;


/* define a function for printing list */
/* notice that this function got a parameter and returns nothing,
but call another functions */
/* let's consider the parameter. a node type pointer object.
It means to copy the pointer to function input */
void print_list(node * head){
  /* diminish a movable Pointers */
  node * current = head;
  /*starting from the head */
  /* till it got the end */
  while(current != NULL){
  /* print out the data then move to the next node */
    printf("%d\n",current->data);
    current = current->next;
  }
}

/* define a function to add item at the end of the list */

/* what if push function got a null list,
it may cause some trouble */

/* first stage, before check strucuture */



void push(node * head, int data){
  node * current = head;
  while(current->next != NULL){
    /* locate the last node of the list */
    current = current->next;
  }
  /* when this points to null */
  /* allocate a storage for it */
  current->next = malloc(sizeof(node));
  /* malloc may fail, so it's necessary to check */
  if (current->next == NULL){
  /* but how if tryint to return in a void function */
    return 1;
  }
/* normal action of assigning value to variables in node */
  current->next->data = data;
  current->next->next=NULL;
}


/* deine a function pop, to remove the first item from the list */
/* passing a pointer to poiter, indicating that the function can change the Ordinal pointer */
/* return the value being poped */

/* more than a way to code, always need restructure */
/* pointer to pointer may complicate the struture,
and make it more difficult to extent */
/* pointer to pointer, make us capable to change the pointer */
int pop(node ** head){
  /* set default return value */
  int retval = -1;
  /* diminish a pointer to the object after head */
  node * after_head = NULL;
  if (*head ==NULL){
  /* distinguish between return value and function output.
  I see nothing */
    return -1;
  }
/* allocate the head node value before free*/
  after_head = (*head)->next;
  retval = (*head)->data;
  /* free the storage that pointers direct */
  free(*head);
  /* redirect the head pointer */
  *head =  after_head;
  return retval;
}

int main(){

  /* head is not a node, but a local pointer to the list */

  /* if head is NULL, what if head->next? */

  /* this initialization may be more completed. */

  push(list,1);

  push(head,2);

  push(head,3);

  print_list(head);

  pop(head);

  print_list(head);

  return 0;
}
