struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        auto p1 = pHead;
        auto p2 = pHead;
        while (p1 && p2)
        {
            p1 = p1->next;
            if (p2->next) p2 = p2->next->next;
            else return nullptr;

            if (p1 == p2)
            {
                auto p3 = pHead;
                while (p3 != p1)
                {
                    p3 = p3->next;
                    p1 = p1->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};