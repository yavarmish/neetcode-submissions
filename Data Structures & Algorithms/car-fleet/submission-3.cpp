class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<pair<int, double>> positionTimeMapping;
            int n = position.size();
            for(int i = 0; i < n; ++i) {                
                positionTimeMapping.push_back({position[i], 1.0 * (target - position[i]) / speed[i]});
            }
            sort(positionTimeMapping.begin(), positionTimeMapping.end());
            // for(auto &i : positionTimeMapping) cout<<i.first<<" "<<i.second<<"\n";
            // cout<<"\n";
            int carFleetCount = 1;
            double limitingTime = positionTimeMapping[n-1].second;
            for(int i = n - 2; i >= 0; --i) {
                // cout<<limitingTime<<" "<<positionTimeMapping[i].second<<"\n";
                while(i >= 0 and limitingTime >= positionTimeMapping[i].second) {
                    --i;
                }    
                
                if(i >= 0) {
                    ++carFleetCount;
                    limitingTime = positionTimeMapping[i].second;
                }
            }
            return carFleetCount;
    }
};
