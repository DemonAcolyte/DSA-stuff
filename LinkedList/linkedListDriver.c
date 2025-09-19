#include <stdio.h>
#include <stdlib.h>
#include "linkedListHeader.h"



int main(){

  LinkedList L;

  initLL(&L);
  insertFirst(&L, 'd');
  insertFirst(&L, 'b');
  insertLast(&L, 'a');
  insertLast(&L, 'c');
  displayLL(L);
  printf("Sorted: \n");
  sort(L);
  displayLL(L);

}
