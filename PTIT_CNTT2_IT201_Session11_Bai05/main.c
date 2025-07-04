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
Node* insertHead(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head==NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
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
    printf("Nhap gia tri node them vao dau danh sach: ");
    scanf("%d",&x);
    head=insertHead(head,x);
    printList(head);
    return 0;
}