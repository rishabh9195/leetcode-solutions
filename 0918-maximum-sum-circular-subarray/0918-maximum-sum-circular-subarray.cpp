class Solution {
public:

    int maxsum(vector<int>& nums)
    {
        int ans=nums[0];
        int bestending=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            bestending=max(nums[i],bestending+nums[i]);
            ans=max(ans,bestending);
        }
        return ans;
    }

    int minsum(vector<int>& nums)
    {
        int ans=nums[0];
        int bestending=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            bestending=min(nums[i],bestending+nums[i]);
            ans=min(ans,bestending);
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int v1=maxsum(nums);
        if (v1 < 0)
            return v1;

        int v2=minsum(nums);

        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int v3=sum-v2;

        return max(v1,v3);
    }
};