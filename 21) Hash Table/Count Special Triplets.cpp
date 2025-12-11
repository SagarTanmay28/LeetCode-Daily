// BRUTE FORCE :: O(n^2) 

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long n = nums.size();

        long long ans = 0;
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        for(long long k=1;k<n-1;k++){
            long long x = 2 * nums[k];

            long long left = 0;
            long long right = 0;
            
            if(mp.find(x) != mp.end()){
                vector<int> idx = mp[x];
                for(int i=0;i<idx.size();i++){
                    if(idx[i] < k) left++;
                    else if(idx[i] > k) right++;
                }
            }

            if(left != 0 && right != 0) ans += (left * right) % 1000000007;
        }

        return ans % 1000000007;
    }
};



Optimal 1 :: O(nlogn) 

/* 
T.C = O(nlogn)
S.C = O(n)
*/
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long n = nums.size();

        long long ans = 0;
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++) mp[nums[i]].push_back(i); // O(n)
        for(auto &p : mp) sort(p.second.begin(),p.second.end()); // O(n * logn)
        

        for(long long k=1;k<n-1;k++){
            long long x = 2LL * nums[k];

            if(mp.find(x) == mp.end()) continue;
            
            vector<int>& idx = mp[x]; // By Reference

            long long left = lower_bound(idx.begin(),idx.end(),k) - idx.begin();  // lower bound -> (logn)
            long long right = idx.size() - (upper_bound(idx.begin(), idx.end(), k) - idx.begin()); // upper bound -> (logn)
            

            if(left != 0 && right != 0) ans = (ans + (left * right) % 1000000007) % 1000000007;
        }

        return ans % 1000000007;
    }
};

//Approach-1 (Using map : 2 Pass Solution)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;

        for(int &num : nums) {
            mp_right[num]++;
        }

        for(int &num : nums) {
            mp_right[num]--;

            int left  = mp_left[num*2];
            int right = mp_right[num*2];

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;
        }

        return result;
    }
};



//Approach-2 (Using map :  Pass Solution)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> valid_i;
        unordered_map<int, int> valid_j;

        int result = 0;

        for(int &num : nums) {
            
            if(num%2 == 0) { //if it's valid k, we got our triplet
                result = (result + valid_j[num/2]) % M;
            }

            //If it's valid j or not
            valid_j[num] = (valid_j[num] + valid_i[num*2]) % M;

            valid_i[num]++;
        }

        return result;
    }
};
