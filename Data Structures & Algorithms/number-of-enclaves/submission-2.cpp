class Solution {

    void BFS(vector<vector<int>>& grid, vector<vector<int>>& visit, queue<pair<int, int>> q){

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row >= 0 && col >= 0 && row < n && col < m && !visit[row][col] && grid[row][col]){
                    visit[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            if(!visit[i][0] && grid[i][0]){
                visit[i][0] = 1;
                q.push({i, 0});
            }
            if(!visit[i][m-1] && grid[i][m-1]){
                visit[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        for(int j = 0; j < m; j++){
            if(!visit[0][j] && grid[0][j]){
                visit[0][j] = 1;
                q.push({0, j});
            }
            if(!visit[n-1][j] && grid[n-1][j]){
                visit[n-1][j] = 1;
                q.push({n-1, j});
            }
        }

        BFS(grid, visit, q);

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