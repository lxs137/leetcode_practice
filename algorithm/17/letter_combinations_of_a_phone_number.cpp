class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<int> digits_array;
            map<int, vector<char>> buttons;
            vector<string> res, temp;
            if(digits == "" || digits == "1")
                return res;
            buttons[2] = {'a', 'b', 'c'};
            buttons[3] = {'d', 'e', 'f'};
            buttons[4] = {'g', 'h', 'i'};
            buttons[5] = {'j', 'k', 'l'};
            buttons[6] = {'m', 'n', 'o'};
            buttons[7] = {'p', 'q', 'r', 's'};
            buttons[8] = {'t', 'u', 'v'};
            buttons[9] = {'w', 'x', 'y', 'z'};
            buttons[0] = {' '};
            for(int i = 0, n = digits.size(); i < n; i++) {
                digits_array.push_back(digits[i] - '0');
            }
            for(int digit : digits_array) {
                if(digit == 1)
                    continue;
                if(res.empty()) {
                    for(char c : buttons[digit]) {
                        res.push_back(string(1, c));                                    
                    }
                    continue;
                }
                temp.swap(res);
                res.clear();
                for(string s : temp) {
                    for(char c : buttons[digit]) {
                        res.push_back(string(s + string(1, c)));                    
                    }
                }
            }
            return res;
        }
};
