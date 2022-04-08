#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//超时
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         for(int i = 0; i < triangle.size(); i ++)
//             memo.push_back(vector<int>(triangle[i].size(),INT_MAX - 1));
//         calcWays(triangle, 0, 0, 0);
//         sort(res.begin(), res.end(), less<int>());
//         return res[0];
//     }
// private:
//     vector<vector<int>>memo;
//     vector<int>res;
//     void calcWays(vector<vector<int>>& triangle, const int & row, const int & cursum, const int & index){
//         // cout<<"row"<<row<<endl;
//         if(row == triangle.size()){
//             res.push_back(cursum);
//             return;
//         }

//         for(int i = 0; i < 2 && index + i < triangle[row].size(); i ++) //这里要确保i + index不出届
//             calcWays(triangle, row + 1, cursum + triangle[row][i + index], i + index);

//         return ;  
//     }
// };
// //ac 动态规划
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         if(triangle.size() == 1) return triangle[0][0];
//         vector<vector<int>>memo;
//         for(int i = 0; i < triangle.size(); i ++)
//             memo.push_back(vector<int>(triangle[i].size(),INT_MAX - 1));

//         memo[0][0] = triangle[0][0];

//         vector<int>res;
//         for(int i = 1; i < triangle.size(); i ++){
//             for(int j = 0; j < triangle[i].size(); j ++){
//                 if(j == 0) //每一行的左边界，此时上一行同位置左边是没有元素的
//                     memo[i][j] = memo[i-1][j] + triangle[i][j];
//                 else if(j == triangle[i].size() - 1) //每一行的右边界，此时上一行同位置是没有元素的
//                     memo[i][j] = memo[i-1][j-1] + triangle[i][j];
//                 else
//                     memo[i][j] = min(memo[i-1][j], memo[i-1][j-1]) + triangle[i][j];
//                 if(i == triangle.size() - 1) //把最后一行加入res，排序，然后直接返回最小值
//                     res.push_back(memo[i][j]);
//             }
//         }
//         sort(res.begin(), res.end(), less<int>());
//         return res[0];
//     }
// };

//ac 动态规划,减少空间使用,因为i只和i-1有关，所有只要两行数组就可以
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        vector<vector<int>>memo;

        memo.push_back(vector<int>(triangle[triangle.size() - 1].size(), INT_MAX - 1));
        memo.push_back(vector<int>(triangle[triangle.size() - 1].size(), INT_MAX - 1));

        memo[0][0] = triangle[0][0];

        vector<int>res;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) //每一行的左边界，此时上一行同位置左边是没有元素的
                    memo[i % 2][j] = memo[(i - 1) % 2][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1) //每一行的右边界，此时上一行同位置是没有元素的
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + triangle[i][j];
                else
                    memo[i % 2][j] = min(memo[(i - 1) % 2][j], memo[(i - 1) % 2][j - 1]) + triangle[i][j];
                if (i == triangle.size() - 1) //把最后一行加入res，排序，然后直接返回最小值
                    res.push_back(memo[i % 2][j]);
            }
        }
        sort(res.begin(), res.end(), less<int>());
        return res[0];
    }
};
int main() {

    system("pause");
    return 0;
}