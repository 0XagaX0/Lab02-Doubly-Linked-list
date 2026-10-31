#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void insertAtBeginning(struct Node **head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head)!=NULL){
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}


void insertAtEnd(struct Node **head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *current = *head;
    newNode->data=  data;

    while (current->next!=NULL){
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;

}

void insertAfter(struct Node **head, int data ,int targetValue){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *current = *head;

    while(current->data!=targetValue){
        current=current->next;
    }

    newnode->next = current->next;
    current->next = newnode;
    newnode->prev = current;
    newnode->next->prev = newnode;
}


void deleteAtBeginning(struct Node **head){
    struct Node *current = *head;
    (*head) = (*head)->next;
    current->next = NULL;
    free(current);
}


void deleteAtEnd(struct Node **head){
    struct Node *current = *head;
    while(current->next!=NULL){
        current= current->next;
    }

    current->prev->next = NULL;
    free(current);
}


void deleteNode(struct Node **head, int targetValue){
    struct Node *current = *head;

    while (current->data!=targetValue)
    {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    current->next = NULL;
    current->prev = NULL;
    free(current);
}



struct Node* searchNode(struct Node **head,int tragetValue){
    struct Node *current = *head;
    while(current->data!=tragetValue){
        current=current->next;
    }

    if(current!=NULL){
        return current;
    }
    else{
        return NULL;
    }
}


void traverseForward(struct Node **head){
    struct Node *current = *head;
    while (current!=NULL){
        current=current->next;
        printf("%d\n",current->data);
    }
}


void traverseBackward(struct Node **tail){
    struct Node *current = *tail;
    while(current!=NULL){
        current = current->prev;
        printf("%d\n",current->data);
    }
}



int main(){
    struct Node *head = NULL;

    insertAtBeginning(&head,15);
    insertAtBeginning(&head,10);

    insertAtEnd(&head,20);
    insertAtEnd(&head,25);
    insertAtEnd(&head,30);

    insertAfter(&head,17,15);

    traverseForward(&head);

    //traverseBackward(&tail);

 

}