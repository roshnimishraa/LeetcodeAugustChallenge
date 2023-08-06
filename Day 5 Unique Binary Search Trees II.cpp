Problem Link : https://leetcode.com/problems/unique-binary-search-trees-ii/

Approach : Recursion 
Logic :
1. For BST every tree must be BST 
2. no of element in BST from 1 to n

Task 
1. Build Tree
2. Return Root

eg. n = 3
There can be Three Possibility of root it can be 1,2,3
if root = 1 then [[1,null,3,2],[1,null,2,3]]
if root = 2 then [[2,1,3]]
if root = 3 then [3,1,null,null,2],[[3,2,null,1]]

ans =  [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Time Complexity: O(2^n)
Auxiliary Space: O(2^n)

class Solution {
public:
    vector<TreeNode*> constructTrees(int start, int end){
        vector<TreeNode*> result;
		
        if(start==end){
            TreeNode *root = new TreeNode(start);
            result.push_back(root);
            return result;
        }
        if(start>end){
            result.push_back(NULL);
            return result;
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees = constructTrees(start, i-1); /*Total no. of LSTs possible when  is the root*/
            vector<TreeNode*> rightTrees = constructTrees(i+1, end); 
			/*Join each left and right subtree to the root to form different BSTs*/
            for(auto l: leftTrees){
                for(auto r: rightTrees){
                    TreeNode *root = new TreeNode(i); 
                    root->left = l;
                    root->right = r;
                    result.push_back(root);  /*Add the root of the resulting BST each time to the vector result*/
                }
            }
        }
        return result;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return constructTrees(1, n);
    }
};
