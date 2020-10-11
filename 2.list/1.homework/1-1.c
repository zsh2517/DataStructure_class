#include <stdio.h>
int a[10010] = {0};
int n = 20;

// 传入一个区间范围. 然后取中间 pos = (left + right) / 2
// 根据 arr[pos - 1], arr[pos], arr[pos + 1] 的情况
// 判断当前 pos 和要找的 target 的关系
int check(int* left, int* right) {
    int pos = ((*left) + (*right)) / 2;
    if(a[pos - 1] > a[pos] && a[pos + 1] > a[pos]) {
        // case 1
        // a[pos - 1] > a[pos/target] < a[pos + 1]
        return 1;
    } else {
        if(a[pos - 1] < a[pos] && a[pos] < a[pos + 1]) {
            // case 2
            // a[target] <= a[pos - 1] < a[pos] < a[pos + 1]
            // 所求的 target 在传入的 pos (即 (left + right) / 2) 的左边
            *right = pos - 1;
            // 更换当前的区间为左边的半部分
        } else {
            // case 3
            // a[pos + 1] > a[pos] > a[pos - 1] >= a[target]
            // 所求的 target 在传入的 pos (即 (left + right) / 2) 的右边
            *left = pos + 1;
            // 更换当前的区间为右边的半部分
        }
        return 0;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // 输入
    int left = 0;
    int right = n - 1;
    // 初始化 left 和 right
    while(!check(&left, &right));
    // 在上面的 [left, right] 内进行查找
    printf("%d", (left + right) / 2);
    // 输出结果
}