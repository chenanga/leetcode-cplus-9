#include<iostream>
#include<vector>

using namespace std;

//图的解法
// class Solution {
// public:
//     int numSquares(int n) {

//         queue<pair<int,int>>que;
//         que.push(make_pair(n, 0));
//         vector<bool>visited(n+1, false);//设立辅助数组，判断每个节点是否被访问
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
//一些细节优化
// class Solution {
// public:
//     int numSquares(int n) {

//         queue<pair<int,int>>que;
//         que.push(make_pair(n, 0));
//         vector<bool>visited(n+1, false);//设立辅助数组，判断每个节点是否被访问
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

//动态规划思路求解
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> memo(n+1, n+1); //记录当前数字n最少是几个完全平方数的和
//         memo[0] = 0;
//         memo[1] = 1;

//         for(int i = 2; i <= n; i ++){
//             //数字i拆为j^2 + (i - j^2)
//             for(int j = sqrt(i) ; j >= 1 ; j --){
//                 memo[i] = min(memo[i], 1 + memo[i-j*j]);
//                 // cout<<"i = "<<i<<", j = "<<j<<": memo[i] = "<<memo[i]<<endl;
//             }
//         }

//         return memo[n];
//     }
// };

//动态规划思路求解,基于官方求解优化
class Solution {
public:
    int numSquares(int n) {

        vector<int> memo(n + 1, n + 1); //记录当前数字n最少是几个完全平方数的和
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            //数字i拆为j^2 + (i - j^2)
            int minn = n + 1;
            for (int j = sqrt(i); j >= 1; j--) {
                minn = min(minn, memo[i - j * j]);
            }
            memo[i] = minn + 1; //加1放到循环外边，可以提升一些速度。因为一个循环加一次，如果放到循环内部，每次都加。
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