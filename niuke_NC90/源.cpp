#include <stack>
class Solution {
public:
    void push(int value) {
        if (_st.empty()) {
            _st.push(value);
            _min.push(value);
        }
        else {
            _st.push(value);
            if (_min.top() > value)
                _min.push(value);
            else
                _min.push(_min.top());
        }
    }
    void pop() {
        _st.pop();
        _min.pop();
    }
    int top() {
        return _st.top();
    }
    int min() {
        return _min.top();
    }
private:
    stack<int> _st;
    stack<int> _min;
};