/*
T.C = O(N);
S.C = O(H); worst case :: O(N) skewed tree
*/
class Solution {
public:
    long long total_sum = 0;
    long long maxi = LLONG_MIN;
    long long mod = 1e9 + 7;

    void calculate_sum(TreeNode* root){
        if(root == NULL) return;
        total_sum += root->val;
        calculate_sum(root->left);
        calculate_sum(root->right);
    }

    long long dfs(TreeNode* root){
        
        if(root == NULL) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subtree_sum = left + right + root->val;

        long long product = subtree_sum * (total_sum - subtree_sum);
        maxi = max(maxi,product);

        return subtree_sum;

    }

    int maxProduct(TreeNode* root) {
        calculate_sum(root);
        dfs(root);
        return (maxi % mod);
    }
};
