/*
TC = (hloh + vlogv);
SC = O(1);
*/
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxi1 = 1, cnt = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxi1 = max(maxi1, cnt);
        }

        int maxi2 = 1;
        cnt = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxi2 = max(maxi2, cnt);
        }

        int side = min(maxi1 + 1, maxi2 + 1);
        return side * side;
    }
};
