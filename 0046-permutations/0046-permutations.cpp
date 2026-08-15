class Solution {
public:

    void fun(vector<int>&nums,vector<bool>&used, vector<int>&temp,vector<vector<int>>&ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(used[i]) continue;

            used[i]=true;
            temp.push_back(nums[i]);
            fun(nums,used,temp,ans);
            temp.pop_back();
            used[i]=false;
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int>temp;
        vector<vector<int>>ans;
        fun(nums,used,temp,ans);
        return ans;
    }
};