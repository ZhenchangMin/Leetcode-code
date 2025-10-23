class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &res)// another function to maintain a vector to store the result
    {
        if (root == nullptr)
        {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https : // leetcode.cn/problems/binary-tree-preorder-traversal/solutions/461821/er-cha-shu-de-qian-xu-bian-li-by-leetcode-solution/
// 来源：力扣（LeetCode） 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。