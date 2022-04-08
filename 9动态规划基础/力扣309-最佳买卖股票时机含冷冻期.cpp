#include<iostream>
#include<vector>

using namespace std;

//��̬�滮û�������������˹ٷ������������
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n <= 1) return 0;
//         //memo[i][0]�����i����й�Ʊ��˵����i-1�����룬����i-1����Ѿ����� max(memo[i-1][0],memo[i-1][2]-prices[i] )
//         //memo[i][1]�����i��δ���й�Ʊ���Ҵ����䶳��.˵��i-1����У�i������ memo[i-1][0] + prices[i]
//         //memo[i][2]�����i��δ���й�Ʊ���Ҳ������䶳��. i-1��ʱ�����䶳�ڻ���һֱ����max(memo[i-1][1],memo[i-1][2])
//     /*
//     memo[i][] ��ʾ�� i �����֮��ġ��ۼ��������
//     ����ġ������䶳�ڡ�ָ�����ڵ� i �����֮���״̬��
//     Ҳ����˵������� i �����֮�����䶳�ڣ���ô�� i+1���޷������Ʊ��
//     */
//         vector<vector<int>> memo(n, vector<int>(3, -1));
//         memo[0][0] = - prices[0]; //��0����еģ�ֻ���ǵ������
//         memo[0][1] = 0; //�����0��δ���й�Ʊ���Ҳ������䶳��
//         memo[0][2] = 0; //�����0��δ���й�Ʊ���Ҵ����䶳��

//         for(int i = 1; i < n; i ++){

//             memo[i][0] = max(memo[i-1][0], memo[i-1][2]-prices[i] );
//             memo[i][1] = memo[i-1][0] + prices[i];
//             memo[i][2] = max(memo[i-1][1],memo[i-1][2]);
//         }
//         //������Ҫ����memo[n-1][0],memo[n-1][1],memo[n-1][2]�����ֵ
//         //��������������һ����й�Ʊ�϶���û�����������ߵģ���Ҳ����д��max(memo[n-1][1],memo[n-1][2])
//         // return max(max(memo[n-1][0],memo[n-1][1]),memo[n-1][2]);
//         return max(memo[n-1][1],memo[n-1][2]);

//     }
// };

//�Ż�1���ռ䣬����ÿһ��״ֻ̬��ǰһ���й�
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        //memo[i][0]�����i����й�Ʊ��˵����i-1�����룬����i-1����Ѿ����� max(memo[i-1][0],memo[i-1][2]-prices[i] )
        //memo[i][1]�����i��δ���й�Ʊ���Ҵ����䶳��.˵��i-1����У�i������ memo[i-1][0] + prices[i]
        //memo[i][2]�����i��δ���й�Ʊ���Ҳ������䶳��. i-1��ʱ�����䶳�ڻ���һֱ����max(memo[i-1][1],memo[i-1][2])
    /*
    memo[i][] ��ʾ�� i �����֮��ġ��ۼ��������
    ����ġ������䶳�ڡ�ָ�����ڵ� i �����֮���״̬��
    Ҳ����˵������� i �����֮�����䶳�ڣ���ô�� i+1���޷������Ʊ��
    */

        vector<int> pre(3, 0);
        pre[0] = -prices[0];//��ʼ��Ϊ0���ҵ�һ��Ԫ����Ϊ- prices[0]

        vector<int> cur(3, -1);
        // memo[0][0] = - prices[0]; //��0����еģ�ֻ���ǵ������
        // memo[0][1] = 0; //�����0��δ���й�Ʊ���Ҳ������䶳��
        // memo[0][2] = 0; //�����0��δ���й�Ʊ���Ҵ����䶳��
        for (int i = 1; i < n; i++) {

            cur[0] = max(pre[0], pre[2] - prices[i]);
            cur[1] = pre[0] + prices[i];
            cur[2] = max(pre[1], pre[2]);
            pre = cur;
        }
        //������Ҫ����memo[n-1][0],memo[n-1][1],memo[n-1][2]�����ֵ
        //��������������һ����й�Ʊ�϶���û�����������ߵģ���Ҳ����д��max(memo[n-1][1],memo[n-1][2])
        // return max(max(memo[n-1][0],memo[n-1][1]),memo[n-1][2]);
        return max(cur[1], cur[2]);

    }
};

int main() {

	system("pause");
	return 0;
}