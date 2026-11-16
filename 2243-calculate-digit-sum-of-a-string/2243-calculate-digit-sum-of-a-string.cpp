class Solution {
public:

    int getsum(string grp)
    {
        int sum=0;
        for(int i=0;i<grp.size();i++)
        {
            sum+=grp[i]-'0';
        }
        return sum;
    }

    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            string ans="";
            for(int i=0;i<s.size();i+=k)
            {
                string grp= s.substr(i,k);
                int sum=getsum(grp);
                ans+=to_string(sum);
            }
            s=ans;
        }
        return s;
    }
};