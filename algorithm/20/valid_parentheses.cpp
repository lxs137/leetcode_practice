class Solution {
    public:
        bool isValid(string s) {
            stack<char> c_stack;
            map<char, char> match;
            match['('] = ')', match[')'] = '(';
            match['{'] = '}', match['}'] = '{';
            match['['] = ']', match[']'] = '[';
            for(int i = 0, n = s.size(); i < n; i++) {
                if(c_stack.empty() || match[c_stack.top()] != s[i]) {
                    c_stack.push(s[i]);
                }
                else {
                    c_stack.pop();
                }
            }
            return c_stack.empty();
        }
};
