#include<iostream>
using namespace std;

int main() {
    int n;
    int caseNum = 0;
    while(scanf("%d", &n) != EOF) {
        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        long long max = 0;
        for(int l=0; l<n; l++) {
            long long product = 1;
            for(int r=l; r<n; r++) {
                product *= a[r];
                if(product > max) {
                    max = product;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++caseNum, max);
    }
}