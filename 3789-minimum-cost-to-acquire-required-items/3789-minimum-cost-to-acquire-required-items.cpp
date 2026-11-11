class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long int ans=0;

        long long c1= 1LL*cost1*need1 + 1LL*cost2*need2;

        int common =min(need1,need2);

        long long c2=   1LL*costBoth*common 
                      + 1LL*(need1-common)*cost1 
                      + 1LL*(need2-common)*cost2;

        long long c3= 1LL*costBoth * max(need1,need2);

        ans= min({c1,c2,c3});
        return ans; 

    }
};