#include <iostream>
using namespace std;

int isLegal(int a, int b){
    int used[10] = {0};
    for(int i = 0; i < 5; i++) {
        used[a % 10]++;
        a /= 10;
        used[b % 10]++;
        b /= 10;
    }
    for(int i = 0; i < 10; i++) {
        if(used[i] > 1) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    bool first = true;
    while(n != 0) {
        if(!first) {
            // print a blank line to separate from previous test case
            printf("\n");
        }
        first = false;

        int a = 1234;
        int flag = 0;
        int b = n * a;
        while(b <= 98765) {
            if(isLegal(a, b)) {
                printf("%05d / %05d = %d\n", b, a, n);
                flag = 1;
            }
            a++;
            b = n * a;
        }
        if(!flag) {
            printf("There are no solutions for %d.\n", n);
        }
        scanf("%d", &n);
    }
}