#include <iostream>
#include <string>
#include <stack>

using namespace std;
    
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* before = nullptr;
        ListNode* cur = nullptr;
        ListNode* after = head;

        if (nullptr != after && nullptr != after->next)
        {
            return after;
        }

        while (nullptr != after)
        {
            before = cur;
            cur = after;
            after = cur->next;
            cur->next = before;
        }
        
        return cur;        
    }


    //! 回文
    bool reverseList1(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (nullptr != fast->next && nullptr != fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;
        ListNode* cur = head;
        if (nullptr == fast->next)
        {
            middle = slow->next;
        }

        while (nullptr != middle)
        {
            if (cur->val != middle->val)
            {
                return false;
            }
            cur = cur->next;
            middle = middle->next;
        }
        return true;        
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

    void test()
    {
        ListNode* dumy = new ListNode(0);
        ListNode* cur = dumy;
        cur->next = new ListNode(1);
        cur = cur->next;
        cur->next = new ListNode(2);
        cur = cur->next;
        cur->next = new ListNode(3);
        cur = cur->next;
        PirintList(reverseList(dumy->next));
        
        ListNode* dumy1 = new ListNode(0);
        cur = dumy1;
        cur->next = new ListNode(1);
        cur = cur->next;
        cur->next = new ListNode(2);
        cur = cur->next;
        cur->next = new ListNode(3);
        cur = cur->next;
        cur->next = new ListNode(4);
        cur = cur->next;
        PirintList(reverseList(dumy1->next));
    }
};



int main(int argc, char* argv[])
{
    Solution solution;
    solution.test();
    return 0;
}