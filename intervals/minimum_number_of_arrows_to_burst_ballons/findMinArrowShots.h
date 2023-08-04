 /* There are some spherical balloons taped onto a flat
  * wall that represents the XY-plane. The balloons are
  * represented as a 2D integer array points where
  * points[i] = [x_start, x_end] denotes a balloon whose
  * horizontal diameter streches between x_start and
  * x_end. You do not know the exact y-coordinates of
  * the balloons.
  *
  * Arrows can be shot up directly vertically (in the
  * positive y-direction) from different points along
  * the x-axis. A balloon with x_start and x_end is 
  * burst by an arrow shotat x if x_start <= x <= x_end.
  * There is no limit to the number of arrows that can
  * be shot. A shot arrow keeps traveling up infinitely,
  * bursting any balloons in its path.
  *
  * Given the array points, return the minium number
  * of arrows that must be shot to burst all balloons. */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> arrows;
        
        // this is necessary, but i do not know why
        /* actually i do know why. we need to properly account
         * for certain cases of nested balloons */
        sort(points.begin(), points.end());

        for (vector<int> point : points) {
            if (arrows.empty()) {
                arrows.push_back(point);
            }
            else {
                vector<vector<int>>::iterator interval = arrows.begin();
                bool inserted = false;
                while (interval != arrows.end() && !inserted) {
                    // if inside interval, update
                    if ((point[0] >= (*interval)[0] && point[0] <= (*interval)[1]) ||
                        (point[1] <= (*interval)[1] && point[1] >= (*interval)[0])) {
                        (*interval)[0] = max((*interval)[0], point[0]);
                        (*interval)[1] = min((*interval)[1], point[1]);
                        inserted = true;
                    }
                    interval++;
                }
                if (!inserted) {
                    arrows.push_back(point);
                }
            }
        }

        return (int)arrows.size();
    }
};
