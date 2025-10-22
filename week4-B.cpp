#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int l, r, sum;
    Node(int x, int y, int z) : l(x), r(y), sum(z) {}
};

Node crossArraySum(const vector<int>& arr, int left, int mid, int right) {
    int leftSum = -10000, rightSum = -10000;
    int sum = 0;
    int maxLeft = mid, maxRight = mid + 1;

    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return Node(maxLeft, maxRight, leftSum + rightSum);
}

Node maxSubArraySum(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return Node(left, right, arr[left]);
    }

    int mid = left + (right - left) / 2;
    Node leftNode = maxSubArraySum(arr, left, mid);
    Node rightNode = maxSubArraySum(arr, mid + 1, right);
    Node crossNode = crossArraySum(arr, left, mid, right);

    if (leftNode.sum >= rightNode.sum && leftNode.sum >= crossNode.sum) {
        return leftNode;
    } else if (rightNode.sum >= leftNode.sum && rightNode.sum >= crossNode.sum) {
        return rightNode;
    } else {
        return crossNode;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node result = maxSubArraySum(arr, 0, n - 1);
    cout << result.sum << endl;

    return 0;
}