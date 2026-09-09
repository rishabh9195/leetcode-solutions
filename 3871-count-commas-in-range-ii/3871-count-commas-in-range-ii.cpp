class Solution {
public:
    long long countCommas(long long n) {
        long long curr=1000;
        long long res=0;
        int commas=1;

        while(curr<=n)
        {
            long long end= curr*1000-1;
            res+=(min(n,end)-curr+1)*commas;

            curr*=1000;
            commas++;
        }
        return res;
    }
};