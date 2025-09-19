
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayHeader.h"




int main(){

  
  ArrayList L;
  
  initArray(&L);
  insertFirst(&L, 'y');
  insertLast(&L, 'd');
  insertLast(&L, 'z');
  insertFirst(&L, 'a');
  insertFirst(&L, 'z');
  displayArray(L);
  printf("Insert Sorted: \n");
  insertSorted(&L, 'b');
  insertSorted(&L, 'c');
  displayArray(L);
  printf("Insert Sorted Unique: \n");
  insertSortedUnique(&L, 'c');
  insertSortedUnique(&L, 'k');
  displayArray(L);
  printf("Delete First: \n");
  deleteFirst(&L);
  displayArray(L);
  printf("Delete Last: \n");
  deleteLast(&L);
  displayArray(L);
  printf("Delete Array: \n");
  deleteElem(&L, 'a');
  displayArray(L);
  printf("Delete All Occurences: \n");
  deleteAllOccurences(&L, 'z');
  displayArray(L);
  printf("Sorted: \n");
  sort(&L);
  displayArray(L);

  
}
