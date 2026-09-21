class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next && curr->next->next) {
            ListNode* a = curr->next;
            ListNode* b = a->next;

            a->next = b->next;
            b->next = a;
            curr->next = b;

            curr = a;
        }

        return dummy.next;
    }
};