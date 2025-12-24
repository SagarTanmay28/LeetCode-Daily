/*
T.C = O(n + mlogm);
S.C = O(1)
*/
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        int total_apples = accumulate(apple.begin(),apple.end(),0);

        int count = 0;
        sort(capacity.begin(),capacity.end());

        for(int j=m-1;j>=0;j--){
            total_apples -= capacity[j];
            count++;
            if(total_apples <= 0) return count;
        }

        return count;
    }
};
