class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();

        long long total_sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total_sum += grid[i][j];
            }
        }

        long long row_sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row_sum += grid[i][j];
            }
            long long rem = total_sum - row_sum;
            if(rem == row_sum) return true;
            if(row_sum > rem) break;
        }

        long long col_sum = 0;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                col_sum += grid[i][j];
            }
            long long rem = total_sum - col_sum;
            if(rem == col_sum) return true;
            if(col_sum > rem) break;
        }

        return false;
    }
};
