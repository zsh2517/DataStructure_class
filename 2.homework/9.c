// problem 19
#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    struct node* next;
    int val;
}node;

void work(node* ori, node** l1, node** l2) {
    // origin linklist is ori(ori is the head)
    // new linklist is l1, l2
    // now l1 == NULL and l2 == NULL;
    int target = 1;
    for(node* ptr = ori->next; ptr != NULL; ptr = ptr->next) {
        if(target == 1) {
            node* temp = (node*) malloc(sizeof(node));
            temp->val = ptr->val;
            if((*l1) == NULL) {
                (*l1) = temp;
                (*l1)->next = (*l1);
            } else {
                temp->next = (*l1)->next;
                (*l1)->next = temp;
                (*l1) = (*l1)->next;
            }
        } else {
            node* temp = (node*) malloc(sizeof(node));
            temp->val = ptr->val;
            if((*l2) == NULL) {
                (*l2) = temp;
                (*l2)->next = (*l2);
            } else {
                temp->next = (*l2)->next;
                (*l2)->next = temp;
                (*l2) = (*l2)->next;
            }
        }
        target = 3 - target;
    }
}

int main() {
    node* ori = (node*) malloc(sizeof(node));
    ori->next = NULL;
    node* ptr = ori;
    for(int i = 1; i < 10; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->val = i;
        ptr->next = NULL;
    }
    node* l1 = NULL;
    node* l2 = NULL;
    work(ori, &l1, &l2);
    for(int i = 0; i < 15; i++) {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
    printf("\n");
    for(int i = 0; i < 15; i++) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");
}