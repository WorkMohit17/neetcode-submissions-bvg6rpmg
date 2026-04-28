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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;

        int size = 0;
        ListNode* temp = head;
        
        while (temp) {
            size++;
            temp = temp->next;
        }

        int c = size - n;

        if (c == 0) {
            return head->next;
        }

        temp = head;
        for (int i = 0; i < c - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};