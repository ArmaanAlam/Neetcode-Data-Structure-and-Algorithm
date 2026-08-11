class Solution {

    void DFS(vector<vector<int>>& image,vector<vector<int>>& visit, int row, int col, int oldcolor, int color){

        int n = image.size();
        int m = image[0].size();
        
        visit[row][col] = 1;
        image[row][col] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int r = row + dr[i];
            int c = col + dc[i];

            if(r < 0 || c < 0 || r >= n || c >= m){
                continue;
            }

            if(visit[r][c] == 0 && image[r][c] == oldcolor){
                DFS(image, visit, r, c, oldcolor, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        int oldcolor = image[sr][sc];
        if(oldcolor == color) return image;

        vector<vector<int>> visit(n, vector<int>(m, 0));

        DFS(image, visit, sr, sc, oldcolor, color);

        return image;
    }
};