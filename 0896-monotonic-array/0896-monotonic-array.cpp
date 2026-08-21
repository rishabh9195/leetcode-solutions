class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool var1=true;
        bool var2=true;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
             var1=false;

            if(nums[i]>nums[i-1])
             var2=false;
        }
        return var1 || var2;
    }
};