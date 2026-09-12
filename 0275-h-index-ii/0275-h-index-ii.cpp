class Solution {
public:

    bool fun(vector<int>& citations,int n,int guess)
    {   
        int h=n-guess;
        if(citations[guess]>=h)
            return true;
        else 
            return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0;
        int high=n-1;
        int res=0;

        while(low<=high)
        {
            int guess=(low+high)/2;

            if(fun(citations,n,guess))
            {
                res=n-guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return res;
    }
};