# Challenges
# Double-linked list with C

If I want to check my program, I got to get a IDE. Or before that, I should check it again.
Abstraction：
* I decided to look at direct tutorial to shorten hours spending. But I do admit that thinking independent is undoundtly important.
* As saying, linked list is a good example of dynamic data struture.
* Lists and arrays are two different types of allocators.


Method:
* new // start the data structure correctly
* insert // add a new data to the list
* find  // check if a particular data is in the list
* delete  // remove a particular data from the list
* quit   // shut down the program correctly

Cue:
* Pointers
* Have you consider a simplier version of this question? Single-linked list.
* Destint passing pointers and value being pointed
* Look back to the concept of **recursion**.
* Destinct "." and "->"
* Thinking carefully if you need a node object, or a list object.


Desription:
* a kind of data structure, saving strings with undetermined length.
* Pointer that points to forward, named Pf
* Pointer that points to backward, named Pb
* data itself
* Additional feature: a counter that indiacte the position in the sequence.

Let's look into codes of single-linked list to set sail.
```
/* Fistly, what we define is not the list itself, but its component: node */
/* Second, seems to be a little tricky, what type of pointer should nodes conclude? */

/* printf fuction in this header */
#include <stdio.h>
/* malloc function in this header */
#include <stdlib.h>

/* A recursion struture */

typedef struct Node{
  int data;
  struct Node * next;
}node;

/* a list header will bring a lot of convinience */
typedef struct List_s{
  struct node * head;  
}List;

void init_list(List list){
  list.head = NULL;
}

/* define a function for printing list */

void print_list(node * head){
  node * current = head;
  while(current != NULL){
    printf("%d\n",current->data);
    current = current->next;
  }
}

/* define a function to add item at the end of the list */

/* what if push function got a null list, it may cause some trouble */

void push2(node * head, int data){
  node * current = head;
  while(current->next != NULL){
    /* locate the last node of the list */
    current = current->next;
  }
  current->next = malloc(sizeof(node));
  /* malloc may fail, so it's necessary to check */
  if (current->next == NULL){
    return 1;
  }
  current->next->data = data;
  current->next->next=NULL;
}

/*it takes a time to overwrite */
void push(List *list,node data){


}

/* deine a function pop, to remove the first item from the list */
/* passing a pointer to poiter, indicating that the function can change the Ordinal pointer */
/* return the value being poped */

/* more than a way to code, always need restructure */

int pop2(node ** head){
  int retval = -1;
  node * after_head = NULL;
  if (*head ==NULL){
    return -1;
  }

  after_head = (*head)->next;
  retval = (*head)->data;
  free(*head);
  *head =  after_head;
  return retval;  
}

/* try another version of pop using list*/
void pop(List * list ){
  node * head = list->head;
  if(list){
    list->head = head->next;
    head->next = NULL;
  }

}

int main(){

  /* head is not a node, but a local pointer to the list */

  /* if head is NULL, what if head->next? */

  /* this initialization may be more completed. */

  init_list(list);

  push(list,1);

  push(head,2);

  push(head,3);

  print_list(head);

  pop(head);

  print_list(head);

  return 0;
}


```

Path:
1. First of all, a starting point. Name a pointer "Head", refer to the beginning of the data.
2. In addition, an end point is needed. named "End". initially, Head and End refer to the same address.
2. Then, the first data input. There needs to be a pointer, to indicate the address of the data in the heap space. Counter 1. Pf[1] should points to the end of the data chain, as to connect with it. Say, `Pf[1] = End` .Then the end of the chain has to be updated. `End = `

State Analysis:
1. State 0
A starting point, as the entrance of the data list. Name "Head", points to NULL. And the end mark, name "Tail".
2. State 1
input first data, name "Data[1]", which is a pointer.
3. State 0 to 1
The trick is, Pointer "Head" can points to Data[1], say `Head = Data[1]`. Then, `Tail = Data[1]`
4. State 2
Here comes the problem. Firstly, second data, named "Data[2]". How to link it to Data[1], thus form a chain? Say, there is something, if Sth in case, then `Sth = Data[2]`, which acts like step 3 does. Let's look further, we got `tail = Data[2]`. The problem remain: how to link data? The trick must be pointer, but how to use it? Let's say, `Pf[1]=Data[2]`. In this case, it indicates that, from Data[1], points forward, is Data[2]. Sounds reasonable. From this point of view, it's easy to go one more step, `Pb[2]=Data[1]`, indicates that Data[2] points backward is Data[1], also sounds great. though we still don't know how to fullfill it, but it must be true.
5. State 3
The problem now is transform into, how to combine Data, Pf, and Pb. Obviously, it doesn't matter, at all.

Object:
* Head
* End
* Counter i
* Pf[i]
* Pb[i]
* Data[i]

prototype as below:

```
typedef struct{
  cahr * Pf;
  char * Pb;
  char * Data;
}DoubleLinkedList;

Statement{
  dim Head as Pointer
  dim Tail as Pointer
  dim Data[] as Pointer
  dim Pf[] as Pointer
  dim Pb[] as Pointer
  dim Counter as long
  dim FindValue as Pointer
}

Method New{
  Head = NULL
  Tail = NULL  
  Counter = 0
}

Method Insert{
  if Counter = 0 then
    Head = Data[Counter]
  end if
  Counter=Counter+1
  Data[Counter]=Input
  Pf[Counter-1] = Data[Couter]
  Pb[Counter]=Data[Counter-1]
  Tail = Data[Counter]
}

Method Find{
  FindValue = input
  for i = 1 to counter
    if FindValue == Data[Counter] Then
      return Counter
    end if
    i = i + 1
  next i
  return 0
}

Method Delete{
  dim Ind as long
  Ind = Find(Input)
  if Ind = 0 Then
    return Error
  else
    Pf[Ind+1] = Pf[Ind]
    Pb[Ind-1]=Pb[Ind]
    Pf[Ind]= NULL
    Pb[Ind]= NULL
    Data[Ind]=NULL
  end if

  Method Quit{
    Head = NULL
    Tail = NULL
  }
}
```

A test file maybe as following:
```
int main()
  dim i as integer
  printf("Welcome to D.L.L. (DoubleLinkedList) Written in C. Please enter a number below, show me what you want:")
  do{
    printf("1 Input Data", \n ,"2 Find Data", \n , "3 Delete Data", \n, "0 Quit",\n)
    i = inputbox()
    select case i
      i = 1:
        Printf("Please input a Data ")
        Intert(inputbox())

      i = 2:
        printf("What do you want to find?")
        Find(inputbox())

      i = 3:
       pringf("What data you want to delete?")
       Delete(inputbox())

      i = 0:
       printf("Goodbye")
       exit

      else:
      printf("You have input wrong data, please try it again.")

    end select  


  }
  loop



```

I really want to create a testing bot to check my program automatically.

Obviously, I'm not get there.  A lot of works still needed. But how to go a step more forward?

Checking list:
- [ ] Memory Leak.
 Have you release every single pointer after you using it? If I got a set of pointers, before quit I can do a loop do check if every pointer is NULL. So the question transform into, how I got a set of pointers, or , [**how to create a set of paricular data type?**](HowToCreateSetOfDataType.md)

- [ ] Data Type Matchment
  Have you ever check each assignment is with correspond data type?

  Your prototype hasn't finished yet.

  The next part I should try to transform my prototype into runnable C programs, which require me coding in C. So, it's time to [**ReviewC**](ReviewC.md)
