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
int findNode(Node* head, int x) {
    Node* curr=head;
    while(curr!=NULL) {
        if(curr->data==x) {
            return 1;
        }
        curr=curr->next;
    }
    return 0;
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
    int x;
    printf("Gia tri node can tim: ");
    scanf("%d",&x);
    if (findNode(head,x)) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}