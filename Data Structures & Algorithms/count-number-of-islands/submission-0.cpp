class Solution {

    void DFS(vector<vector<char>>& grid, vector<vector<int>>& visit, int r, int c){

        int n = grid.size();
        int m = grid[0].size();

        visit[r][c] = 1;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int row = r + dr[i];
            int col = c + dc[i];

            if(row >= 0 && col >= 0 && row < n && col < m && !visit[row][col] && grid[row][col] == '1'){
                DFS(grid, visit, row, col);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j] && grid[i][j] == '1'){
                    cnt++;
                    DFS(grid, visit, i, j);
                }
            }
        }

        return cnt;
    }
};
