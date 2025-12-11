/* 
T.C = O(n);
S.C = O(n);
*/
class Solution {
public:
    int countCoveredBuildings(int m, vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int,int> x_min,x_max;
        unordered_map<int,int> y_min,y_max;

        for(auto &p : nums){ // O(n)
            int x = p[0];
            int y = p[1];

            if(!x_min.count(x) || x_min[x] > y) x_min[x] = y;
            if(!x_max.count(x) || x_max[x] < y) x_max[x] = y;
            if(!y_min.count(y) || y_min[y] > x) y_min[y] = x;
            if(!y_max.count(y) || y_max[y] < x) y_max[y] = x;
        }

        for(auto &p : nums){ // O(n)
            int x = p[0];
            int y = p[1];

            if((x_min[x] < y && y < x_max[x]) && (y_min[y] < x && x < y_max[y])) ans++;
        }

        return ans;
    }
};
