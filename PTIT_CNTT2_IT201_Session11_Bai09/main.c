#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void printList(Node* head) {
    Node* curr=head;
    while(curr!=NULL) {
        printf("%d<->", curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}
Node* reverse(Node* head) {
    Node* curr=head;
    Node* temp=NULL;
    while(curr!=NULL) {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if (temp!=NULL) {
        head=temp->prev;
    }
    return head;
}
int main(void) {
    Node* head=NULL;
    Node* tail=NULL;
    for (int i=1;i<=5; i++) {
        Node* node=createNode(i);
        if (!head) {
            head=tail=node;
        }else {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }
    head=reverse(head);
    printList(head);
    return 0;
}