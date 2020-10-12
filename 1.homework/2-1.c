#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义链表的结构
typedef struct _node {
    struct _node* next;
    char data;
} node;
node s1, s2;

// 获取下一个节点. 可以参考报告中 4. 算法设计 > Part 2. 连接尾节点和第二个节点头部
// 在不改变链表的结构的情况下, 实现链表的公共结尾和第二个链表头相连接的效果
node* gotonext(node* cnt) {
    if(cnt->next != NULL) {
        // 如果没有到达结尾
        return cnt->next;
    } else {
        // 如果到达了结尾. 那么下一个节点就是第二个链表的头节点
        return s2.next;
    }
}

// 打印链表 s
void print(node s) {
    for(node* ptr = s.next; ptr != NULL; ptr = ptr->next) {
        printf("%c", ptr->data);
    }
    printf("\n");
}

int main() {
    // 定义两个字符串
    char str1[] = "loading";
    int l1 = strlen(str1);
    char str2[] = "be";
    int l2 = strlen(str2);
    
    // 因为仅仅需要把字符串插入进去. 并没有太过于复杂的插入操作
    // 所以直接写到了主函数内部

    // str1[] -> s1
    node* ptr = &s1;
    for(int i = 0; i < l1; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->data = str1[i];
        ptr->next = NULL;
    }
    printf("str1 is ");
    print(s1);

    // str2[] -> s2
    ptr = &s2;
    for(int i = 0; i < l2; i++) {
        ptr->next = (node*) malloc(sizeof(node));
        ptr = ptr->next;
        ptr->data = str2[i];
        ptr->next = NULL;
    }

    // 手动把 s2 的结尾 (being 目前插入了 be, 下一个是 i) 指向 s1 的 ing 的 i 处
    ptr->next = s1.next->next->next->next->next;

    printf("str2 is ");
    print(s2);
    
    // 找环    
    printf("--------------------    Test if have circle...    --------------------\n");
    node* fast = s1.next;
    node* slow = s1.next;
    printf("Begin. fast is %c and slow is %c\n", fast->data, slow->data);
    while(1) {
        // 筷慢指针. 分别步进 2 和 步进 1
        fast = gotonext(fast);
        fast = gotonext(fast);
        slow = gotonext(slow);
        printf("fast=%c slow=%c\n", fast->data, slow->data);
        // 由于确定了一定存在公共交点, 进而一定存在环
        // 所以不需要单独判断如果是单链即 fast == NULL && slow != NULL 的情况
        if(fast == slow) {
            // 快慢指针相遇

            printf("--------------------    Find circle...    --------------------\n");
            // 一个指针回到开头
            slow = s1.next;
            printf("fast is %c. slow returns to link_list1's head: %c\n", fast->data, slow->data);
            
            // 再次相向运动直到相交然后停止
            while(fast != slow) {
                fast = gotonext(fast);
                slow = gotonext(slow);
                printf("fast=%c slow=%c\n", fast->data, slow->data);
            }

            printf("the cross node is %c\n", slow->data);
            break;
        }
    }
}
