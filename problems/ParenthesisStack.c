#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10
typedef struct{
  int top;
  char elem[MAX];
}ArrayStack;

void initStack(ArrayStack *A);
bool isFull(ArrayStack A);
bool isEmpty(ArrayStack A);
void push(ArrayStack *A, char x);
void pop(ArrayStack *A);
char top(ArrayStack A);
void displayStack(ArrayStack A);
bool validParenthesis(ArrayStack A, char *string);

int main(){

char string[] = "(";
ArrayStack L;
initStack(&L);

printf("%d",validParenthesis(L, string));


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

bool validParenthesis(ArrayStack A, char *string){
  
  int ctr;
  bool retval = true;
  for(ctr = 0; ctr < strlen(string); ctr++){
    char curr = string[ctr];
    if(curr == '(' || curr == '{' || curr == '['){
      push(&A, curr);
    }else if(curr == ')' || curr == '}' || curr == ']'){

      if(isEmpty(A)){
        retval = false;
      }
      if(curr == top(A) + 1 || curr == top(A) + 2){
        pop(&A);
      }else {
        retval = false;
      }
        
    }
  }
  return retval && isEmpty(A);
}
