class Solution {
public:
    bool checkDivisibility(int n) {
        int nums=n;
        int sum=0;
        int prod=1;

        while(nums>0)
        {
            int digit= nums%10;
            sum+=digit;
            prod*=digit;
            nums/=10;
        }
        int value= sum+prod;

        return n%value==0;
    }
};