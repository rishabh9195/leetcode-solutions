class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0];
        int nodelete=arr[0];
        int onedelete=INT_MIN;

        for(int i=1;i<arr.size();i++)
        {   
            int prevnodelete=nodelete;
            int prevonedelete=onedelete;
            nodelete=max(arr[i],prevnodelete+arr[i]);

            int v2;
            if(prevonedelete==INT_MIN)
                v2=arr[i];
            else
                v2=onedelete+arr[i];

            onedelete=max(v2,prevnodelete);

            ans=max(ans,max(onedelete,nodelete));

        }
        return ans;
    }
};