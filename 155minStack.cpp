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
 

class MinStack {

public:
    /** initialize your data structure here. */
     /** initialize your data structure here. */
    MinStack() {
        minValue = INT_MAX;
    }
    
    void push(int val) {
        if (val < minValue)
        {
            minValue = val;
        }
        
        dataStack.push(val);
        minValueStack.push(minValue);

    }
    
    void pop() {
        dataStack.pop();
        minValueStack.pop();
        if (minValueStack.empty())
        {
            minValue = INT_MAX;
        }
        else
        {
            minValue = minValueStack.top();
        }
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minValueStack.top();
    }


private:
    std::stack<int>   dataStack;
    std::stack<int>   minValueStack;
    int               minValue;
};

// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// ' +
//   '[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

void test()
{
    MinStack* obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483646);
    int param_3 = obj->top();
    obj->pop();
    int param_4 = obj->getMin();
    obj->pop();
    int param_5 = obj->getMin();
    obj->pop();
    obj->push(2147483646);




    std::cout << param_3 << "   " << param_4 << std::endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}