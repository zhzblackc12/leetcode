#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.
    
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!rightStack.empty())
        {
            int popValue = rightStack.top();
            rightStack.pop();
            leftStack.push(popValue);
        }

        leftStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int popValue = peek();
        rightStack.pop();
        return popValue;
    }
    
    /** Get the front element. */
    int peek() {
        while (!leftStack.empty())
        {
            int popValue = leftStack.top();
            leftStack.pop();
            rightStack.push(popValue);
        }

        int popValue = rightStack.top();
        return popValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return leftStack.empty() && rightStack.empty();
    }
    
private: 
    std::stack<int>  leftStack;
    std::stack<int>  rightStack;
};
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// ' +
//   '[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]



int main(int argc, char* argv[])
{
     MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    std::cout << obj->peek() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->peek() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->peek() << std::endl;
    std::cout << obj->pop() << std::endl;
    obj->push(4);
    return 0;
}