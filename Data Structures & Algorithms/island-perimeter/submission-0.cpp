class Solution {

    int DFS(vector<vector<int>>& grid, vector<vector<int>>& visit, int i, int j){

        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 1;
        }
        
        if(visit[i][j]){
            return 0;
        }
        visit[i][j] = 1;

        int primeter = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int k = 0; k < 4; k++){
            int row = i + dr[k];
            int col = j + dc[k];

            primeter += DFS(grid, visit, row, col);
        }

        return primeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    return DFS(grid, visit, i, j);
                }
            }
        }


    }
};