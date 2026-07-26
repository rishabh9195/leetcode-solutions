class Solution {
public:
    int trap(vector<int>& height) {
        /*solution 1:
        int n= height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        leftmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i]);
        }

        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }

        int water=0;
        for(int i=0;i<n;i++)
        {
            water+=min(leftmax[i],rightmax[i])-height[i];
        }
        return water;*/

        //brute force

        int n= height.size();
        int left=0;
        int right= n-1;

        int leftmax=0;
        int rightmax=0;

        int water=0;

        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>leftmax)
                {
                    leftmax=height[left];
                }
                else
                {
                    water+=leftmax-height[left];
                }
                left++;
            }
            else
            {
                if(height[right]>rightmax)
                {
                    rightmax=height[right];
                }
                else
                {
                    water+=rightmax-height[right];
                }
                right--;
            }
        }
        return water;

    }
};