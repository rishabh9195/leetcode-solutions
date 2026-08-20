class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        int a1=0;
        int a2=0;

        for(int i=2;i<nums.size();i++)
        {
            if(arr1[a1]>arr2[a2])
            {
                arr1.push_back(nums[i]);
                a1++;
            }
            else
            {
                arr2.push_back(nums[i]);
                a2++;
            }
        }
        vector <int> ans= arr1;
        ans.insert(ans.end(), arr2.begin(), arr2.end());
        return ans;
    }
};