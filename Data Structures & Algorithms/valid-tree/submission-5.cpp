class Solution {
public:

    bool cycle(int par,int src,vector<bool>&vis,  vector<vector<int>>&graph){
        vis[src]=true;
        for(int i:graph[src]){
            if(!vis[i]){
              bool check= cycle(src,i,vis,graph);
              if(check) return true;
            }
            else if(i!=par) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() < n - 1) {
            return false;
        }
        
        
            vector<vector<int>>graph(n);


        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
              graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){

                bool check=cycle(-1,i,vis,graph);
                if(check) return false;

            }
        }

        return true;

    }
};
