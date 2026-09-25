class Solution {
public:

    int nextindex(int i, vector<int>& nums)
    {
        int n=nums.size();
        return ((i + nums[i])%n + n) % n;
    } 

    bool circularArrayLoop(vector<int>& nums) {

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            bool forward= nums[i]>0;
            int slow=i;
            int fast=i;

            while(true)
            {
                int nextslow=nextindex(slow,nums);

                if((nums[nextslow]>0)!=forward)
                    break;
                
                if(nextslow==slow)
                    break;

                slow=nextslow;

                int nextfast=nextindex(fast,nums);

                if((nums[nextfast]>0)!=forward)
                    break;
                
                if(nextfast==fast)
                    break;

                fast=nextfast;

                nextfast=nextindex(fast,nums);

                if((nums[nextfast]>0)!=forward)
                    break;
                
                if(nextfast==fast)
                    break;

                fast=nextfast;

                if(slow==fast)
                    return true;
            }
        }
        return false;
    }
};