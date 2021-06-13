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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (nullptr != fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }

    void test()
    {

        ListNode* dumy = new ListNode(0);
        ListNode* cur = dumy;
        cur->next = new ListNode(3);
        cur = cur->next;
        cur->next = new ListNode(2);
        cur = cur->next;
        cur->next = new ListNode(0);
        cur = cur->next;
        cur->next = new ListNode(4);
        std::cout << hasCycle(dumy->next) << std::endl;

        ListNode* dumy1 = new ListNode(0);
        cur = dumy1;
        cur->next = new ListNode(1);
        cur = cur->next;
        cur->next = new ListNode(2);
        cur = cur->next;
        cur->next = dumy1->next;
        std::cout << hasCycle(dumy1->next) << std::endl;


        ListNode* dumy2 = new ListNode(0);
        cur = dumy2;
        cur->next = new ListNode(1);
        cur = cur->next;
        std::cout << hasCycle(dumy2->next) << std::endl;
    }
};



int main(int argc, char* argv[])
{
    Solution solution;
    solution.test();
    return 0;
}