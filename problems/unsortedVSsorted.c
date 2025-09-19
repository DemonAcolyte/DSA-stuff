#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TRUE,
    FALSE
} boolean;

typedef struct node {
    int data;
    struct node *next;
} *List;

/*************************************/
/*           YOUR TASKS              */
/*************************************/
boolean isEqualNotSorted(List A, List B);
boolean isEqualSorted(List A, List B);
void sort(List L);


/*************************************/
/*       PROVIDED FUNCTIONS          */
/*************************************/
void initList(List *L);
void insertFirst(List *L, int data);
void deleteFirst(List *L);
void populate(List *L, int size);
void printList(List L);
void freeAll(List *L);

int main() {
    List A, B;
    int sizeA, sizeB;

    initList(&A);
    initList(&B);

    printf("Enter size of List A: ");
    scanf("%d", &sizeA);
    populate(&A, sizeA);

    printf("\nEnter size of List B: ");
    scanf("%d", &sizeB);
    populate(&B, sizeB);

    printf("\nBefore Sorting:\n");
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    printf("NOT SORTED: %s\n", (isEqualNotSorted(A, B) == TRUE) ? "EQUAL" : "NOT EQUAL");

    sort(A);
    sort(B);

    printf("\nAfter Sorting:\n");
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    printf("SORTED: %s", (isEqualSorted(A, B) == TRUE) ? "EQUAL" : "NOT EQUAL");

    freeAll(&A);
    freeAll(&B);

    return 0;
}

boolean isEqualNotSorted(List A, List B) {
    // Implementation here...
    
    boolean retval = FALSE;
    List C;
    List trav, trav2;
    initList(&C);
    int ctr = 0, ctr2 = 0;
    if(A == NULL && B == NULL){
        return retval;
    }

    for(trav = A; trav != NULL; trav = trav->next){
        insertFirst(&C, trav->data);
        ctr++;
    }

    for(trav2 = B; trav2 != NULL; trav2 = trav2->next){

        if(C->data == trav2->data){
            deleteFirst(&C);
        }
        ctr2++;
    }
    
    return (C == NULL && ctr == ctr2)? TRUE : FALSE;
    

}

boolean isEqualSorted(List A, List B) {
    // Implementation here...
    List trav, trav2;
    boolean retval = TRUE;
    if(A != NULL && B != NULL){
    for(trav = A, trav2 = B; trav != NULL && trav2 != NULL; trav = trav->next, trav2 = trav2->next){

        if(trav->data != trav2->data && retval == TRUE){
            retval = FALSE;
        }
    }
    }
    return retval;
}

void sort(List L) {
    // Implementation here...
    List trav;
    List trav2;
    List minNode;
    for(trav = L; trav != NULL; trav = trav->next){
        minNode = trav;
        
        for(trav2 = trav; trav2 != NULL; trav2 = trav2->next){
            if(minNode->data > trav2->data){
                minNode = trav2;
            }
        }
        int temp = minNode->data;
        minNode->data = trav->data;
        trav->data = temp;
    }
}

void initList(List *L) {
    *L = NULL;
}

void insertFirst(List *L, int data) {
    List temp = (List)malloc(sizeof(struct node));
    
    if(temp != NULL) {
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}

void deleteFirst(List *L) {
    if(*L != NULL) {
        List temp = *L;
        *L = temp->next;
        free(temp);
    }
}

void populate(List *L, int size) {
    for(int i = 0; i < size; i++) {
        int temp;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &temp);
        insertFirst(L, temp);
    }
}

void printList(List L) {
    if(L == NULL) {
        printf("EMPTY");
    }

    for(List curr = L; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }

    printf("\n");
}

void freeAll(List *L) {
    List del;

    while(*L != NULL) {
        del = *L;
        *L = (*L)->next;
        free(del);
    }
}
