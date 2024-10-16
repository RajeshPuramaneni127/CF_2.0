#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left,* right;
    TreeNode(){
        left = NULL; right = NULL;
    }
    TreeNode(int val){
        this->val = val;
        left = NULL; right = NULL;
    }
};

priority_queue<int,vector<int>,greater<int>> pq;

// DFS to push elements into the priority queue
void dfs1(TreeNode* root){
    if(!root) return;
    pq.push(root->val);
    dfs1(root->left);
    dfs1(root->right);
}

// Assign sorted values from the priority queue back to the tree
void fun(TreeNode* root){
    dfs1(root);
    function<void (TreeNode*)> dfs = [&](TreeNode* root){
        if(!root) return;
        dfs(root->left);
        root->val = pq.top();
        pq.pop();
        dfs(root->right);
    };
    dfs(root);
}

// Function to print the tree in an inorder fashion
void printTree(TreeNode* root){
    if(!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// Function to construct the tree from a vector
TreeNode* constructTree(vector<int>& a, int& i){
    if(i >= a.size()) return NULL;
    TreeNode* root = new TreeNode(a[i++]);
    root->left = constructTree(a, i);
    root->right = constructTree(a, i);
    return root;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int index = 0;
    TreeNode* root = constructTree(a, index);

    fun(root);  // Sort the tree using priority queue
    
    printTree(root);  // Print the tree
    
    return 0;
}
