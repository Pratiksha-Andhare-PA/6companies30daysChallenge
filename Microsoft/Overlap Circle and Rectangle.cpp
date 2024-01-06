class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                // dist of a pt from center of a circle
                double dist = (i-xCenter)*(i-xCenter) + (j-yCenter)*(j-yCenter);
                double r = radius*radius;

                if(dist <= r){   // pt lies within or on the circumference of a circle
                    return true;
                }
            }
        }
        return false;
    }
};
