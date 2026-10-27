class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        unordered_map<int, long long> lastOccurrence;

        long long currentDay = 0;

        for(int task : tasks) {

            if(lastOccurrence.find(task) != lastOccurrence.end()) {

                if(currentDay - lastOccurrence[task] <= space) {

                    currentDay = lastOccurrence[task] + space + 1;
                } else {

                    currentDay++;
                }
            } else {

                currentDay++;
            }

            lastOccurrence[task] = currentDay;
        }

        return currentDay;
    }
};
