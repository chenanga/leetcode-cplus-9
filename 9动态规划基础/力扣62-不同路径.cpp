#include<iostream>
#include<vector>

using namespace std;

// //��̬�滮
// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> memo(m, vector<int>(n, 1));//��ʼ�������ұ�һ���ߺ����±�һ���߶���1
//         //memo[i][j]����ǰ���굽finish�Ĳ�ͬ·������
//         for(int i = m-2; i >=0; i --){
//             for(int j = n-2; j >= 0; j --){
//                 memo[i][j] = memo[i+1][j] + memo[i][j+1];
//             }
//         }
//         return memo[0][0];
//     }
// };

//
//��̬�滮,�ռ��Ż�,sʹ������������
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);//��ʼ�������ұ�һ����1
        vector<int> next(n, 1);//��ʼ���������±�һ����1

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                cur[j] = next[j] + cur[j + 1];
            }
            next = cur;
        }
        return cur[0];
    }
};

int main() {

	system("pause");
	return 0;
}