class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num || sum==0 || sum<1)
        {
            return "";
        }
        string str="";
        
        for(int i=0;i<num;i++)
        {   
            if(sum==0)
            {
                str +=to_string(0);
            }
            else
            {
                int digit = min(9, sum);
                str += to_string(digit);
                sum -= digit;  
            }
                    
        }
        return str;

    }
};