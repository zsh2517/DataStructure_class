#include <stdio.h>
int a[10010] = {0};
int n = 20;
int check(int* left, int* right) {
    int pos = ((*left) + (*right)) / 2;
    if(a[pos - 1] > a[pos] && a[pos + 1] > a[pos]) {
        return 1;
    } else {
        if(a[pos - 1] < a[pos] && a[pos] < a[pos + 1]) {
            // a[target] <= a[pos - 1] < a[pos] < a[pos + 1]
            *right = pos - 1;
        } else {
            // a[pos + 1] > a[pos] > a[pos - 1] >= a[target]
            *left = pos + 1;
        }
        return 0;
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int left = 0;
    int right = n - 1;
    while(!check(&left, &right));
    printf("%d", (left + right) / 2);
}