#include <iostream>
#include <string>
#include <stack>

using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.
    
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (nullptr == head)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (nullptr != fast->next && nullptr != fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = slow;
        if (nullptr != fast->next)
        {
            middle = middle->next;
        }

        return middle;
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
        PirintList(middleNode(dumy->next));
        
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
        PirintList(middleNode(dumy1->next));
    }
};



int main(int argc, char* argv[])
{
    Solution solution;
    solution.test();
    return 0;
}