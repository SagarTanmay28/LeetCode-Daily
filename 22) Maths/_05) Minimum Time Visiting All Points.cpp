/*
T.C = O(n);
S.C = O(1);
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i=0;i<n-1;i++){
            int start_x = points[i][0];
            int start_y = points[i][1];

            int end_x = points[i+1][0];
            int end_y = points[i+1][1];

            ans += max(abs(end_x - start_x), abs(end_y - start_y));

        }

        return ans;
    }
};
