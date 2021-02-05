/**
 *  Topic: [Week 4] [LeetCode] [Tree] 1261. Find Elements in a Contaminated Binary Tree
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 4, LeetCode, Tree, Medium, C++, Binary Tree, Breadth-first Search
 **/

class FindElements {
    
    /** storing whether a value is in the tree **/
    map<int, bool> contain_value;
    
public:
    FindElements(TreeNode* root)
    {
        /** Queue for BFS **/
        queue<TreeNode*> unvisited;
        
        int val = 0;
        root->val = 0;
        unvisited.push(root);
        
        /** BFS **/
        while (!unvisited.empty())
        {
            TreeNode *parent = unvisited.front();
            
            /** Checking whether left node exists **/
            if (parent->left)
            {
                val = 2*parent->val + 1;
                contain_value[val] = true;
                
                parent->left->val = val;
                unvisited.push(parent->left);
            }
            
            /** Checking whether right node exists **/
            if (parent->right)
            {
                val = 2*parent->val + 2;
                contain_value[val] = true;
                
                parent->right->val = val;
                unvisited.push(parent->right);
            }
            unvisited.pop();
        }
    }
    
    bool find(int target)
    {
        bool found = contain_value.find(target) != contain_value.end();
        return found;
    }
};

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
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
