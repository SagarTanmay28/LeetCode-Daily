/*
T.C = O(n * m)
S.C = O(1)
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;

        for(int i = 0 ; i < strs[0].length() ; i++){
            for(int j = 0 ; j < n - 1 ; j++){
               if(strs[j][i] > strs[j+1][i]){
                ans++;
                break;
               }
            }
        }

        return ans;
    }
};
