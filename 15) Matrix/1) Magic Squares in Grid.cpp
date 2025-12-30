/*
T.C = O(m * n);
S.C = O(1);
*/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        if(n < 3 || m < 3) return 0;

        for(int r = 1;r < n-1;r++){
           for(int c = 1;c < m-1;c++){
            
              vector<int> seen(10,false);
              bool flag = true;

              for(int i = r - 1; i <= r + 1; i++){
                    for(int j = c - 1; j <= c + 1; j++){
                        int val = grid[i][j];
                        if(val < 1 || val > 9 || seen[val]){
                            flag = false;
                            break;
                        }
                        seen[val] = true;
                    }
                    if(!flag) break;
              }

              if(flag == false) continue;

              int sum_v = grid[r][c] + grid[r-1][c] + grid[r+1][c];
              int sum_h = grid[r][c] + grid[r][c-1] + grid[r][c+1];
              int sum_ld = grid[r][c] + grid[r-1][c-1] + grid[r+1][c+1];
              int sum_rd = grid[r][c] + grid[r-1][c+1] + grid[r+1][c-1];

              int sum_r1 = grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1];
              int sum_r3 = grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1];
              int sum_c1 = grid[r-1][c-1] + grid[r][c-1] + grid[r+1][c-1];
              int sum_c3 = grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c+1];
              

              if((sum_v == sum_h) && (sum_h == sum_ld) && (sum_ld == sum_rd) && (sum_rd == sum_r1) && (sum_r1 == sum_r3) && (sum_r3 == sum_c1) && (sum_c1 == sum_c3)) ans++;
           }
        }

        return ans;
    }
};
