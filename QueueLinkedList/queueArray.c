#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
  
  char elem[MAX];
  int front;
  int rear;
}Queue;

void initQueue(Queue *A);
void enqueue(Queue *A, char x);
void dequeue(Queue *A);
char top(Queue A);
bool isFull(Queue A);
bool isEmpty(Queue A);
void read(Queue A);


int main(){
  
  Queue L;
  initQueue(&L);

  enqueue(&L, 'a');
  enqueue(&L, 'd');
  enqueue(&L, 'h');
  read(L);
  printf("Dequeue:\n");
  dequeue(&L);
  dequeue(&L);
  enqueue(&L, 'b');
  read(L);
}



void initQueue(Queue *A){
  A->front = 1;
  A->rear = 0;
}

bool isFull(Queue A){
  return (A.front == (A.rear + 2) % MAX)? true : false;
}

bool isEmpty(Queue A){
  return (A.front == (A.rear + 1) % MAX)? true : false;
}

void enqueue(Queue *A, char x){
  if(!isFull(*A)){
  A->rear = (A->rear + 1) % MAX;
  A->elem[A->rear] = x;
  }
}

void dequeue(Queue *A){
  if(!isEmpty(*A)){
  A->front = (A->front + 1) % MAX;
  }
}

char front(Queue A){
  return (!isEmpty(A))? A.elem[A.front] : 'O';
}

void read(Queue A){

  int temp;
  for(;!isEmpty(A);){
    temp = front(A);
    dequeue(&A);
    printf("elem: %c\n", temp);
  }
  
}

