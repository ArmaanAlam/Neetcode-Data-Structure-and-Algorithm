class Solution {

    void BFS(vector<vector<int>>& grid,
             vector<vector<bool>>& visit,
             int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        visit[row][col] = false;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 0 &&
                   visit[nrow][ncol]) {

                    q.push({nrow, ncol});
                    visit[nrow][ncol] = false;
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // true = unvisited, false = visited
        vector<vector<bool>> visit(
            n, vector<bool>(m, true)
        );

        // 1. Left border
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0 && visit[i][0]) {
                BFS(grid, visit, i, 0);
            }
        }

        // 2. Right border
        for(int i = 0; i < n; i++) {
            if(grid[i][m-1] == 0 && visit[i][m-1]) {
                BFS(grid, visit, i, m-1);
            }
        }

        // 3. Top border
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 0 && visit[0][j]) {
                BFS(grid, visit, 0, j);
            }
        }

        // 4. Bottom border
        for(int j = 0; j < m; j++) {
            if(grid[n-1][j] == 0 && visit[n-1][j]) {
                BFS(grid, visit, n-1, j);
            }
        }

        // Count the remaining closed islands
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0 && visit[i][j]) {
                    cnt++;
                    BFS(grid, visit, i, j);
                }
            }
        }

        return cnt;
    }
};