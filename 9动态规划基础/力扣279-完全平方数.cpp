#include<iostream>
#include<vector>

using namespace std;

//ͼ�Ľⷨ
// class Solution {
// public:
//     int numSquares(int n) {

//         queue<pair<int,int>>que;
//         que.push(make_pair(n, 0));
//         vector<bool>visited(n+1, false);//�����������飬�ж�ÿ���ڵ��Ƿ񱻷���
//         visited[n] = true;
//         while(!que.empty()){
//             int num = que.front().first;
//             int distance = que.front().second;
//             que.pop();
//             if(num == 0) return distance;
//             for(int i = 1; num -i*i>=0; i++){
//                 if(!visited[num-i*i]){
//                     que.push(make_pair((num -i*i),distance+1));
//                     visited[num-i*i] = true;
//                 }
//             }
//         }
//         return -1;;
//     }
// };
//һЩϸ���Ż�
// class Solution {
// public:
//     int numSquares(int n) {

//         queue<pair<int,int>>que;
//         que.push(make_pair(n, 0));
//         vector<bool>visited(n+1, false);//�����������飬�ж�ÿ���ڵ��Ƿ񱻷���
//         visited[n] = true;
//         while(!que.empty()){
//             int num = que.front().first;
//             int distance = que.front().second;
//             que.pop();

//             for(int i = 1; ; i++){
//                 int a = num - i * i;
//                 if(a < 0) break;
//                 if(a == 0) return distance+1;

//                 if(!visited[num-i*i]){
//                     que.push(make_pair((num -i*i),distance+1));
//                     visited[num-i*i] = true;
//                 }
//             }
//         }
//         return -1;;
//     }
// };

//��̬�滮˼·���
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> memo(n+1, n+1); //��¼��ǰ����n�����Ǽ�����ȫƽ�����ĺ�
//         memo[0] = 0;
//         memo[1] = 1;

//         for(int i = 2; i <= n; i ++){
//             //����i��Ϊj^2 + (i - j^2)
//             for(int j = sqrt(i) ; j >= 1 ; j --){
//                 memo[i] = min(memo[i], 1 + memo[i-j*j]);
//                 // cout<<"i = "<<i<<", j = "<<j<<": memo[i] = "<<memo[i]<<endl;
//             }
//         }

//         return memo[n];
//     }
// };

//��̬�滮˼·���,���ڹٷ�����Ż�
class Solution {
public:
    int numSquares(int n) {

        vector<int> memo(n + 1, n + 1); //��¼��ǰ����n�����Ǽ�����ȫƽ�����ĺ�
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            //����i��Ϊj^2 + (i - j^2)
            int minn = n + 1;
            for (int j = sqrt(i); j >= 1; j--) {
                minn = min(minn, memo[i - j * j]);
            }
            memo[i] = minn + 1; //��1�ŵ�ѭ����ߣ���������һЩ�ٶȡ���Ϊһ��ѭ����һ�Σ�����ŵ�ѭ���ڲ���ÿ�ζ��ӡ�
        }
        return memo[n];
    }
};



int main() {
	int n = 5;
	vector<int> f(n + 1);
	for (int i = 0; i < n; i++)
		cout << f[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}