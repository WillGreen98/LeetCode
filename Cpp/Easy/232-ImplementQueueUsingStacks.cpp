/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    private:
        stack<int> in_stack;
        stack<int> out_stack;

        void transferInToOut() {
            while(!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    public:
        MyQueue() {}

        void push(int x) {
            in_stack.push(x);
        }

        int pop() {
            if(out_stack.empty()) transferInToOut();

            if(!out_stack.empty()) {
                int front = out_stack.top();
                out_stack.pop();

                return front;
            } else {
                return -1;
            }
        }

        int peek() {
            if(out_stack.empty()) transferInToOut();
            if(!out_stack.empty()) {
                return out_stack.top();
            } else {
                return -1;
            }
        }

        bool empty() {
            return in_stack.empty() && out_stack.empty();
        }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end