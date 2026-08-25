class Solution {

    int DFS(vector<vector<int>>& grid, vector<vector<int>>& visit, int r, int c){

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        visit[r][c] = 1;

        int area = 1;

        for(int i = 0; i < 4; i++){
            int row = r + dr[i];
            int col = c + dc[i];

            if(row >= 0 && col >= 0 && row < n && col < m && !visit[row][col] && grid[row][col]){
                area += DFS(grid, visit, row, col);
            }
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int max_area = 0;

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j] && grid[i][j] == 1){
                    int area = DFS(grid, visit, i, j);
                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }
};
