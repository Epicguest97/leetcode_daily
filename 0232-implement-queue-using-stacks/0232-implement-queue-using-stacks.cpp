class MyQueue {
private:
    stack<int> in, out;
    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
    
public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        transfer();
        int front = out.top();
        out.pop();
        return front;
    }
    
    int peek() {
        transfer();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
