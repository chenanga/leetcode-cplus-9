#include<iostream>
#include<vector>

using namespace std;



// //��̬�滮
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         //memo[i][j]����ǰ���굽finish�Ĳ�ͬ·������,long long ��ֹ���
//         vector<vector<long>> memo(m, vector<long>(n, 0));//��ʼ��,�����ϰ���ĸ���Ҳ����Ϊ0���������ܸ��ĺ����ϰ���ĺ���
//         if(obstacleGrid[m-1][n-1] != 1)//������½�һ��û���ϰ������Ϊ1
//             memo[m-1][n-1] = 1;

//         for(int i = n-2; i >= 0; i --)//��ʼ��������һ��
//             if(obstacleGrid[m-1][i] != 1)//�����ǰ�������ϰ��������Ϊ��������һ����ͬ��������ϰ������������Ϊ��ʼ��ʱ���Ѿ���0
//                 memo[m-1][i] = memo[m-1][i+1];

//         for(int i = m-2; i >= 0; i --)//��ʼ�����ұ�һ��
//             if(obstacleGrid[i][n-1] != 1)
//                 memo[i][n-1] = memo[i+1][n-1];

//         for(int i = m-2; i >=0; i --){
//             for(int j = n-2; j >= 0; j --){
//                 if(obstacleGrid[i][j] != 1)
//                 memo[i][j] = memo[i+1][j] + memo[i][j+1];
//             }
//         }
//         return memo[0][0];
//     }
// };

//��̬�滮���ռ��Ż�,ʹ����������
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //memo[i][j]����ǰ���굽finish�Ĳ�ͬ·������,long long ��ֹ���
        vector<long>next(n, 0);

        if (obstacleGrid[m - 1][n - 1] != 1)//������½�һ��û���ϰ������Ϊ1
            next[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)//��ʼ��������һ��
            if (obstacleGrid[m - 1][i] != 1)//�����ǰ�������ϰ��������Ϊ��������һ����ͬ��������ϰ������������Ϊ��ʼ��ʱ���Ѿ���0
                next[i] = next[i + 1];

        for (int i = m - 2; i >= 0; i--) {
            vector<long>cur(n, 0);
            if (obstacleGrid[i][n - 1] != 1)//��ʼ�������ڶ������ұ�һ����
                cur[n - 1] = next[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] != 1)
                    cur[j] = next[j] + cur[j + 1];
                else
                    cur[j] = 0;

            }
            next = cur;
        }

        return next[0];
    }
};

int main() {

	system("pause");
	return 0;
}