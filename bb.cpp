#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        auto dum = new ListNode(0, head), cur = dum;
        unordered_map<int, ListNode *> dic;
        int sum{};
        while (cur) {
            sum += cur->val;
            dic[sum] = cur;
            cur = cur->next;
        }
        sum = 0;
        cur = dum;
        while (cur) {
            sum += cur->val;
            auto tmp = dic[sum]->next, pre{cur->next};
            ListNode *t;
            while (pre != tmp) {
                t = pre->next;
                delete pre;
                pre = t;
            }
            cur->next = tmp;
            cur = cur->next;
        }
        return dum->next;
    }
};

int main(int argc, char *argv[]) {
    //
    Solution s;
    ListNode *head = new ListNode(1);
    auto cur = head;
    cur->next = new ListNode(2), cur = cur->next;
    cur->next = new ListNode(-3), cur = cur->next;
    cur->next = new ListNode(3), cur = cur->next;
    cur->next = new ListNode(1);
    auto ans = s.removeZeroSumSublists(head);
    cur = ans;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}
