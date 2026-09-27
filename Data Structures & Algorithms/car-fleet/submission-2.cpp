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


        double slowestFleetTime = 0.0;
        int fleetCount = 0;

        for(int i =0;i<carCount; i++)
        {
            int distanceLeft = target - cars[i].first;

            double arrivalTime = (double)distanceLeft/cars[i].second;

            if(arrivalTime > slowestFleetTime)
            {

                slowestFleetTime = arrivalTime;
                fleetCount++;
            }
        }

        return fleetCount;
        
    }
};
