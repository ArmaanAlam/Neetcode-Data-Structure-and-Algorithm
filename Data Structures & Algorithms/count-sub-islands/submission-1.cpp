class Solution {

    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, 
            vector<vector<bool>> &visit, int r, int c){

                int n = grid2.size();
                int m = grid2[0].size();

                visit[r][c] = true;

                bool isSubIsland = (grid1[r][c] == 1);

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int i = 0; i < 4; i++){
                    int row = r + dr[i];
                    int col = c + dc[i];

                    if(row < 0 || col < 0 || row >= n || col >= m || visit[row][col]){
                        continue;
                    }

                    if(grid2[row][col] == 1 && !visit[row][col]) {
                        if(!DFS(grid1, grid2, visit, row, col)) {
                            isSubIsland = false;
                        }
                    } 
                }

                return isSubIsland;

            }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] && grid1[i][j] && !visit[i][j]){
                    if(DFS(grid1, grid2, visit, i, j)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
