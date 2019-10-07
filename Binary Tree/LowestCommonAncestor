/*
Function Description

The function lca returns a pointer to the lowest common ancestor node of the two values given.

lca has the following parameters:
- root: a pointer to the root node of a binary search tree
- v1: a node.data value
- v2: a node.data value

Input Format

The first line contains an integer n, the number of nodes in the tree.
The second line contains n space-separated integers representing values.
The third line contains two space-separated integers, v1 and v2.

To use the test data, you will have to create the binary search tree yourself. 

*/
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


    Node *lca(Node *root, int v1,int v2) {
        int left = v1;
        int right = v2;
        if (v1 > v2){
            left = v2;
            right = v1;
        }
        if (right < root->data) {
            return lca(root->left, left, right);
        } else if (left > root->data){
            return lca(root->right, left, right);
        }
        return root;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
