#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//��ʱ
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

//         for(int i = 0; i < 2 && index + i < triangle[row].size(); i ++) //����Ҫȷ��i + index������
//             calcWays(triangle, row + 1, cursum + triangle[row][i + index], i + index);

//         return ;  
//     }
// };
// //ac ��̬�滮
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
//                 if(j == 0) //ÿһ�е���߽磬��ʱ��һ��ͬλ�������û��Ԫ�ص�
//                     memo[i][j] = memo[i-1][j] + triangle[i][j];
//                 else if(j == triangle[i].size() - 1) //ÿһ�е��ұ߽磬��ʱ��һ��ͬλ����û��Ԫ�ص�
//                     memo[i][j] = memo[i-1][j-1] + triangle[i][j];
//                 else
//                     memo[i][j] = min(memo[i-1][j], memo[i-1][j-1]) + triangle[i][j];
//                 if(i == triangle.size() - 1) //�����һ�м���res������Ȼ��ֱ�ӷ�����Сֵ
//                     res.push_back(memo[i][j]);
//             }
//         }
//         sort(res.begin(), res.end(), less<int>());
//         return res[0];
//     }
// };

//ac ��̬�滮,���ٿռ�ʹ��,��Ϊiֻ��i-1�йأ�����ֻҪ��������Ϳ���
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
                if (j == 0) //ÿһ�е���߽磬��ʱ��һ��ͬλ�������û��Ԫ�ص�
                    memo[i % 2][j] = memo[(i - 1) % 2][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1) //ÿһ�е��ұ߽磬��ʱ��һ��ͬλ����û��Ԫ�ص�
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + triangle[i][j];
                else
                    memo[i % 2][j] = min(memo[(i - 1) % 2][j], memo[(i - 1) % 2][j - 1]) + triangle[i][j];
                if (i == triangle.size() - 1) //�����һ�м���res������Ȼ��ֱ�ӷ�����Сֵ
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