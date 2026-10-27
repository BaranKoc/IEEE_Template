class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;

    MinStack() {

    }

    void push(int val) {

        stk.push(val);

        if(minstk.size()==0)
            minstk.push(val);
        else{
            if(minstk.top()<val)
                minstk.push(minstk.top());
            else
                minstk.push(val);
        }
    }

    void pop() {
        stk.pop();
        minstk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};
