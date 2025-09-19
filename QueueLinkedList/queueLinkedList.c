#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

  char elem;
  struct node *link;
}*nodetype;

typedef struct{

  nodetype front;
  nodetype rear;

}Queue;

void initQueue(Queue *A);
bool isEmpty(Queue A);
bool isFull(Queue A);
void enqueue(Queue *A, char x);
void dequeue(Queue *A);
char top(Queue A);
void read(Queue A);
int size(Queue A);
void insertSorted(Queue *A, char x);

int main(){

  Queue L;

  initQueue(&L);
  enqueue(&L, 'a');
  enqueue(&L, 'b');
  enqueue(&L, 'z');

  //printf("rear: %c", L.rear->elem);
  insertSorted(&L, 'c');
  insertSorted(&L, 'c');
  insertSorted(&L, 'd');
  read(L);
  
}


void initQueue(Queue *A){
  A->front = NULL;
  A->rear = NULL;
}

bool isEmpty(Queue A){
  return (A.front == NULL)? true : false;
}

void enqueue(Queue *A, char x){

  nodetype newNode = (nodetype)malloc(sizeof(struct node));
  
  newNode->elem = x;
  newNode->link = NULL;
  if(isEmpty(*A)){
    A->front = newNode;
  }else{
    A->rear->link = newNode;
  }

  A->rear = newNode;

}

void dequeue(Queue *A){
  
  nodetype temp;
  if(!isEmpty(*A)){
    temp = A->front;
    A->front = A->front->link;
    free(temp);
  }
  if(A->front == NULL){
    A->rear = NULL;
  }
}

char front(Queue A){
  return (!isEmpty(A))? A.front->elem : '0'; 
}

void read(Queue A){

  nodetype temp;
  char element;
  nodetype stop = A.front;
  int count = size(A);
  int ctr;
  
  if(isEmpty(A)){
    printf("Queue Empty");
    return;
  }
  for(ctr = 0; ctr < count; ctr++){
    
    char temp = front(A);
    printf("elem: %c\n", temp);
    
    dequeue(&A);
    enqueue(&A, temp);
    
  }
}

int size(Queue A){

  int ctr = 0;
  nodetype trav;
  for(trav = A.front; trav != NULL; trav = trav->link){
    ctr++;
  
  }
  
  return ctr;
}

void insertSorted(Queue *A, char x){
  int numElem = size(*A);
  int ctr;

  bool retval = false;
  for(ctr = 0; ctr < numElem; ctr++){
    char temp = front(*A);

    if(x < temp && retval == false){
    enqueue(A, x);
    retval = true;
    }
    dequeue(A);
    enqueue(A, temp);
  }
  if(retval == false){
    enqueue(A, x);
  }
}
