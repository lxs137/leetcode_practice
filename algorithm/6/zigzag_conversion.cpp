class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows < 2 || s.size() <= numRows)
                return s;
            vector<char*> mat;
            char *col;
            bool odd_col = false;
            for(int i = 0, j, n = s.size(); i < n;) {
                col = new char[numRows]();
                if(odd_col) {
                    for(j = 0; j < numRows - 2 && i + j < n; j++) {
                        col[numRows - j - 2] = s[i + j];
                    }
                }
                else {
                    for(j = 0; j < numRows && i + j < n; j++) {
                        col[j] = s[i + j];
                    }   
                }
                i += j;
                odd_col = !odd_col;
                mat.push_back(col);
            }
            string output;
            for(int j = 0; j < numRows; j++) {
                for(int i = 0, n = mat.size(); i < n; i++) {
                    if(mat[i][j])
                        output.append(1, mat[i][j]);
                }
            }
            return output;
        }
};
