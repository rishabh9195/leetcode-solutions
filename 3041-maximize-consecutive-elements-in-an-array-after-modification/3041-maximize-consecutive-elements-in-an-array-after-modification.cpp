class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        unordered_map<int,int>dp;

        for(int x : nums)
        {
            dp[x+1]=dp[x]+1;
            dp[x]=dp[x-1]+1;
            ans=max({ans,dp[x+1],dp[x]});
        }
        return ans;
    }
};