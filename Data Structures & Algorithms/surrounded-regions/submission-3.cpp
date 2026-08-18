class Solution {

    void DFS(vector<vector<char>> &board,
             vector<vector<int>> &visit,
             int r, int c) {

        visit[r][c] = 1;

        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++) {

            int row = r + dr[i];
            int col = c + dc[i];

            if(row >= 0 && col >= 0 &&
               row < n && col < m &&
               !visit[row][col] &&
               board[row][col] == 'O') {

                DFS(board, visit, row, col);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        if(board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {

            if(!visit[i][0] && board[i][0] == 'O') {
                DFS(board, visit, i, 0);
            }

            if(!visit[i][m-1] && board[i][m-1] == 'O') {
                DFS(board, visit, i, m-1);
            }
        }

        for(int j = 0; j < m; j++) {

            if(!visit[0][j] && board[0][j] == 'O') {
                DFS(board, visit, 0, j);
            }

            if(!visit[n-1][j] && board[n-1][j] == 'O') {
                DFS(board, visit, n-1, j);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O' && !visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};