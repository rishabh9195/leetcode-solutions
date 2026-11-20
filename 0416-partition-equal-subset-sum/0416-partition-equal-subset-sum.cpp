class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2==1)
        {
            return false;
        }
        else{
            sum=sum/2;
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
       for(int i=0;i<=sum;i++)
       {
           dp[n][i]=false;
       }
       dp[n][0]=true;
       
       for(int i=n-1;i>=0;i--)
       {
           for(int j=0;j<=sum;j++)
           {
               if(arr[i]>j)
               {
                   dp[i][j]=dp[i+1][j];
               }
               else
               {
               dp[i][j]= dp[i+1][j] || dp[i+1][j-arr[i]];
               }
           }
       }
       return dp[0][sum];
    }
};