/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
             vector<int> ans = {-1, -1};
        int pos = 1, first = -1, prev = -1, mn = INT_MAX;

        while (head && head->next && head->next->next) {
            int a = head->val;
            int b = head->next->val;
            int c = head->next->next->val;

            if ((b > a && b > c) || (b < a && b < c)) {
                if (first == -1)
                    first = pos;
                else {
                    mn = min(mn, pos - prev);
                    ans[1] = pos - first;
                }
                prev = pos;
            }

            head = head->next;
            pos++;
        }

        if (ans[1] == -1) return ans;
        ans[0] = mn;
        return ans; 
    }
};