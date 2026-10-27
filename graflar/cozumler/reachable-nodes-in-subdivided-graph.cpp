class Solution {
  public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
  const int INF = 1e8;
  vector<vector<pair<int,int>> g(n);
  for(auto i: edges){
  g[i[0]].push_back({i[1],i[2]});
  g[i[1]].push_back({i[0],i[2]});
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  pq.push({0, 0});
  vector<int> d(n, INF);
  d[0] = 0;

  while(!pq.empty()){
       int dist = pq.top().first;
       int node = pq.top().second;
       pq.pop();

       for(auto it:g[node]){
           if(d[it.first]>dist+it.second+1)
           {
               d[it.first]=dist+it.second+1;
               pq.push({d[it.first], it.first});
           }
       }
  }

  int ans = 0;
  for(int i = 0; i < n; ++i) {
      if(d[i] <= maxMoves)
        ans++;
   }

  for(auto i : edges) {
      int src=i[0],dest=i[1], between=i[2];
      int x = max(0, (maxMoves - d[src]));
      int y = max(0, (maxMoves - d[dest]));
      ans += min(between, x + y);
  }
  return ans;
