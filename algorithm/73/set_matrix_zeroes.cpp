class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    int height = matrix.size(), width = matrix[0].size();
    bool setRow = false, setCol = false;

    if (matrix[0][0] == 0) {
        setRow = true;
        setCol = true;
    } else {
        for (int i = 1; i < height; i++) {
            if (matrix[i][0] == 0) {
                setCol = true;
                break;
            }
        }
        for (int j = 1; j < width; j++) {
            if (matrix[0][j] == 0) {
                setRow = true;
                break;
            }
        }
    }

    for (int i = 1; i < height; i++) {
      for (int j = 1; j < width; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < height; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < width; j++) {
          matrix[i][j] = 0;
        }        
      }
    }

    for (int j = 1; j < width; j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < height; i++) {
          matrix[i][j] = 0;
        }        
      }
    }
    
    if (setCol) {
      for (int i = 0; i < height; i++) {
        matrix[i][0] = 0;
      }
    }

    if (setRow) {
       for (int j = 0; j < width; j++) {
        matrix[0][j] = 0;
      } 
    }
  }
};
