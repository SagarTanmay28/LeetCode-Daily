| Complexity Type      | Value        |
| -------------------- | ------------ |
| **Time Complexity**  | **O(n × m)** |
| **Space Complexity** | **O(n)**     |


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;

        vector<bool> sorted(n - 1, false); // NEW: track resolved pairs

        for (int i = 0; i < m; i++) {
            bool flag = true;

            for (int j = 0; j < n - 1; j++) {
                if (!sorted[j] && strs[j][i] > strs[j + 1][i]) {
                    flag = false;
                    ans++;      // delete this column
                    break;
                }
            }

            if (!flag) continue;

            // mark pairs that become sorted because of this column
            for (int j = 0; j < n - 1; j++) {
                if (!sorted[j] && strs[j][i] < strs[j + 1][i]) {
                    sorted[j] = true;
                }
            }
        }
        return ans;
    }
};
