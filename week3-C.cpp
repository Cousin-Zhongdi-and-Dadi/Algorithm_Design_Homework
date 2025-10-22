#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF) {
        if(a == 0) continue;
        vector<int> array(a);
        for(int i = 1; i <= a; i++) {
            array[i-1] = i;
        }
        for(int i = 1; i < b; i++) {
            if(!next_permutation(array.begin(), array.end())) {
                break;
            }
        }
        for(int i = 0; i < a; i++) {
            if(i != 0) printf(" ");
            printf("%d", array[i]);
        }
        printf("\n");
    }
}