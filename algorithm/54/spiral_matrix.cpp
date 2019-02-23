class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        } else if (matrix.size() == 1) {
            res.insert(res.begin(), matrix[0].begin(), matrix[0].end());
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m - 1, startCol = 0, endCol = n - 1;
        while (startRow <= endRow && startCol <= endCol) {
            if (startRow == endRow) {
                for (int j = startCol; j <= endCol; j++) {
                    res.push_back(matrix[startRow][j]);                    
                }
            } else if (startCol == endCol) {
                for (int i = startRow; i <= endRow; i++) {
                    res.push_back(matrix[i][endCol]);
                }
            } else {
                for (int j = startCol; j <= endCol - 1; j++) {
                    res.push_back(matrix[startRow][j]);
                }
                for (int i = startRow; i <= endRow - 1; i++) {
                    res.push_back(matrix[i][endCol]);
                }
                for (int j = endCol; j >= startCol + 1; j--) {
                    res.push_back(matrix[endRow][j]);
                }
                for (int i = endRow; i >= startRow + 1; i--) {
                    res.push_back(matrix[i][startCol]);
                }
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return res;
    }
};