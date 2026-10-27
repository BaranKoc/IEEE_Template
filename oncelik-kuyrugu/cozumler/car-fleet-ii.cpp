class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars)
    {
        int n = cars.size();
        vector<double> res(n,-1.0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {

            while(!st.empty() && cars[st.top()][1]>= cars[i][1])
                st.pop();
            while(!st.empty())
            {
                double collision_time = (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(collision_time <=res[st.top()] || res[st.top()] == -1)
                {
                    res[i] = collision_time;
                    break;
                }
                st.pop();
            }

            st.push(i);
        }
        return res;
    }
};
