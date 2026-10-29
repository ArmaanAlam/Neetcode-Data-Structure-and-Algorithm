class Solution {

    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& visit, int row, int col){
        int n = heights.size();
        int m = heights[0].size();

        if(visit[row][col]) return;
        visit[row][col] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) continue;

            if(heights[nrow][ncol] >= heights[row][col]){
                DFS(heights, visit, nrow, ncol);
            }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            DFS(heights, pacific, i, 0);
        }

        for(int j = 0; j < m; j++){
            DFS(heights, pacific, 0, j);
        }

        for(int i = 0; i < n; i++){
            DFS(heights, atlantic, i, m-1);
        }

        for(int j = 0; j < m; j++){
            DFS(heights, atlantic, n-1, j);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
