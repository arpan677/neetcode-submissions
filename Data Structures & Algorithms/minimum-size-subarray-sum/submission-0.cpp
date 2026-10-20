class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r=0;
        int l=0;
        int ans=INT_MAX;
        int cur_sum=0;
        while(r<nums.size()){
            cur_sum+=nums[r];


            while(cur_sum>=target){
                ans=min(r-l+1,ans);
                cur_sum-=nums[l];
                l++;
            }
            r++;


        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};