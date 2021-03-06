class Solution {
//1.transpose + reverse
//2.another method is iterating through every starting point, and for each starting point, rotate its corresponding 4 points.
//3.the third method is to iterate through each layer, for each layer, go through each ponit on each edge, for each point, rotate its 4 points.
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose matrix
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }
    // reverse each row
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - j - 1];
        matrix[i][n - j - 1] = tmp;
      }
    }
    }
};
