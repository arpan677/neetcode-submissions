class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
   int INF = 2147483647;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            if(i-1 > -1 && grid[i-1][j] == INF){
                grid[i-1][j] = t+1;
                q.push({{i-1,j},t+1});
            }

            if(j-1 > -1 && grid[i][j-1] == INF){
                grid[i][j-1] = t+1;
                q.push({{i,j-1},t+1});
            }

            if(i+1 < n && grid[i+1][j] == INF){
                grid[i+1][j] = t+1;
                q.push({{i+1,j},t+1});
            }

            if(j+1 < m && grid[i][j+1] == INF){
                grid[i][j+1] = t+1;
                q.push({{i,j+1},t+1});
            }
        }
    }
};