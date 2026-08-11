class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int fresh = 0;

        // Put all rotten oranges into queue
        // and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {

                    int row = r + dr[i];
                    int col = c + dc[i];

                    if (row < 0 || col < 0 ||
                        row >= n || col >= m) {
                        continue;
                    }

                    if (grid[row][col] == 1 &&
                        visited[row][col] == 0) {

                        grid[row][col] = 2;
                        visited[row][col] = 1;

                        fresh--;

                        q.push({row, col});
                    }
                }
            }

            time++;
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};