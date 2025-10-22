#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // priority 大的优先级高（降序）
        }
        return a.second > b.second;  // 如果 priority 相同，time 小的优先级高（早到的先出）
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            continue;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> doc_a;  // 大顶堆 for priority and time
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> doc_b;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> doc_c;
        int id = 0;  // 入队时间计数器
        for (int i = 1; i <= n; i++) {
            string ch;
            cin >> ch;
            if (ch == "IN") {
                int doctor, priority;
                scanf("%d %d", &doctor, &priority);
                id++;  // 递增时间戳
                pair<int, int> patient = make_pair(priority, id);  // <priority, time>
                if (doctor == 1) {
                    doc_a.push(patient);
                } else if (doctor == 2) {
                    doc_b.push(patient);
                } else if (doctor == 3) {
                    doc_c.push(patient);
                }
            } else {
                int doctor;
                scanf("%d", &doctor);
                if (doctor == 1) {
                    if (!doc_a.empty()) {
                        printf("%d\n", doc_a.top().second);  // 输出 id
                        doc_a.pop();
                    } else {
                        printf("EMPTY\n");
                    }
                } else if (doctor == 2) {
                    if (!doc_b.empty()) {
                        printf("%d\n", doc_b.top().second);
                        doc_b.pop();
                    } else {
                        printf("EMPTY\n");
                    }
                } else if (doctor == 3) {
                    if (!doc_c.empty()) {
                        printf("%d\n", doc_c.top().second);
                        doc_c.pop();
                    } else {
                        printf("EMPTY\n");
                    }
                }
            }
        }
    }
    return 0;
}