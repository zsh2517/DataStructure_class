#include <iostream>
using namespace std;
#define n 50
// int arr[] = {37, 2, 25, 46, 18, 22, 2, 25, 7, 19, 19, 8, 35, 27, 28, 18, 30, 28, 6, 23, 19, 25, 49, 18, 32, 3, 39, 46, 19, 50};
int arr[] = {18, 19, 1, 4, -19, -4, -7, -11, -15, 13, 20, 19, -17, 20, -5, 2, 3, -13, -4, 6, 19, 13, -6, -16, -9, 2, -11, 5, -9, 5};
int length = sizeof(arr) / sizeof(arr[0]);

int bucket[n + 1] = {0};
int visit[n + 1] = {0};

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

void solve() {
    // solve the question

    // count the number
    for(auto ptr = head.next; ptr != nullptr; ptr = ptr->next) {
        bucket[abs(ptr->val)] += 1;
    }

    // foreach x in link_list, find if it is duplicate.
    for(auto ptr = &head; ptr->next != nullptr;) {
        int thisval = abs(ptr->next->val);
        // meet it for the first time
        if(!visit[thisval]) {
            visit[thisval] = 1;
            ptr = ptr->next;
        } else {
            // not the first time
            if(bucket[thisval]) {
                auto temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
            } else {
                ptr = ptr->next;
            }
        }
    }
}

int main() {
    init_data();
    print();
    solve();
    print();
}