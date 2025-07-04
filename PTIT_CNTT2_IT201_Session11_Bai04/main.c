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
int lengthList(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
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
    printf("Danh sach lien ket co %d phan tu\n", lengthList(head));
    return 0;
}