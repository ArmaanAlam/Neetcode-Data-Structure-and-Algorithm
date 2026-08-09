class Solution {

    int BFS(vector<vector<int>>& grid,vector<vector<int>>& visit, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        visit[i][j] = 1;

        int perimeter = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int row = r + dr[k];
                int col = c + dc[k];

                if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0) {
                    perimeter++;
                }

                else if(!visit[row][col]) {
                    visit[row][col] = 1;
                    q.push({row, col});
                }
            }
        }

        return perimeter;
    }

public:

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    return BFS(grid, visit, i, j);
                }
            }
        }

        return 0;
    }
};