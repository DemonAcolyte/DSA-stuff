#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

  char elem;
  struct node *link;
}*Stack;


void initStack(Stack *A);
bool isEmpty(Stack A);
void pop(Stack *A);
void push(Stack *A, char x);
char top(Stack A);
void displayStack(Stack A);

int main(){
  
  Stack L;

  initStack(&L);
  push(&L, 'c');
  push(&L, 'd');
  push(&L, 'a');
  displayStack(L);
  printf("Pop\n");
  pop(&L);
  displayStack(L);
}
void initStack(Stack *A){

  *A = NULL;
}

bool isEmpty(Stack A){
  
  return(A == NULL)? true : false;
}

void pop(Stack *A){

  Stack temp;

  if(!isEmpty(*A)){

    temp = *A;
    *A = temp->link;
    free(temp);
  }
}

void push(Stack *A, char x){

  Stack newNode = (Stack)malloc(sizeof(struct node));
  if(newNode != NULL){
    newNode->elem = x;
    newNode->link = *A;
    *A = newNode;
  }
}

char top(Stack A){

  return (isEmpty(A))? '\0' : A->elem;
}

void displayStack(Stack A){

  Stack temp = (Stack)malloc(sizeof(struct node));
  initStack(&temp);
  
  if(!isEmpty(A)){

    for(; !isEmpty(A); pop(&A)){
      push(&temp, A->elem);
      printf("elem: %c\n", top(temp));
    }

    for(; !isEmpty(temp); pop(&temp)){
      push(&A, temp->elem);
    }
  }

}
