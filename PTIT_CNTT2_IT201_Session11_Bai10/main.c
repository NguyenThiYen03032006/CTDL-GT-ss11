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
Node* swap(Node* head) {
    Node* curr=head;
    while (curr!=NULL && curr->next!=NULL) {
        Node* first=curr;
        Node* second=curr->next;
        Node* prevNode=first->prev;
        Node* nextNode=second->next;
        second->prev=prevNode;
        second->next=first;

        if (prevNode!=NULL) {
            prevNode->next=second;
        }else {
            head=second;
        }
        first->prev=second;
        first->next=nextNode;
        if (nextNode!=NULL) {
            nextNode->prev=first;
        }
        curr=first->next;
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
    head=swap(head);
    printList(head);
    return 0;
}