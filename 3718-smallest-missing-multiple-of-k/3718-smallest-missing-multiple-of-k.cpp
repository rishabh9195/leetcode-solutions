class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> freq(101,false);

        for(int x:nums)
        {
            freq[x]=true;
        }

        int i=k;
        while(i<=100)
        {
            if(!freq[i])
                return i;

            i+=k;
        }
        return ((100 / k) + 1) * k;
    }
};