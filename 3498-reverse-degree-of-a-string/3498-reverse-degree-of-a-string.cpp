class Solution {
public:
    int reverseDegree(string s) {
        int totalsum=0;

        for(int i=0;i<s.size();i++)
        {
            int reversedpos= 26-(s[i]-'a');
            int indexpos=i+1;
            totalsum+= reversedpos*indexpos;
        }

        return totalsum;
    }
};