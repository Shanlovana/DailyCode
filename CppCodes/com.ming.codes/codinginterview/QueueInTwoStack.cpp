//
// Created by android on 19-8-14.
//
/*题目：
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 * 队列是先进先出，栈是先进后出，如何用两个栈来实现这种先进先出呢？
 * 其实很简单，我们假设用stack1专门来装元素，那么直接stack1.pop肯定是不行的，这个时候stack2就要发挥作用了。
 * 我们的规则是：只要stack2中有元素就pop，如果stack2为空，则将stack1中所有元素倒进satck2中，就是说，新元素只进stack1，元素出来只从stack2出来。
 * 直到stack2的为空，stack1再将值倒入stack2中
 * 这样子，就能保证每次从stack2中pop出来的元素就是最老的元素了。
 * */
#include <stack>
#include <gtest/gtest.h>

using namespace std;

class Solution {
private:
    stack<int> stackOne;
    stack<int> stackTwo;
public:
    void push(int node) {
        stackOne.push(node);
    }

    int pop() {
        if (stackTwo.empty()) {
            while (stackOne.size() > 0) {
                int data = stackOne.top();
                stackOne.pop();
                stackTwo.push(data);
            }
        }
        int pop_ele = stackTwo.top();
        stackTwo.pop();
        return pop_ele;
    }
};

TEST(queue, pop) {
    Solution solution;
    solution.push(1);
    solution.push(2);
    solution.push(3);
    solution.push(4);
    solution.push(5);

    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;

}