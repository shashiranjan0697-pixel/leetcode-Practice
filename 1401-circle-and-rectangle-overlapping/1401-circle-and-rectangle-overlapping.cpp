class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        for(int i = y1; i <= y2; i++) {

            int x = x1 - xCenter;
            int y = i - yCenter;

            if(x*x + y*y <= radius*radius)
                return true;

            x = x2 - xCenter;

            if(x*x + y*y <= radius*radius)
                return true;
        }

        for(int i = x1; i <= x2; i++) {

            int y = y1 - yCenter;
            int x = i - xCenter;

            if(x*x + y*y <= radius*radius)
                return true;

            y = y2 - yCenter;

            if(x*x + y*y <= radius*radius)
                return true;
        }

        if (xCenter >= x1 && xCenter <= x2 &&
            yCenter >= y1 && yCenter <= y2)
            return true;

        return false;
    }
};