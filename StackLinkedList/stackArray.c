#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct{
  
  char elem[MAX];
  int top;
}ArrayStack;


void initStack(ArrayStack *A);
void push(ArrayStack *A, char x);
void pop(ArrayStack *A);
char top(ArrayStack A);
bool isEmpty(ArrayStack A);
bool isFull(ArrayStack A);
void displayStack(ArrayStack A);
void insertAtBottom(ArrayStack *A, char x);
void sortStack(ArrayStack *A, char x);

int main(){

  ArrayStack L;
  initStack(&L);
  push(&L, 'a');
  push(&L, 'c');
  displayStack(L);
  push(&L, 'd');
  displayStack(L);
  printf("pop:\n");
  pop(&L);
  displayStack(L);
  printf("insertAtBottom:\n");
  insertAtBottom(&L, 'z');
  displayStack(L);
  printf("Sort:\n");
  sortStack(&L, 'l');
  displayStack(L);
}

void initStack(ArrayStack *A){

  A->top = MAX;
}
bool isFull(ArrayStack A){

  return (A.top == 0)? true : false;
}
bool isEmpty(ArrayStack A){

  return (A.top == MAX)? true : false;
}
void push(ArrayStack *A, char x){

  if(!isFull(*A)){
    A->elem[--A->top] = x;
    
  }
}

void pop(ArrayStack *A){

  if(!isEmpty(*A)){
    A->top++;
  }
}

char top(ArrayStack A){

  return (!isEmpty(A))? A.elem[A.top] : '\0';
}

void displayStack(ArrayStack A){
  
  for(;!isEmpty(A); pop(&A)){
    printf("elem: %c\n", top(A));
  }
}

void insertAtBottom(ArrayStack *A, char x){

  ArrayStack temp;
  initStack(&temp);
  for(;!isEmpty(*A); pop(A)){
    push(&temp, A->elem[A->top]);
  }
  push(A, x);
  for(;!isEmpty(temp); pop(&temp)){
    push(A, temp.elem[temp.top]);
  }

}

void sortStack(ArrayStack *A, char x){

  char temp;
  ArrayStack tempStack;
  initStack(&tempStack);

  for(; !isEmpty(*A);){
    temp = top(*A);
    pop(A);
    while(!isEmpty(tempStack) && top(tempStack) > x){
      push(A, top(tempStack));

      pop(&tempStack);
    }
    
  }
  for(;!isEmpty(tempStack);pop(&tempStack)){
    push(A, top(tempStack));
  }
}

