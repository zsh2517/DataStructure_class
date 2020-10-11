#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
    struct _node* next;
    int val;
} node;

void insert(node* head, int val) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->val = val;
    newnode->next = head->next->next;
    head->next = newnode;
}

void convert_linklist(node* head, int arr[], int size) {
    node* ptr = head;
    for(int i = 0; i < size; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->val = arr[i];
        ptr->next = NULL;
    }
}

void print(node* head) {
    for(node* ptr = head->next; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->val);
    }
    printf("\n");
}

// problem 6
void copy_linklist(node* origin, node* target) {
    // copy origin to target
    node* ptr = target;
    for(node* p = origin->next; p != NULL; p = p->next) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->val = p->val;
        ptr->next = NULL;
    }
}

// problem 14
void stack_push(node* head, int val) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->val = val;
    newnode->next = head->next;
    head->next = newnode;
}

int stack_top(node* head) {
    return head->next == NULL?NULL:head->next->val;
}

void stack_pop(node* head) {
    if(head->next != NULL) {
        node* temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
}

// problem 17
int length(node* head) {
    int ans = 0;
    for(node* ptr = head->next; ptr != NULL; ptr = ptr->next) {
        ans ++;
    }
    return ans;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    node a;
    convert_linklist(&a, arr, sizeof(arr) / sizeof(arr[0]));
    print(&a);
    node b;
    copy_linklist(&a, &b);
    print(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_push(&b, 2);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_push(&b, 3);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
    stack_pop(&b);
    printf("[%d %d]", stack_top(&b), length(&b));
}