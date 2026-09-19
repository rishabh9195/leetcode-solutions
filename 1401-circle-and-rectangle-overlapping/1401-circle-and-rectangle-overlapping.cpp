class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int nearestx= max(x1,min(xCenter,x2));
        int nearesty= max(y1,min(yCenter,y2));

        int dx= xCenter-nearestx;
        int dy= yCenter-nearesty;

        int dist= dx*dx + dy*dy;

        return dist<= radius*radius;

    }
};