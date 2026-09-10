class Solution {
public:

    long long fun(vector<int>&piles,int speed)
    {
        long long h=0;
        for(int i=0;i<piles.size();i++)
        {
            h=h+(piles[i]/speed);
            if(piles[i]%speed!=0)
            {
                h=h+1;
            }
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int res=-1;

        while(low<=high)
        {
            int guess = low + (high - low) / 2;
            long long  hour=fun(piles,guess);
            
            if(hour>h)
            {
                low=guess+1;
            }
            else
            {
                res=guess;
                high=guess-1;
            }
        }
        return res;

    }
};