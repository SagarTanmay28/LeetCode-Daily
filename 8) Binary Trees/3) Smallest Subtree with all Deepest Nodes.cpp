/*
T.C = O(n);
S.C = O(maxD);
*/
class Solution {
public:
    unordered_map<int,int> mp;
    int maxD = 0;

    void depth_fill(TreeNode* root, int d){
        if(root == NULL) return;
        
        maxD = max(maxD,d);
        mp[root->val] = d;

        depth_fill(root->left,d+1);
        depth_fill(root->right,d+1);
    }

    TreeNode* dfs(TreeNode* root){
        if(root == NULL || mp[root->val] == maxD) return root;

        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);

        if(left != NULL && right != NULL) return root;

        return left != NULL ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;
        depth_fill(root,0);
        return dfs(root);
    }
};

/**************************************************************One-Pass-Solution************************************************************************************/

/*
T.C = O(n);
S.C = O(h);
*/
class Solution {
public:
    pair<int,TreeNode*> solve(TreeNode* root){
        if(root == NULL){
            return {0,NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if(l.first == r.first) return {l.first+1,root};
        else if(l.first > r.first) return {l.first+1,l.second};
        else return {r.first+1,r.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};
