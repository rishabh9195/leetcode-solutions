class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        vector<pair<int,int>> cars;

        for(int i=0;i<n;i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        int fleet=0;
        double lasttime=0;

        for(int i= n-1;i>=0;i--)
        {
            double currtime= (double)(target-cars[i].first)/(cars[i].second);
        
            if(currtime>lasttime)
            {
                fleet++;
                lasttime=currtime;
            }
        }
        return fleet;
    }
};