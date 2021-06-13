#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* dumy = new ListNode(0);
        ListNode* cur = dumy;
        while (nullptr != l1 && nullptr != l2)
        {
            int il1 = l1->val;
            int il2 = l2->val;
           
            if (il1 < il2)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        cur->next = l1 == nullptr ? l2 : l1;

        return dumy->next;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1)
        {
            return l2;
        }

        if (nullptr == l2)
        {
            return l1;
        }
        
        if (l1->val >= l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            l2 = l1;
        }

        return l2;
    }

    void PirintList(ListNode* list) {
        std::cout << std::endl;
        if (nullptr == list)
        {
            return;
        }

        ListNode* tempList = list;
        while (nullptr != tempList)
        {
            std::cout << tempList->val << std::endl;
            tempList = tempList->next;
        }
    }
};

// [1,2,4]
// [1,3,4]

int test()
{
    ListNode* l1 = new ListNode();
    l1->val = 1;
    
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(4);
    l2->next = l3;
    l1->next = l2;

    ListNode* r1 = new ListNode();
    r1->val = 1;
    ListNode* r2 = new ListNode(3);
    ListNode* r3 = new ListNode(4);
    r2->next = r3;
    r1->next = r2;

    Solution* newSolution = new Solution();
    newSolution->PirintList(l1);
    newSolution->PirintList(r1);

    ListNode* mergeList = newSolution->mergeTwoLists(l1, r1);
    newSolution->PirintList(mergeList);
    return 0;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}