#include <iostream>
// #define MAKE_CIRCLE_SIZE
#define CIRCLE_SIZE 2
using namespace std;
#define n 50
// int arr[] = {37, 2, 25, 46, 18, 22, 2, 25, 7, 19, 19, 8, 35, 27, 28, 18, 30, 28, 6, 23, 19, 25, 49, 18, 32, 3, 39, 46, 19, 50};
int arr[] = {18, 19, 1, 4, -19, -4, -7, -11, -15, 13, 20, 19, -17, 20, -5, 2, 3, -13, -4, 6, 19, 13, -6, -16, -9, 2, -11, 5, -9, 5};
int length = sizeof(arr) / sizeof(arr[0]);

struct node {
    node* next;
    int val;
    node(){
        next = nullptr;
        val = 0;    
    }
    node(int x) {
        next = nullptr;
        val = x;
    }
};

node head;

void init_data() {
    // make the array arr[] into a link_list
    node* ptr = &head;
    for(int i = 0; i < length; i++) {
        ptr->next = new node(arr[i]);
        ptr = ptr->next;
    }
}

void print() {
    // print the link_list
    for(auto ptr = head.next; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
}

node* gotonext(node* cnt) {
    if(cnt->next != nullptr) {
        return cnt->next;
    } else {
        return nullptr;
    }
}

void makecircle() {
    // make a circle
    auto ptr = head.next;;
    for(; ptr->next != nullptr; ptr = ptr->next);
    auto cir_bgn = head.next;
    for(int i = 0; i < CIRCLE_SIZE; i++) {
        cir_bgn = cir_bgn->next;
    }
    ptr->next = cir_bgn;
}

void solve() {
    // find if it has a circle
    auto fast = head.next;
    auto slow = head.next;
    int flag_circle = 1;
    while(1) {
        if(fast->next == nullptr) {
            flag_circle = 0;
            break;
        }
        fast = fast->next;
        if(fast->next == nullptr) {
            flag_circle = 0;
            break;
        }
        fast = fast->next;
        slow = slow->next;
        if(fast == slow) {
            flag_circle = 1;
            break;
        }
    }
    if(flag_circle) {
        cout << "have a circle" << endl;
    } else {
        cout << "no circle" << endl;
        return;
    }
    // find the cross of the circle
    slow = head.next;
    int count = 0;
    while(slow != fast) {
        count += 1;
        slow = slow->next;
        fast = fast->next;
    }
    cout << "The entrance is arr[" << count << "], and value is " << slow->val << endl;
}

int main() {
    init_data();
    print();
    #ifdef MAKE_CIRCLE_SIZE
        makecircle();
    #endif
    solve();
}