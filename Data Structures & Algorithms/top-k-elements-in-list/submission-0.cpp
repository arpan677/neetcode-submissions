class Solution { 
public: 
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        int n = nums.size(); 
        unordered_map<int, int> mp; 
        
        for(int i : nums) 
            mp[i]++; 
        
        vector<vector<int>> bucket(n + 1); 
 
        for(auto i : mp) { 
            bucket[i.second].push_back(i.first); 
        } 
        
        vector<int> ans; 
         
        for(int i = n; i >= 0; i--) { 
            if(k == 0) break; 
 
            for(int x : bucket[i]) {
                ans.push_back(x);
                k--;
                if(k == 0) break;
            }
        } 
        
        return ans; 
    } 
};