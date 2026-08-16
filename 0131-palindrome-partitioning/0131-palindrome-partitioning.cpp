class Solution {
public:

    bool isPalindrome(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
    
    void fun(string s , int start , vector<string>temp,vector<vector<string>>&ans)
    {
        if(s.size()==start)
        {
            ans.push_back(temp);
            return;
        }

        for(int end=start; end<s.size() ; end++)
            {
                if(isPalindrome(s,start,end))
                {
                    temp.push_back(s.substr(start, end - start + 1));
                    fun(s,end+1,temp,ans);
                    temp.pop_back();
                 }
            }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        
        fun(s,0, temp,ans);
        return ans;
    }
};