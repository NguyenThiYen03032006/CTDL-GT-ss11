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
Node* deleteHead(Node* head) {
    Node* curr=head;
    if(curr==NULL) {
        return NULL;
    }
    head=head->next;
    head->prev=NULL;
    free(curr);
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
    head=deleteHead(head);
    printList(head);
    return 0;
}