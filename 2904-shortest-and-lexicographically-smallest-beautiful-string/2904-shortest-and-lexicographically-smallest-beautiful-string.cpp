class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector <int> pos;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                pos.push_back(i);
            }
        }
        if(pos.size()<k)
        {
            return "";
        }
        string ans="";

        for(int i=0;i+k-1<pos.size();i++)
        {
            int start=pos[i];
            int end=pos[i+k-1];

            string temp=s.substr(start,end-start+1);

            if(ans==""||
            temp.length()<ans.length()||
            (temp.length()==ans.length() && temp<ans))
            {
                ans=temp;
            }
        }
        return ans;
    }
};