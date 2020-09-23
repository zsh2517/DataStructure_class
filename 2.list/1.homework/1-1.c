#include <stdio.h>
int a[20] = {98, 96, 76, 66, 56, 54, 33, 21, 10, 7, 3, 11, 15, 19, 23, 35, 39, 60, 63, 67};
int n = 20;
int check(int* left, int* right) {
    int pos = ((*left) + (*right)) / 2;
    if(a[pos - 1] > a[pos] && a[pos + 1] > a[pos]) {
        return 1;
    } else {
        if(a[pos - 1] < a[pos] && a[pos] < a[pos + 1]) {
            // a[target] <= a[pos - 1] < a[pos] < a[pos + 1]
            *right = pos;
        } else {
            // a[pos + 1] > a[pos] > a[pos - 1] >= a[target]
            *left = pos;
        }
        return 0;
    }
}
int main() {
    int left = 0;
    int right = n - 1;
    while(!check(&left, &right));
    printf("%d", (left + right) / 2);
}