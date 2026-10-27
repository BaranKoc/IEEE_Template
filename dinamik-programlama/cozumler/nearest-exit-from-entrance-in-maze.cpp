class Solution {
public:

    bool isValid(int x,int y,int n,int m, vector<vector<char>>& maze,vector<vector<int>>& visited){
        if(x>=0 && x<n && y>=0 && y< m && maze[x][y]!='+' && visited[x][y]!=1){
            return true;
        }
        return false;
    }

    bool isExit(int x,int y,int startX,int startY, vector<vector<char>>& maze,vector<vector<int>>& visited){
        if(x==startX && y==startY) return false;
        if( (x==0 || x==maze.size()-1 || y==0 || y==maze[0].size()-1)
           && maze[x][y]!='+')
        {
            return true;
        }
        return false;
    }

    int bfsHelper(vector<vector<char>>& maze,vector<vector<int>>& visited,int startX,int startY){
        queue<vector<int>>Queue;
        Queue.push({startX,startY,0});
        while(!Queue.empty()){
            int x = Queue.front()[0];
            int y = Queue.front()[1];
            int steps = Queue.front()[2];
            Queue.pop();

            if(isExit(x,y,startX,startY,maze,visited)) return steps;
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int newX = x+dx[i] , newY = y+dy[i];

                if(isValid(newX,newY,maze.size(),maze[0].size(),maze,visited)){
                    Queue.push({newX,newY,steps+1});
                    visited[newX][newY] = 1;
                }
            }
        }

        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>visited(n,vector<int>(m,-1));
        return bfsHelper(maze,visited,entrance[0],entrance[1]);
    }
};
