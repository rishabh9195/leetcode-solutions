class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n= row.size();
        int swaps=0;

        vector<int>pos(n);
        for(int i=0;i<n;i++)
        {
            pos[row[i]]=i;
        }

        for(int i=0;i<n;i+=2)
        {
            int number=row[i];
            int partner= number^1;

            if(row[i+1]!=partner)
            {
                int partnerpos= pos[partner];
                int other=row[i+1];
                swap(row[i+1],row[partnerpos]);
                pos[partner]=i+1;
                pos[other]=partnerpos;
                swaps++;
            }
        }
        return swaps;
    }
};