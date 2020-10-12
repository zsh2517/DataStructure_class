#include <iostream>
using namespace std;
#define n 50
// int arr[] = {37, 2, 25, 46, 18, 22, 2, 25, 7, 19, 19, 8, 35, 27, 28, 18, 30, 28, 6, 23, 19, 25, 49, 18, 32, 3, 39, 46, 19, 50};
int arr1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
//            0  1  2  3   4   5   6   7   8
int len1 = sizeof(arr1) / sizeof(arr1[0]);
int arr2[] = {-1, -2, -3, -4}; // and then follows 7, 8, 9, 10...
int len2 = sizeof(arr2) / sizeof(arr2[0]);
int concat_at = 7;
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

node head1, head2;

void init_data() {
    node* ptr = &head1;
    for(int i = 0; i < len1; i++) {
        ptr->next = new node(arr1[i]);
        ptr = ptr->next;
    }
    ptr = &head2;
    for(int i = 0; i < len2; i++) {
        ptr->next = new node(arr2[i]);
        ptr = ptr->next;
    }
    auto p = head1.next;
    for(int i = 0; i < concat_at; i++) {
        p = p->next;
    }
    ptr->next = p;
}

void print() {
    // print the link_list
    cout << "LINKLIST 1: ";
    for(auto ptr = head1.next; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
    cout << "LINKLIST 2: ";
    for(auto ptr = head2.next; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
}

node* gotonext(node* cnt) {
    if(cnt->next != nullptr) {
        return cnt->next;
    } else {
        return head2.next;
        // explained in readme.md of question 8
    }
}

void solve() {
    // find if it has a circle
    auto fast = head1.next;
    auto slow = head1.next;
    int count = 0;
    while(1) {
        fast = gotonext(fast);
        fast = gotonext(fast);
        slow = gotonext(slow);
        if(fast == slow) {
            slow = head1.next;
            while(fast != slow) {
                count += 1;
                fast = gotonext(fast);
                slow = gotonext(slow);
            }
            break;
        }
    }
    cout << "The common one begins at [" << count << "], and value is " << slow->val << endl;
}

int main() {
    init_data();
    print();
    solve();
}