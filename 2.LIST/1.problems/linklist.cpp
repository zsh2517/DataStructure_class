#include <iostream>
using namespace std;
template <class T>
struct node {
    node<T>* next;
    T val;
    node(){
        next = nullptr;
        val = T();
    };
    node(T val) {
        this->val = val;
        this->next = nullptr;
    }
};
template <class T>
class linklist {
private:
    node<T> head;
    // void _insert(node<T>* x, int pos) {
    //     if(head.next == nullptr) {
    //         head.next = new node<T>();
    //         head.next->val = 
    //     }
    // }
    // int _find_before() {

    // }
public:
    void print() {
        for(auto ptr = head.next; ptr != nullptr; ptr = ptr->next) {
            cout << ptr->val << " ";
        }
        cout << endl;
    }
    int find(T val){
        int count = 0;
        for(auto ptr = head.next; ptr != nullptr; ptr = ptr->next) {
            if(ptr->val == val) {
                return count;
            }
            count += 1;
        }
        return -1;
    }
    int insert(T val, int pos = 0) {
        // insert x before y
        if(head.next == nullptr) {
            // if(pos != 0) {
            //     return 0;
            // }
            head.next = new node<T>(val);
            return 1;            
        } else {
            node<T>* ptr = &head;
            for(int i = 0; i < pos; i++) {
                if(ptr->next != nullptr) {
                    ptr = ptr->next;
                } else {
                    break;
                    // return 0;
                }
            }
            auto temp = new node<T>(val);
            temp->next = ptr->next;
            ptr->next = temp;
            return 1;
        }
    }
    int delete_val(T val) {
        auto before = &head;
        auto ptr = head.next;
        int flag = 0;
        int count = 0;
        for(ptr = head.next; ptr != nullptr; ptr = ptr->next) {
            if(ptr->val == val) {
                flag = 1;
                break;
            }
            before = before->next;
            count += 1;
        }
        if(!flag) {
            return -1;
        }
        before->next = before->next->next;
        delete(ptr);
        return count;
    }
    int length() {
        int count = 0;
        for(auto ptr = head.next; ptr != nullptr; ptr = ptr->next) {
            count += 1;
        }
        return count;
    }
    T find_reverse_pos(int pos) {
        // task 4
        auto ptr = head.next;
        auto ptr_fast = head.next;
        for(ptr_fast = head.next; ptr_fast != nullptr; ptr_fast = ptr_fast->next) {
            if(pos == 0) {
                pos = -1;
                break;
            } else {
                pos --;
            }
        }
        if(pos == -1) {
            for(; ptr_fast->next != nullptr; ptr_fast = ptr_fast->next) {
                ptr = ptr->next;
            }
            return ptr->val;
        } else {
            return -1;
        }
    }
    T find_middle() {
        // task 5
        auto ptr = head.next;
        auto ptr_fast = head.next;
        for(;;) {
            ptr_fast = ptr_fast->next;
            if(ptr_fast->next == nullptr) {
                // two values
                return ptr->val;
            }
            ptr_fast = ptr_fast->next;
            ptr = ptr->next;
            if(ptr_fast->next == nullptr) {
                return ptr->val;
            }
        }
    }
    void _print_reverse(node<T>* cnt) {
        // task 6 real function
        if(cnt->next != nullptr) {
            _print_reverse(cnt->next);
        }
        cout << cnt->val << " ";
    }
    void print_reverse() {
        // task 6 entrance
        _print_reverse(head.next);
    }
};

int main() {
    linklist<int> l;
    int base[] = {19, 5, 24, 14, 27, 6, 12, 21, 13, 9, 18, 17, 3, 22, 8, 15, 2, 4, 26, 7};
    // int base[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto length = sizeof(base) / sizeof(base[0]);
    for(auto i = 0; i < length; i++) {
        l.insert(base[i]);
    }
    l.print();
    cout << l.find_reverse_pos(3) << endl;
    cout << l.find_middle() << endl;
    l.print_reverse();
}