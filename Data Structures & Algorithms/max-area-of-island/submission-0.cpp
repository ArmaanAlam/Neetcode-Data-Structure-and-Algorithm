class Solution {

    int BFS(vector<vector<int>>& grid, vector<vector<int>>& visit, int i, int j){

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        int area = 1;

        queue<pair<int, int>> q;
        visit[i][j] = 1;
        q.push({i, j});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int row = r + dr[k];
                int col = c + dc[k];

                if(row >= 0 && col >= 0 && row < n && col < m && !visit[row][col] && grid[row][col]){
                    visit[row][col] = 1;
                    q.push({row, col});
                    area++;
                }
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
                    int area = BFS(grid, visit, i, j);
                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }
};
