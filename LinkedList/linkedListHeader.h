#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

  char elem;
  struct node *link;
}*LinkedList;

void initLL(LinkedList *A);
void insertFirst(LinkedList *A, char x);
void insertLast(LinkedList *A, char x);
void insertSorted(LinkedList *A, char x);
void insertSortedUnique(LinkedList *A, char x);

void deleteElem(LinkedList *A, char x);
void deleteFirst(LinkedList *A);
void deleteLast(LinkedList *A);
void deleteAllOccurences(LinkedList *A, char x);


void displayLL(LinkedList A);
void selectionSort(LinkedList *A);
void sort(LinkedList A);




void initLL(LinkedList *A){
  *A = NULL;
}

void insertFirst(LinkedList *A, char x){

  LinkedList newNode;

  newNode = (LinkedList)malloc(sizeof(struct node));
  if(newNode != NULL){
    newNode->elem = x;
    newNode->link = *A;
    *A = newNode;
  }
}

void insertLast(LinkedList *A, char x){

  LinkedList *trav;
  LinkedList newNode;
  for(trav = A; *trav != NULL; trav = &(*trav)->link){}
  
  newNode = (LinkedList)malloc(sizeof(struct node));
  if(newNode != NULL){
    newNode->elem = x;
    newNode->link = NULL;
    *trav = newNode;
  }
}

void insertSorted(LinkedList *A, char x){
  
  LinkedList *trav;
  LinkedList newNode;

  for(trav = A; *trav != NULL && (*trav)->elem < x; trav = &(*trav)->link){}

  newNode = (LinkedList)malloc(sizeof(struct node));
  if(newNode != NULL){
    newNode->elem = x;
    newNode->link = *trav;
    *trav = newNode;
  }
}

void insertSortedUnique(LinkedList *A, char x){

  LinkedList *trav;
  LinkedList newNode;

  for(trav = A; *trav != NULL && (*trav)->elem < x; trav = &(*trav)->link){}

  
  if((*trav)->link == NULL || (*trav)->elem != x){
    
    newNode = (LinkedList)malloc(sizeof(struct node));
    if(newNode != NULL){
      newNode->elem = x;
      newNode->link = *trav;
      *trav = newNode;
    }
  }
}

void deleteElem(LinkedList *A, char x){

  LinkedList *trav;
  LinkedList temp;
  for(trav = A; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link){}

  if(*trav != NULL){
    temp = *trav;
    *trav = temp->link;
    free(temp);
  }
}

void deleteFirst(LinkedList *A){
  
  LinkedList temp;
  if(*A != NULL){
    temp = *A;
    *A = temp->link;
    free(temp);
  }
}

void deleteLast(LinkedList *A){

  LinkedList *trav;
  LinkedList temp;
  for(trav = A; *trav != NULL; trav = &(*trav)->link){}

  temp = *trav;
  *trav = temp->link;
  free(temp);
}

void deleteAllOccurences(LinkedList *A, char x){

  LinkedList *trav;
  LinkedList temp;

  for(trav = A; *trav != NULL;){

    if((*trav)->elem == x){
      temp = *trav;
      *trav = temp->link;
      free(temp);
    } else{
      trav = &(*trav)->link;
    }
  }
}

void displayLL(LinkedList A){

  LinkedList trav;

  for(trav = A; trav != NULL; trav = trav->link){
    printf("elem %c\n", trav->elem);
  }
}

void selectionSort(LinkedList *A){
  
  LinkedList *trav;
  LinkedList *trav2;
  char min, swapper;
  LinkedList *minNode;
  for(trav = A; *trav != NULL; trav = &(*trav)->link){

    min = (*trav)->elem;
    minNode = trav;
    for(trav2 = trav; *trav2 != NULL; trav2 = &(*trav2)->link){
      if(min > (*trav2)->elem){
        min = (*trav2)->elem;
        minNode = trav2;
      }
    }
    swapper = (*trav)->elem;
    (*trav)->elem = (*minNode)->elem;
    (*minNode)->elem = swapper;
  }
}

void sort(LinkedList A) {
    
    LinkedList trav;
    LinkedList trav2;
    LinkedList minNode;
    for(trav = A; trav != NULL; trav = trav->link){
        minNode = trav;
        
        for(trav2 = trav; trav2 != NULL; trav2 = trav2->link){
            if(minNode->elem > trav2->elem){
                minNode = trav2;
            }
        }
        char temp = minNode->elem;
        minNode->elem = trav->elem;
        trav->elem = temp;
    }
}
