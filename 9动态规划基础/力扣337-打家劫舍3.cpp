#include<iostream>
#include<vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
 //  //递归，超时
 // class Solution {
 // public:
 //     int rob(TreeNode* root) {
 //         return findRob(root);
 //     }
 // private:
 //     //寻找以root为根节点的数能获得的最大值。
 //     int findRob(TreeNode* root){
 //         if(root == NULL) return 0;

 //         //取root和不取root
 //         int res1 = root->val + (root->left != NULL ? (findRob(root->left->left) + findRob(root->left->right)) : 0) + (root->right != NULL ? (findRob(root->right->left) + findRob(root->right->right)) : 0);
 //         int res2 = findRob(root->left) + findRob(root->right);
 //         return max(res1, res2);

 //     }
 // };
 ////递归，记忆化搜索
 // class Solution {
 // public:
 //     int rob(TreeNode* root) {
 //         return findRob(root);
 //     }
 // private:
 //     unordered_map<TreeNode*,int> memo;//使用一个哈希表存储每个节点对应的偷窃金额最大的数量
 //     //寻找以root为根节点的数能获得的最大值。
 //     int findRob(TreeNode* root){
 //         if(root == NULL) return 0;
 //         if(memo[root] != 0)
 //             return memo[root];
 //         //取root和不取root两种情况，取最大值
 //         int res1 = root->val + (root->left != NULL ? (findRob(root->left->left) + findRob(root->left->right)) : 0) + (root->right != NULL ? (findRob(root->right->left) + findRob(root->right->right)) : 0);
 //         int res2 = findRob(root->left) + findRob(root->right);

 //         memo[root] = max(res1, res2);
 //         return memo[root];

 //     }
 // };

 //基于大佬的优化
 /*
 任何一个节点能偷到的最大钱的状态可以定义为

 当前节点选择不偷：当前节点能偷到的最大钱数 = 左孩子能偷到的最大钱 + 右孩子能偷到最大的钱
 注：左孩子能偷到的最大钱: max(左孩子选择不偷时的钱，左孩子选择偷时的钱)
 当前节点选择偷：当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
 */
struct SubtreeStatus {
    int selected;
    int notSelected;
};
class Solution {
public:
    int rob(TreeNode* root) {
        SubtreeStatus res = findRob(root);
        return max(res.selected, res.notSelected);
    }
private:

    //寻找以root为根节点的数能获得的最大值。
    SubtreeStatus findRob(TreeNode* root) {
        if (root == NULL) return { 0,0 };

        auto leftV = findRob(root->left);
        auto rightV = findRob(root->right);
        //取root和不取root两种情况，取最大值

        //取root，则left，right不取
        int selected = root->val + leftV.notSelected + rightV.notSelected;

        //不取root，left,right可取可不取,选择最大的那个
        int notSelected = max(leftV.selected, leftV.notSelected) + max(rightV.selected, rightV.notSelected);

        return { selected, notSelected };

    }
};

int main() {

    system("pause");
    return 0;
}