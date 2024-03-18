class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int i=0, balloons=0, n=points.size();
        sort(points.begin(), points.end());
        while(i<n){
            balloons++;
            int start=points[i][0];
            int end=points[i][1];
            i++;
            while(i<n && (points[i][0]>=start && points[i][0]<=end)){//we'll burst all those ballons coming under the current range
                //end will also be the smallest of the two points, so that we get the next points in the range 
                end = min(end, points[i][1]);
                i++;
            }
        }
        return balloons;
    }
};