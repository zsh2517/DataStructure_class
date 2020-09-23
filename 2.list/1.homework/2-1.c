#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _node {
    struct _node* next;
    char val;
} node;
node s1, s2;

node* gotonext(node* cnt) {
    if(cnt->next != NULL) {
        return cnt->next;
    } else {
        return s2.next;
    }
}

void print(node s) {
    for(node* ptr = s.next; ptr != NULL; ptr = ptr->next) {
        printf("%c", ptr->val);
    }
    printf("\n");
}

int main() {
    char str1[] = "loading";
    int l1 = strlen(str1);
    char str2[] = "be";
    int l2 = strlen(str2);
    node* ptr = &s1;
    for(int i = 0; i < l1; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->val = str1[i];
        ptr->next = NULL;
    }
    printf("str1 is ");
    print(s1);
    ptr = &s2;
    for(int i = 0; i < l2; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->val = str2[i];
        ptr->next = NULL;
    }
    ptr->next = s1.next->next->next->next->next;
    printf("str2 is ");
    print(s2);
    node* fast = s1.next;
    node* slow = s1.next;
    while(1) {
        fast = gotonext(fast);
        fast = gotonext(fast);
        slow = gotonext(slow);
        if(fast == slow) {
            slow = s1.next;
            while(fast != slow) {
                printf("fast=%c slow=%c\n", fast->val, slow->val);
                fast = gotonext(fast);
                slow = gotonext(slow);
            }
            printf("½»µãÎª %c\n", slow->val);
            break;
        }
    }
}