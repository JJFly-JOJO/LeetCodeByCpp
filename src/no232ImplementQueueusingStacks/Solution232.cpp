#include <stack>

class MyQueue {
   public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop()
    {
        if (s2.empty())
        {
            s12s2();
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }

    int peek()
    {
        if (s2.empty())
        {
            s12s2();
        }
        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }

   private:
    std::stack<int> s1;
    std::stack<int> s2;

    void s12s2()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
};