class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=0;
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]<nums[mini])
            {
                mini=i;
            }
            if(nums[i]>nums[maxi])
            {
                maxi=i;
            }
        }
        
        int left= min(mini,maxi);
        int right=max(mini,maxi);

        int opt1= right+1;
        int opt2= n-left;
        int opt3= (left+1)+(n-right);

        return min({opt1,opt2,opt3});
    }
};