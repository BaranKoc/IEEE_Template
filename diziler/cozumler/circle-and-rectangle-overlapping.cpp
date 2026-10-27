class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int nearest_x = (xCenter < x1) ? x1 : (xCenter > x2) ? x2 : xCenter;

        int nearest_y = (yCenter < y1) ? y1 : (yCenter > y2) ? y2 : yCenter;
        int dist_x = xCenter - nearest_x, dist_y = yCenter - nearest_y;
        return dist_x * dist_x + dist_y * dist_y <= radius * radius;
    }
};
