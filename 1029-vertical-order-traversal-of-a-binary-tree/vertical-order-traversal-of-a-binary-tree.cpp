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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL) return v;
        
        map<int,map<int,multiset<int>>>mp;//vertical,level,nodes values(same level and vertical)
        queue<pair<TreeNode*,pair<int,int>>>q;//node,vertical,level

        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();

            TreeNode* node=temp.first;
            int x=temp.second.first;//vertical
            int y=temp.second.second;//level
            
            mp[x][y].insert(node->val);

            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        for(auto it1: mp){
            vector<int>col;
            for(auto it2: it1.second){
                for(auto x: it2.second){
                    col.push_back(x);
                }
            }
            v.push_back(col);
        }
        return v;
    }
};