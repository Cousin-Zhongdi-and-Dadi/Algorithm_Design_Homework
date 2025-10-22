#include <iostream>
#include <vector>
using namespace std;

long long res;

void merge(vector<long long>& arr, int left, int mid, int right) {
    long long n1 = mid - left + 1;
    long long n2 = right - mid;

    vector<long long> L(n1), R(n2);
    for (long long i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (long long j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    long long i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            res += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<long long>& arr, long long left, long long right) {
    if (left < right) {
        long long mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    long long n;
    cin >> n;
    if (n <= 0){
        cout << 0 << endl;
        return 0;
    }
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    res = 0;
    mergeSort(arr, 0, n - 1);
    cout << res << endl;
    
    return 0;
}