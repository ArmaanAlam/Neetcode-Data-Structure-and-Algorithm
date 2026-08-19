class Solution {

    void DFS(vector<vector<int>>& grid, vector<vector<int>>& visit, int r, int c){

        int n = grid.size();
        int m = grid[0].size();

        visit[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int row = r + dr[i];
            int col = c + dc[i];

            if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] && !visit[row][col]){
                DFS(grid, visit, row, col);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(!visit[i][0] && grid[i][0]){
                DFS(grid, visit, i, 0);
            }
            if(!visit[i][m-1] && grid[i][m-1]){
                DFS(grid, visit, i, m-1);
            }
        }

        for(int j = 0; j < m; j++){
            if(!visit[0][j] && grid[0][j]){
                DFS(grid, visit, 0, j);
            }
            if(!visit[n-1][j] && grid[n-1][j]){
                DFS(grid, visit, n-1, j);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && visit[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;

    }
};