class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return rotateN(matrix, n);
    }
    void rotateN(vector<vector<int>>& matrix, int n) {
        if (n <= 1) {
            return;
        } else {
            int start = (matrix.size() - n) / 2, end = start + n - 1, temp;
            for (int k = 0; k < n - 1; k++) {
                temp = matrix[start][start];
                for (int j = start + 1; j <= end; j++) {
                    swap(matrix[start][j], temp);
                }
                for (int i = start + 1; i <= end; i++) {
                    swap(matrix[i][end], temp);
                }
                for (int j = end - 1; j >= start; j--) {
                    swap(matrix[end][j], temp);
                }
                for (int i = end - 1; i >= start; i--) {
                    swap(matrix[i][start], temp);
                }                
            }
            return rotateN(matrix, n - 2);
        }
    }
};