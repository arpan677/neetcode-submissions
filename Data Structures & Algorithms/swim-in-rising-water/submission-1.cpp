class Solution {
   public:
    bool val(vector<vector<int>>& grid, int mid) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] > mid) return false;

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({0, 0});
    vis[0][0] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i == n - 1 && j == m - 1)
            return true;

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj] && grid[ni][nj] <= mid) {

                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    return false;
}

    int swimInWater(vector<vector<int>>& grid) {
        int low=INT_MAX;
        int high=INT_MIN;
         int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j:grid[i]){
                low=min(low,j);
                high=max(high,j);
            }
        }
        while(low<=high){
            int mid=(low+high)/2;
            bool check=val(grid,mid);
            if(check)
            high=mid-1;
            else low=mid+1;
        }
       
        return low;
    }
};
