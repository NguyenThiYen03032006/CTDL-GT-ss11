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
Node* insertNode(Node* head, int data, int position) {
    Node* node = createNode(data);
    Node* curr = head;
    int index=1;
    while(curr!=NULL&& index<position-1) {
        curr=curr->next;
        index++;
    }
    node->next=curr->next;
    node->prev=curr;
    curr->next=node;
    curr->next->prev=node;
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
    int x, position;
    printf("value: ");
    scanf("%d", &x);
    printf("position: ");
    scanf("%d", &position);
    head=insertNode(head, x, position);
    printList(head);
    return 0;
}