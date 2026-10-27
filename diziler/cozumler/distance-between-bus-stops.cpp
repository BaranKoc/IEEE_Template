class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        if (start == destination)
            return 0;

        int one_way = 0;
        int i = start;
        while (i != destination)
        {
            one_way += distance[i];
            i = (i+1)%n;
        }

        int second_way = 0;
        i = destination;
        while (i != start)
        {
            second_way += distance[i];
            i = (i+1)%n;
        }

        return one_way<second_way? one_way : second_way;
    }
};
