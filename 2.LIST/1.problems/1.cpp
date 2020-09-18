// #include <iostream>
// using namespace std;
// void commit(int a[], int b[], int la, int lb) {
//     int pb = lb - 1;
//     int pa = 0;
//     int t; // for temp usage
//     for(int i = 0; i < la; i++) {
//         if(b[pb] < a[i]) {
//             t = a[i];
//             a[i] = b[pb];
//             b[pb] = t;
//             // pb --;
//         } else {
//             pb --;
//             // do nothing
//         }
//     }
// }

// int main() {
//     int a[10] = {5, 10, 19, 22, 41, 57, 79, 82, 91, 92};
//     int b[15] = {95, 84, 81, 69, 67, 58, 50, 49, 44, 35, 33, 14, 13, 12, 1};
//     int la = sizeof(a) / sizeof(a[0]);
//     int lb = sizeof(b) / sizeof(b[0]);
//     commit(a, b, la, lb);
//     for(int i = 0; i < la; i++) {
//         cout << a[i] << " ";
//     }
//     for(int i = 0; i < lb; i++) {
//         cout << b[i] << " ";
//     }
// }