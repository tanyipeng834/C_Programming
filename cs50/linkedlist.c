#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int number;
    struct node* next;
} node;
void insert_start(node** head, int value);
void insert_end(node** head, int value);
void walk (node* head);
void freeList (node* head);

int main(void){
 node* head = NULL;

 insert_start(&head ,1);
 insert_start(&head,2);
 insert_start(&head,3);
 insert_end(&head,4);
 walk(head);
 // rmb to free the memory in the linked list 
 freeList(head);
 return 0;







}

void insert_start(node** head, int value)
{
    node* current = (node *) malloc(sizeof(node));
    if(current ==NULL){
        return;
    }
        current ->number = value;
    
    // we want to modify head    
        current->next= *head;

        *head = current;

    }
void insert_end(node** head, int value)
{
    // go until the last element and then we add the new element
    node * newNode = (node *) malloc(sizeof(node));
    if(newNode ==NULL){
        return;
    }
    newNode->number = value;
    newNode ->next = NULL;
    if(*head ==NULL){
        *head = newNode;

    }
    else{
        node * walk  = *head;
        while(walk->next !=NULL)
        {
            walk = walk->next;

        }

        walk->next = newNode;

    }


}




void walk(node * head)
{
    node * walk = head;
    while(walk !=NULL){
        printf("%d\n",walk->number);
        walk = walk->next;

    }
}

void freeList (node *head)
    {
        node * walk = head;
        while(walk !=NULL)
        {
             node* next = walk ->next;
            free(walk);
            walk = next;

            

        }

    }

