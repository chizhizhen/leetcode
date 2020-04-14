class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int m = (l + r) / 2;
        vector<int> nums_l = nums(nums.begin(), nums.begin()+m);
        vector<int> nums_r = nums(nums.begin()+m+1, nums.end());
        TreeNode* root = new TreeNoed(nums[m]);
        if (nums_l) root->left = sortedArrayToBST(nums_l);
        if (nums_r) root->right = sortedArrayToBST(nums_r);
        return root;
    }
};
