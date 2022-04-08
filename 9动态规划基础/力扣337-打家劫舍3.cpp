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
 
 //  //�ݹ飬��ʱ
 // class Solution {
 // public:
 //     int rob(TreeNode* root) {
 //         return findRob(root);
 //     }
 // private:
 //     //Ѱ����rootΪ���ڵ�����ܻ�õ����ֵ��
 //     int findRob(TreeNode* root){
 //         if(root == NULL) return 0;

 //         //ȡroot�Ͳ�ȡroot
 //         int res1 = root->val + (root->left != NULL ? (findRob(root->left->left) + findRob(root->left->right)) : 0) + (root->right != NULL ? (findRob(root->right->left) + findRob(root->right->right)) : 0);
 //         int res2 = findRob(root->left) + findRob(root->right);
 //         return max(res1, res2);

 //     }
 // };
 ////�ݹ飬���仯����
 // class Solution {
 // public:
 //     int rob(TreeNode* root) {
 //         return findRob(root);
 //     }
 // private:
 //     unordered_map<TreeNode*,int> memo;//ʹ��һ����ϣ��洢ÿ���ڵ��Ӧ��͵�Խ����������
 //     //Ѱ����rootΪ���ڵ�����ܻ�õ����ֵ��
 //     int findRob(TreeNode* root){
 //         if(root == NULL) return 0;
 //         if(memo[root] != 0)
 //             return memo[root];
 //         //ȡroot�Ͳ�ȡroot���������ȡ���ֵ
 //         int res1 = root->val + (root->left != NULL ? (findRob(root->left->left) + findRob(root->left->right)) : 0) + (root->right != NULL ? (findRob(root->right->left) + findRob(root->right->right)) : 0);
 //         int res2 = findRob(root->left) + findRob(root->right);

 //         memo[root] = max(res1, res2);
 //         return memo[root];

 //     }
 // };

 //���ڴ��е��Ż�
 /*
 �κ�һ���ڵ���͵�������Ǯ��״̬���Զ���Ϊ

 ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ������͵�������Ǯ + �Һ�����͵������Ǯ
 ע��������͵�������Ǯ: max(����ѡ��͵ʱ��Ǯ������ѡ��͵ʱ��Ǯ)
 ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ����ѡ���Լ���͵ʱ�ܵõ���Ǯ + �Һ���ѡ��͵ʱ�ܵõ���Ǯ + ��ǰ�ڵ��Ǯ��
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

    //Ѱ����rootΪ���ڵ�����ܻ�õ����ֵ��
    SubtreeStatus findRob(TreeNode* root) {
        if (root == NULL) return { 0,0 };

        auto leftV = findRob(root->left);
        auto rightV = findRob(root->right);
        //ȡroot�Ͳ�ȡroot���������ȡ���ֵ

        //ȡroot����left��right��ȡ
        int selected = root->val + leftV.notSelected + rightV.notSelected;

        //��ȡroot��left,right��ȡ�ɲ�ȡ,ѡ�������Ǹ�
        int notSelected = max(leftV.selected, leftV.notSelected) + max(rightV.selected, rightV.notSelected);

        return { selected, notSelected };

    }
};

int main() {

    system("pause");
    return 0;
}