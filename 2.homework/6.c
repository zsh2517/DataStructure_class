// problem 16
#include <stdio.h>
#define SIZE 10
int s[SIZE];
int size1, size2;
// stack1: [0] - [size1 - 1]
// stack2: [SIZE - size2] - [SIZE - 1]
void init() {
    size1 = 0;
    size2 = 0;
}
void push(int x, int target) {
    if(size1 + size2 < SIZE) {
        if(target == 1) {
            size1 ++;
            s[size1 - 1] = x; 
        } else {
            size2 ++;
            s[SIZE - size2] = x;
        }
    }
}

int top(int target) {
    if(target == 1) {
        return s[size1 - 1];
    } else {
        return s[SIZE - size2];
    }
}

void pop(int target) {
    if(target == 1) {
        size1 --;
    } else {
        size2 --;
    }
}

void print() {
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", s[i]);
    }
}

int main() {
    for(int i = 3; i < 20; i++) {
        push(i, ((i % 3) < 2) + 1);
        printf("insert %d to %d; now top is %d;", i, ((i % 3) < 2) + 1, top(((i % 3) < 2) + 1));
        print();
        printf("\n");
    }
    for(int i = 3; i < 15; i++) {
        pop(((i % 3) < 2) + 1);
        print();
        printf("\n");
    }
}