/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root != nullptr)
            ans.push_back(root->val);
        else return vector<int> (0);
        vector<int> temp; 
        if (root->left != nullptr){
            temp = preorderTraversal(root->left);
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back(temp[i]);
            }
        }
        if (root->right != nullptr){
            temp = preorderTraversal(root->right);
            for (int i = 0; i < temp.size(); i++){
                ans.push_back(temp[i]);
            }
        }
            
        return ans;
    }
};