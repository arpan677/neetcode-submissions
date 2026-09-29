class Solution {
public:

    void bfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             queue<pair<int,int>>& q) {

        int n = heights.size();
        int m = heights[0].size();

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !ocean[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {

                    ocean[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;


        // Pacific: top row + left column
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            qp.push({0, j});
        }

        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            qp.push({i, 0});
        }


        // Atlantic: bottom row + right column
        for (int j = 0; j < m; j++) {
            atlantic[n-1][j] = true;
            qa.push({n-1, j});
        }

        for (int i = 0; i < n; i++) {
            atlantic[i][m-1] = true;
            qa.push({i, m-1});
        }


        // Reverse BFS
        bfs(heights, pacific, qp);
        bfs(heights, atlantic, qa);


        vector<vector<int>> ans;

        // Find cells reachable by BOTH oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};