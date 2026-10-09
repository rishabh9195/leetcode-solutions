class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int open =0;
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(i+1<n && s[i+1]==')')
            {
                if(open>0)
                {
                    open--;
                }
                else{
                    count++;
                }
                i++;
            }
            else
            {
                count++;
                if(open>0)
                {
                    open--;
                }
                else
                {
                    count++;
                }
            }
        }

        count+=2*open;
        return count;

    }
};