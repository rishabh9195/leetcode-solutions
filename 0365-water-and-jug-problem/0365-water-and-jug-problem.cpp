class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target<0 || target>x+y)
        {
            return false;
        }
        if(target==0)
        {
            return true;
        }
        int g= gcd(x,y);
        return g!=0 && target%g==0;
    }
};