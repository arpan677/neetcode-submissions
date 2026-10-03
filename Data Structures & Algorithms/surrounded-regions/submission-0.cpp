class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        auto add = [&](int r, int c) {
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O') {
                board[r][c] = '#';
                q.push({r, c});
            }
        };

        // Boundary rows
        for (int j = 0; j < m; j++) {
            add(0, j);
            add(n - 1, j);
        }

        // Boundary columns
        for (int i = 1; i < n - 1; i++) {
            add(i, 0);
            add(i, m - 1);
        }

        // BFS
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                add(r + dr[k], c + dc[k]);
            }
        }

        // Convert
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};