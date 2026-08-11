class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        int oldcolor = image[sr][sc];

        if(oldcolor == color) return image;

        vector<vector<int>>visit(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        visit[sr][sc] = 1;
        image[sr][sc] = color;
        q.push({sr, sc});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row < 0 || col < 0 || row >= n || col >= m){
                    continue;
                }

                if(visit[row][col] == 0 && image[row][col] == oldcolor){
                    visit[row][col] = 1;
                    image[row][col] = color;
                    q.push({row, col});
                }
            }
        }


        return image;
    }
};