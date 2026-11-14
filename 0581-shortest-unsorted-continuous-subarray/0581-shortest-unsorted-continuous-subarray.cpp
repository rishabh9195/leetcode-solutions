class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=-1;
        int right=-1 ;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1] && left==-1)
            {
                left=i;
            }
        }

        for(int j=n-1;j>0;j--)
        {
            if(nums[j]<nums[j-1])
            {
                right=j;
                break;
            }
        }

            if(left == -1)
                return 0;
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=left;i<=right;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }

        while(left>0 && mini<nums[left-1])
        {
            left--;
        }
        while(right<n-1 && maxi>nums[right+1])
        {
            right++;
        }

        return right-left+1;
    }
};