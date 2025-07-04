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
Node* deletePosition(Node* head, int position) {
    Node* curr=head;
    if (head==NULL || position<0) {
        printf("Vi tri khong hop le\n");
        return head;
    }
    if (position==0) {
        head=head->next;
        if (head!=NULL) {
            head->prev=NULL;
        }
        free(head);
        return head;
    }
    int index=1;
    while (index<position && curr!=NULL) {
        curr=curr->next;
        index++;
    }
    // neu vi tri qua so luong danh sach
    if (curr==NULL) {
        printf("Vi tri khong hop le\n");
        return head;
    }
    // lien ket node trc vs node sau node can xoa
    if (curr->prev!=NULL) {
        curr->prev->next=curr->next;
    }
    // lien ket node sau vs node trc can xoa
    if (curr->next!=NULL) {
        curr->next->prev=curr->prev;
    }
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
    int x;
    printf("Nhap vao vi tri muon xoa: ");
    scanf("%d",&x);
    head=deletePosition(head,x);
    printList(head);
    return 0;
}