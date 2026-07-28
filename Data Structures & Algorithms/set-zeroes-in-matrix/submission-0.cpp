class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>>index;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    index.push_back({i, j});
                }
            }
        }

        for(auto it : index){
            int row = it.first;
            int col = it.second;

            for(int i = 0; i < n; i++){
                matrix[i][col] = 0;
            }

            for(int i = 0; i < m; i++){
                matrix[row][i] = 0;
            }
        }
    }
};
