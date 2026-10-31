/*#include <stdio.h>

int main ( void ) {
int severity = 5;
int * p = & severity ;
printf ( "severity = %d \n " , severity ) ;
printf ( "&severity = %p \n" ,& severity ) ;
printf ( "p = %p \n " , ( void *) p ) ;
printf ( "*p = %d \n " , * p ) ;
*p = 8;
printf ( " severity after * p = 8: %d \n " , severity ) ;
return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SecurityEvent {
    int eventID, severity;
    char code[20];
};

struct node {
    int eventID, severity;
    struct node *next;
};

void insertBeginning ( struct node **head , int id , int severity ) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if ( newNode == NULL ) {
        printf ("Memory allocation failed \n");
        return ;
    }
    newNode -> eventID = id ;
    newNode -> severity = severity ;
    newNode -> next = * head ;
    *head = newNode;
}

void insertAfter (struct node **head, int afterID, int newID, int severity) {
    if ( head == NULL ){
        return ;
    }  

    struct node *current = *head;
    
    while(current->eventID != afterID){
        current = current->next;
    }


    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if ( newNode == NULL ){
        return ;
    } 
    newNode -> eventID = newID ;
    newNode -> severity = severity ;
    newNode->next = current->next;
    current->next = newNode;
}

void insertEnd (struct node **head, int id, int severity){
    struct node *newNode = malloc(sizeof(struct node));
    if ( newNode == NULL )
        return ;
    newNode -> eventID = id ;
    newNode -> severity = severity ;
    newNode -> next = NULL ;

    if (*head == NULL ) {
        printf("La liste est vide \n");
        return ;
    }

    struct node *current = *head ;

    while (current->next != NULL) {
        current = current -> next ;
    }
    current->next = newNode;
}

void deletingBeginning(struct node **head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);    
}

void deleteEnd(struct node **head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }

   struct node *temp = *head;

    while (temp->next != NULL) {
        temp = temp -> next ;
    }
    free(temp);
}

/*void deleteById(struct node **head, int id){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }

   struct node *temp = *head;

    while (temp->eventID != id) {
        temp = temp -> next ;
    }
    free(temp);
}*/

void deleteById(struct node**head, int afterId){
    struct node *current = *head;

    while(current->eventID!=afterId){
        current=current ->next;
    }
    
    struct node *mid=current->next;
    current->next = mid->next;
    mid->next = NULL;
    free(mid);
}


void printList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("[ID: %d | Sev: %d] -> ", current->eventID, current->severity);
        current = current->next;
    }
    printf("NULL\n");
}

void display(struct node *head){
    struct node *current = head;

    while (current != NULL){
        printf("ID: %d | Severity: %d\n",current->eventID,current->severity);
        current = current->next;
    }
}

int countNodes(struct node *head){
    int count = 0;
    struct node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}



void changeByValue ( int x ) {
x = 10;
}
void changeByReference ( int * x ) {
*x = 10;
}

int main() {
    struct SecurityEvent event1;
    event1.eventID = 101;
    event1.severity = 5;
    strcpy(event1.code, "LOGIN_FAIL"); 

    /*struct SecurityEvent *ptr = &event1;
    printf("Event ID: %d\n", event1.eventID);
    printf("Severity: %d\n", event1.severity);
    printf("Code: %s\n", event1.code);

    printf("Acceder par pointer");

    printf("Event ID: %d\n", ptr->eventID);
    printf("Severity: %d\n", ptr->severity);
    printf("Code: %s\n", ptr->code);

    ptr->severity = 4;
    printf("Severity: %d\n", event1.severity);*/

    /*int severity = 5;
    changeByValue ( severity ) ;
    printf ( "After value : % d \n", severity ) ;
    changeByReference (& severity ) ;
    printf ( "After reference : % d \n", severity ) ;*/

    /*struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n3->eventID = 103; n3->severity = 4; n3->next = NULL; 

    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n2->eventID = 102; n2->severity = 3; n2->next = n3; 

    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    n1->eventID = 101; n1->severity = 5; n1->next = n2; 

    struct node *head = n1; 

    insertBeginning(&head, 100, 2);
    insertEnd(&head,104,3);
    insertAfter(&head,101,150,4);
    

    printf("\n--- Test Liste Chainee (malloc) ---\n");
    printList(head);

    

    

    printf("Number of nodes: %d\n",countNodes(head));

    deletingBeginning(&head);

    display(head);


    // Libération de la mémoire de la liste (Bonne pratique !)
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }*/

    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    n1->eventID = 101; n1->severity = 5; n1->next = NULL; 

    struct node *head = n1;

    insertEnd(&head,102,3);
    insertEnd(&head,103,4);
    insertBeginning(&head,100,5);
    insertAfter(&head,101,150,2);

    display(&head);

    printf("Number of nodes: %d\n",countNodes(head));
    deletingBeginning(&head);
    deleteEnd(&head);
    deleteById(&head,150);

    display(&head);
    
    printf("Number of nodes: %d\n",countNodes(head));




    return 0;
}

