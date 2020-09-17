#include <iostream>
#define min(x, y) (x<y?x:y)
using namespace std;
// int in_order[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// int in_order[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int in_order[9] = {8, 4, 2, 5, 3, 9, 1, 6, 7};
// 8, 9
// 4, 5, 6, 7
// 2, 3
// 1
int queue[9];
int sz = 0;
int main() {
    for(int i = 0; i < 9; i++) {
        int minval = 0x7fffffff, minj = -1;
        for(int j = 0; j < sz; j++) {
            if(queue[j] < in_order[i]) {
                if(minval > queue[j]) {
                    minval = min(minval, queue[j]);
                    minj = j;
                }
            }
        }
        if(minj == -1) {
            queue[sz] = in_order[i];
            sz += 1;
        }
    }
    cout << sz << endl;
}