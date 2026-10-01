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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;      // 0 or 1 node: nothing to do

        // 1. SPLIT — fast starts at head->next, so slow lands on the LAST node
        //    of the first half (first middle on even lengths).
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. CUT — the cycle-preventer. Save the second half, then sever.
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. REVERSE the second half. prev ends as its new head.
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* nxt = curr->next;   // save — ground floor rule
            curr->next = prev;            // flip
            prev = curr;                  // grow reversed prefix
            curr = nxt;                   // advance
        }
        second = prev;                    // second half now starts at the old tail

        // 4. WEAVE — stop as soon as the shorter (second) half runs out.
        ListNode* first = head;
        while (second) {
            ListNode* fnext = first->next;    // save both before rewiring
            ListNode* snext = second->next;
            first->next  = second;            // first -> second
            second->next = fnext;             // second -> rest of first
            first  = fnext;
            second = snext;
        }
    }
};
