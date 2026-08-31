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
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        vector<int> critical;
        ListNode* curr = head->next;
        ListNode* prev = head;
        int count = 0;
        while (curr->next != NULL) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(count);
            }
            prev = curr;
            curr = next;
            count++;
        }

        int ans = INT_MAX;
        for (int i = 1; i < critical.size(); i++) {
            ans = min(critical[i] - critical[i - 1], ans);
        }

        if (ans == INT_MAX) {
            return {-1, -1};
        }

        return {ans, critical[critical.size() - 1] - critical[0]};
    }
};