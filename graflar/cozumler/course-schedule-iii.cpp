class Solution {
public:
    bool static cmp(vector<int> &a,vector<int>&b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
         sort(courses.begin(),courses.end(),cmp);
         int sm = 0;
         priority_queue<int> pq;
         for(int i=0; i<courses.size(); i++) {
               pq.push(courses[i][0]);
               sm+=courses[i][0];

               if(sm>courses[i][1]) {
                    sm-=pq.top();
                    pq.pop();
               }
         }
        return pq.size();
    }
};
