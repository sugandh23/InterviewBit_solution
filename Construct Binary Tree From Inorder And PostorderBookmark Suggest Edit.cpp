Question link: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-postorder/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {      
      if(postorder.size()==0)
            return NULL;
        stack<int> s;
        stack<TreeNode*> st;
        int i,j,k=0;
        j=inorder.size()-1;
        i=postorder.size()-1;
        TreeNode *temp,*root;
        s.push(postorder[i]);
        root= new TreeNode(postorder[i]);
        st.push(root);
        temp=root;
        i--;
        while(i>=0){
            if(!s.empty() && st.top()->val==inorder[j]){
                temp=st.top();
                st.pop();
                s.pop();
                k=1;
                j--;
            }
            else{
                if(k==0){
                    s.push(postorder[i]);
                    temp->right=new TreeNode(postorder[i]);
                    temp=temp->right;
                    st.push(temp);
                    i--;
                }
                else{
                    k=0;
                    s.push(postorder[i]);
                    temp->left=new TreeNode(postorder[i]);
                    temp=temp->left;
                    st.push(temp);
                    i--;
                }
            }
        }
        return root;
}
