class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if(rows == 0) return "";

        int n = s.size();
        int cols = n / rows;

        vector<vector<char>> nums(rows, vector<char>(cols, ' '));

        int idx = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                nums[i][j] = s[idx++];
            }
        }

        string ans = "";

        // 🔥 diagonal traversal
        for(int start_col = 0; start_col < cols; start_col++){
            int i = 0, j = start_col;

            while(i < rows && j < cols){
                ans += nums[i][j];  // ✅ DO NOT SKIP SPACES
                i++;
                j++;
            }
        }

        // 🔥 remove trailing spaces ONLY
        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
