class Solution {
public:
    inline static int offset(int x, int y, int n) {
        return n * x + y;
    }

    vector<vector<int>> generateMatrix(int n) {
        auto mat = vector<vector<int>>();
        if (n == 0) {
            return mat;
        }

        int k = 1, x = 0, y = 0, len = n * n, batch = n, batchStart = 0, batchEnd = batch - 1;
        auto flatMat = vector<int>(len);
        while (batchStart <= batchEnd) {
            for (int j = batchStart; j < batchEnd; j++) {
                flatMat[offset(batchStart, j, n)] = k++;
            }
            for (int i = batchStart; i < batchEnd; i++) {
                flatMat[offset(i, batchEnd, n)] = k++;
            }
            for (int j = batchEnd; j > batchStart; j--) {
                flatMat[offset(batchEnd, j, n)] = k++;
            }
            for (int i = batchEnd; i > batchStart; i--) {
                flatMat[offset(i, batchStart, n)] = k++;
            }
            batch -= 2;
            batchStart += 1;
            batchEnd -= 1;
        }

        if (n % 2 == 1) {
            flatMat[offset(batchStart - 1, batchStart - 1, n)] = k;
        }

        for (int i = 0; i < n; i++) {
            auto line = vector<int>(n);
            memcpy(&line[0], &flatMat[i * n], sizeof(int) * n);
            mat.push_back(line);
        }

        return mat;
    }
};