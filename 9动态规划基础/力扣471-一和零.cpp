#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

// //�������ÿ��strs��Ӧ��0��1����
// //nums[i][0]��ʾ��strs[i]����0�ĸ���
// //nums[i][1]��ʾ��strs[i]����1�ĸ���

// //memo[i][j]��ʾi��0��j��1�ܱ�ʾ������Ӽ�����
// //memo[i][j] = �� nums[i][] nums[n][] ��
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));
//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++){
//                 if(strs[i][j] == '0')
//                     nums[i][0]++;
//                 else if(strs[i][j] == '1')
//                     nums[i][1]++;
//             }

//         vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); //memo[i][j]��ʾi��0��j��1�ܱ�ʾ������Ӽ�����

//         for(int i = 1; i <= m; i ++){
//             for(int j = 1; j <= n; j ++){
//                 // cout<<" memo["<<i<<"]["<<j<<"] = "<<memo[i][j];
//                 for(int k = 0; k < nums.size(); k ++){
//                     if(i >= nums[k][0] && j >= nums[k][1])
//                         memo[i][j] = max(memo[i][j],  memo[i-nums[k][0]][j-nums[k][1]]);
//                 }
//                 memo[i][j] += 1;
//                 cout<<"memo["<<i<<"]["<<j<<"] = "<<memo[i][j]<<"  ";
//             }
//             cout<<endl;
//         }

//         return memo[m][n];
//     }
// };


// //ͨ��64/71������, ac�ˣ�ԭ��������ѭ����j��kӦ�ô�0��ʼ��֮ǰд�ɴ�1��ʼ
// //�������ÿ��strs��Ӧ��0��1����
// //nums[i][0]��ʾ��strs[i]����0�ĸ���
// //nums[i][1]��ʾ��strs[i]����1�ĸ���

// //memo[i][j][k] ���Ƿ����strs[i]�Ͳ���������ֵ
// //memo[i][j][k] = �� nums[i][] nums[n][] ��
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++){
//                 // if(strs[i][j] == '0')
//                 //     nums[i][0]++;
//                 // else if(strs[i][j] == '1')
//                 //     nums[i][1]++;
//                 //�Ż���������ʾ
//                 nums[i][strs[i][j] - '0']++;
//             }

//         vector<vector<vector<int>>> memo(nums.size(),vector<vector<int>>(m + 1, vector<int>(n + 1, 0))); //memo[i][j][k]��ʾ���Ƿ���Ͳ�����strs[i], j��0��k��1�ܱ�ʾ������Ӽ�����
//         for(int i = 0; i <= m; i ++){
//             for(int j = 0; j <= n; j ++)
//             if(i >= nums[0][0] && j >= nums[0][1])
//                 memo[0][i][j] = 1;
//         }
//         for(int i = 1; i < nums.size(); i ++){
//             for(int j = 0; j <= m; j ++){
//                 for(int k = 0; k <= n; k ++){

//                     memo[i][j][k] = memo[i-1][j][k];
//                     if( j >= nums[i][0] && k >= nums[i][1])
//                         memo[i][j][k] = max(memo[i][j][k], 1 + memo[i-1][j-nums[i][0]][k-nums[i][1]]);

//                 }
//             }
//         }
//         return memo[strs.size()-1][m][n];
//     }
// };

// //ʹ�ù������鷽ʽ������ʡ�ռ䣬�ռ����Ĵ�99.9MB��Ϊ11.5MB
// //ʹ������������
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++)
//                 nums[i][strs[i][j] - '0']++;

//         vector<vector<vector<int>>> memo(2,vector<vector<int>>(m + 1, vector<int>(n + 1, 0))); //memo[i][j][k]��ʾ���Ƿ���Ͳ�����strs[i], j��0��k��1�ܱ�ʾ������Ӽ�����
//         for(int i = 0; i <= m; i ++){
//             for(int j = 0; j <= n; j ++)
//             if(i >= nums[0][0] && j >= nums[0][1])
//                 memo[0][i][j] = 1;
//         }
//         for(int i = 1; i < nums.size(); i ++){
//             for(int j = m; j >= 0; j --){
//                 for(int k = n; k >= 0; k --){

//                     memo[i%2][j][k] = memo[(i-1)%2][j][k];
//                     if( j >= nums[i][0] && k >= nums[i][1])
//                         memo[i%2][j][k] = max(memo[i%2][j][k], 1 + memo[(i-1)%2][j-nums[i][0]][k-nums[i][1]]);

//                 }
//             }
//         }
//         return memo[(strs.size()-1)%2][m][n];
//     }
// };

//ʹ��һ�����飬���𣬽�ʡ�ռ� ʱ��

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

        for (int i = 0; i < strs.size(); i++)
            for (int j = 0; j < strs[i].size(); j++)
                nums[i][strs[i][j] - '0']++;

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); //memo[i][j][k]��ʾ���Ƿ���Ͳ�����strs[i], j��0��k��1�ܱ�ʾ������Ӽ�����
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++)
                if (i >= nums[0][0] && j >= nums[0][1])
                    memo[i][j] = 1;
        }
        for (int i = 1; i < nums.size(); i++)
            for (int j = m; j >= nums[i][0]; j--)
                for (int k = n; k >= nums[i][1]; k--) {

                    memo[j][k] = max(memo[j][k], 1 + memo[j - nums[i][0]][k - nums[i][1]]);
                }


        return memo[m][n];
    }
};


//�ٷ���⣬˼·����һ��
// class Solution {
// public:
//     vector<int> getZerosOnes(string& str) {
//         vector<int> zerosOnes(2);
//         int length = str.length();
//         for (int i = 0; i < length; i++) {
//             zerosOnes[str[i] - '0']++;
//         }
//         return zerosOnes;
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int length = strs.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int i = 0; i < length; i++) {
//             vector<int>&& zerosOnes = getZerosOnes(strs[i]);
//             int zeros = zerosOnes[0], ones = zerosOnes[1];
//             for (int j = m; j >= zeros; j--) {
//                 for (int k = n; k >= ones; k--) {
//                     dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

int main() {

    system("pause");
    return 0;
}