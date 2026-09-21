class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto x : lists) if (x) pq.push(x);

        ListNode dummy(0), *cur = &dummy;

        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            cur->next = x;
            cur = x;
            if (x->next) pq.push(x->next);
        }

        return dummy.next;
    }
};