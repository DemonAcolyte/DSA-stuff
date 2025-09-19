#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct{
  
  char elem[MAX];
  int count;
}ArrayList;


void initArray(ArrayList *A);
void insertFirst(ArrayList *A, char x);
void insertLast(ArrayList *A, char x);
void insertSorted(ArrayList *A, char x);
void insertSortedUnique(ArrayList *A, char x);

void deleteElem(ArrayList *A, char x);
void deleteFirst(ArrayList *A);
void deleteLast(ArrayList *A);
void deleteAllOccurences(ArrayList *A, char x);

void sort(ArrayList *A);
void swap(char *A, char *B);
void displayArray(ArrayList A);


void initArray(ArrayList *A){

  A->count = 0;
}
void insertFirst(ArrayList *A, char x){
  int ctr;
  if(A->count < MAX){
    for(ctr = A->count; ctr > 0; ctr--){
      A->elem[ctr] = A->elem[ctr - 1];
    }
    A->elem[0] = x;
    A->count++;
  }
}

void insertLast(ArrayList *A, char x){
  
  if(A->count < MAX){
    A->elem[A->count] = x;
    A->count++;
  }
}

void insertSorted(ArrayList *A, char x){

  int ctr, ndx;
  
  if(A->count < MAX){
    for(ctr = 0; ctr < A->count && A->elem[ctr] < x; ctr++){}
    
    if(ctr != A->count){
      
      for(ndx = A->count; ndx > ctr; ndx--){
        A->elem[ndx] = A->elem[ndx - 1];
      }
      A->elem[ctr] = x;
      A->count++;
    }
  }
}

void insertSortedUnique(ArrayList *A, char x){

  int ctr, ndx;

  if(A->count < MAX){

    for(ctr = 0; ctr < A->count && A->elem[ctr] < x; ctr++){}

    if(ctr == A->count ||  A->elem[ctr] != x){
      for(ndx = A->count; ndx > ctr; ndx--){
        A->elem[ndx] = A->elem[ndx - 1];
      }
      A->elem[ctr] = x;
      A->count++;
    }else{
      printf("Element already exist: %c\n", x);
    }
  }
}


void deleteFirst(ArrayList *A){


  int ctr;
  
  A->count--;
  for(ctr = 0; ctr < A->count; ctr++){
    A->elem[ctr] = A->elem[ctr + 1];
  }
}

void deleteLast(ArrayList *A){

  A->count--;
}

void deleteElem(ArrayList *A, char x){

  int ctr;

  for(ctr = 0; ctr < A->count && A->elem[ctr] != x; ctr++){}

  if(ctr != A->count){
    A->count--;
    for(; ctr < A->count; ctr++){
      A->elem[ctr] = A->elem[ctr + 1];
    }
    
  }
}

void deleteAllOccurences(ArrayList *A, char x){
  int ctr, ndx;

  for(ctr = 0; ctr < A->count;){
    
    if(A->elem[ctr] == x){
      
      for(ndx = ctr; ndx < A->count; ndx++){
        A->elem[ndx] = A->elem[ndx + 1];
      }
      A->count--;
    } else{
    
      ctr++;
    }
    
  }
}

void sort(ArrayList *A){

  int min, ctr, ndx;
  char temp;
  
  for(ctr = 0; ctr < A->count; ctr++){
    int min = ctr;

    for(ndx = ctr; ndx < A->count; ndx++){

      if(A->elem[ndx] < A->elem[min]){
        min = ndx;
      }
    }
    temp = A->elem[ctr];
    A->elem[ctr] = A->elem[min];
    A->elem[min] = temp;
  }
}

void displayArray(ArrayList A){

  int ctr;
  for(ctr = 0; ctr < A.count; ctr++){
    printf("elem: %c\n", A.elem[ctr]);
  }
}




