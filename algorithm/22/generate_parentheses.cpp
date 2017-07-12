class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res, temp;
            if(n == 0)
                return res;
            res.emplace_back("()");
            n--;
            if(n <= 0) 
                return res;
            while(n >= 1) {
                temp.clear();
                temp.swap(res);
                for(int i = 0, size = temp.size(); i < size; i++) {
                    res.emplace_back(string("(") + temp[i] + string(")"));
                }
                for(int i = 0, size = temp.size(); i < size; i++) {
                    if(i == size - 1) {
                        res.emplace_back(temp[i] + string("()"));
                    }
                    else {
                        res.emplace_back(temp[i]+ string("()"));
                        res.emplace_back(string("()") + temp[i]);
                    }
                }
                n--;
            }
            return res;

        }
};
