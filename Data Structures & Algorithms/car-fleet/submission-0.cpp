class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int carCount = position.size();

        vector<pair<int, int>> cars;

        for(int i =0;i<carCount; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());


        vector<double> fleetTimes;

        for(int i =0;i<carCount; i++)
        {
            int distanceLeft = target - cars[i].first;

            double arrivalTime = (double)distanceLeft/cars[i].second;

            if(fleetTimes.empty() || arrivalTime > fleetTimes.back())
            {
                fleetTimes.push_back(arrivalTime);
            }
        }

        return fleetTimes.size();
        
    }
};
