
class Solution { 
public: 
 
    bool helper(int n1, int n2, vector<vector<int>>& heights, vector<vector<bool>> vis) { 
        vis[n1][n2] = true; 
        int n = heights.size(); 
        int m = heights[0].size(); 
 
        bool pacific = false; 
        bool atlantic = false; 
 
        queue<pair<int,int>> q; 
        q.push({n1,n2}); 
 
        while(!q.empty()) { 
            int i = q.front().first; 
            int j = q.front().second; 
 
            q.pop(); 
 
            if(i == 0 || j == 0) { 
                pacific = true; 
            } 
 
            if(i == n-1 || j == m-1) { 
                atlantic = true; 
            } 
 
            if(pacific && atlantic) { 
                return true; 
            } 
 
            // right
            if(i+1 < n && !vis[i+1][j] && 
               heights[i+1][j] <= heights[i][j]) { 
                q.push({i+1,j}); 
                vis[i+1][j] = true; 
            } 
 
            // left
            if(i-1 >= 0 && !vis[i-1][j] && 
               heights[i-1][j] <= heights[i][j]) { 
                q.push({i-1,j}); 
                vis[i-1][j] = true; 
            } 
 
            // down
            if(j+1 < m && !vis[i][j+1] && 
               heights[i][j+1] <= heights[i][j]) { 
                q.push({i,j+1}); 
                vis[i][j+1] = true; 
            } 
 
            // up
            if(j-1 >= 0 && !vis[i][j-1] && 
               heights[i][j-1] <= heights[i][j]) { 
                q.push({i,j-1}); 
                vis[i][j-1] = true; 
            } 
        } 
 
        return pacific && atlantic; 
    } 
 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 
        vector<vector<int>> ans; 
 
        int n = heights.size(); 
        int m = heights[0].size(); 
 
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) { 
 
                vector<vector<bool>> vis(n, vector<bool>(m, false)); 
 
                if(helper(i, j, heights, vis)) { 
                    ans.push_back({i,j}); 
                } 
            } 
        } 
 
        return ans; 
    } 
};

