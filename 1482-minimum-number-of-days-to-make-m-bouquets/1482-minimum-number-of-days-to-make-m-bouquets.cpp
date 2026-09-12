class Solution {
public:
    bool fun(vector<int>& bloomDay, int m, int k,int guess)
    {
        int flowers=0;
        int bouquet=0;

        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=guess)
            {
                flowers++;
                if(flowers==k)
                {
                    bouquet++;
                    flowers=0;
                    if(bouquet>=m)
                        return true;
                }
            }
            else
            {
                flowers=0;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k > n)
        {
            return -1;
        }

        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high= *max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;

        while(low<=high)
        {
            int guess=(low+high)/2;

            if(fun(bloomDay,m,k,guess))
            {
                res=guess;
                high=guess-1;
            }
            else
            {
                low=guess+1;
            }
        }
        return res;
    }
};