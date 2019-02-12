class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> nums;
        for(int i = 0; i < 9; i++) {
            nums.clear();
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (num < 1 || num > 9)
                    return false;
                auto res = nums.insert(num);
                if (!res.second)
                    return false;
            }
        }
        for(int j = 0; j < 9; j++) {
            nums.clear();
            for(int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (num < 1 || num > 9)
                    return false;
                auto res = nums.insert(num);
                if (!res.second)
                    return false;
            }
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                nums.clear();
                for(int sub_i = i, sub_i_end = i + 3; sub_i < sub_i_end; sub_i++) {
                    for(int sub_j = j, sub_j_end = j + 3; sub_j < sub_j_end; sub_j++) {
                        if (board[sub_i][sub_j] == '.')
                            continue;
                        int num = board[sub_i][sub_j] - '0';
                        if (num < 1 || num > 9)
                            return false;
                        auto res = nums.insert(num);
                        if (!res.second)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};