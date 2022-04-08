#include<iostream>
#include<vector>

using namespace std;


// //���仯����
// class Solution {
// public:
//     int integerBreak(int n) {
//         memo = vector<int>(n+1, -1);
//         return breadkInteger(n);
//     }
// private:
//     vector<int> memo;
//     int max3(int a, int b, int c){
//         return max(a, max(b,c));
//     }
//     //��n���зָ���ٷָ������֣������Ի�õ����˻�
//     int breadkInteger(int n){
//         if(n == 1) return 1;

//         if(memo[n] != -1)
//             return memo[n];

//         int res = -1;

//         for(int i = 1; i <= n - 1; i ++)
//             // i   n-i
//             res = max3(res, i * (n-i), i * breadkInteger(n-i));

//         memo[n] = res;

//         return res;
//     }
// };

//��̬�滮
class Solution {
public:
    int integerBreak(int n) {
        //memo[i]��ʾ������i���зָ���ٷָ������֣������Ի�õ����˻�
        vector<int>memo(n + 1, -1);
        memo[1] = 1;

        for (int i = 2; i <= n; i++)
            //���memo[i]
            for (int j = 1; j <= i - 1; j++) {
                // j + (i - j)
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }

        return memo[n];
    }
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
};

int main() {

	system("pause");
	return 0;
}