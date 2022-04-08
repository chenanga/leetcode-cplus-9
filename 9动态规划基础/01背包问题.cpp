#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

////记忆化搜索
//class Knapsack01{
//public:
//	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
//
//		int n = w.size();
//		memo = vector<vector<int>>(n, vector<int>(C + 1, -1)); // n * (C+1)
//		return bestValue(w, v, n - 1, C);
//	}
//
//private:
//	vector<vector<int>> memo;
//
//	//用 [0...index] 的物品，填充容积为c的背包的最大价值
//	int bestValue(const vector<int>& w, const vector<int>& v, int index, int c) {
//
//		if (index < 0 || c <= 0)
//			return 0;
//		if (memo[index][c] != -1)
//			return memo[index][c];
//
//		int res = bestValue(w, v, index - 1, c);
//		if (c >= w[index])
//			res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
//		memo[index][c] = res;
//		return memo[index][c];
//	}
//
//};


////动态规划
//class Knapsack01 {
//public:
//	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
//		assert(w.size() == v.size());
//		int n = w.size();
//		if (n == 0) 
//			return 0;
//		vector<vector<int>> memo (n, vector<int>(C + 1, -1)); // n * (C+1)
//
//		//memo[0][]时候初始化
//		for (int j = 0; j < C; j++) {
//			if (j >= w[0])
//				memo[0][j] = v[0];
//			else
//				memo[0][j] = 0;
//		}
//
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < C; j++) {
//				//考虑放入第i个物体，和不放入的最大值
//				memo[i][j] = memo[i - 1][j];
//				if (j - w[i] >= 0)
//					memo[i][j] = max(memo[i][j],  v[i] + memo[i - 1][j - w[i]] );
//			}
//		}
//		return memo[n-1][C];
//	}
//};
// 


////动态规划，空间优化,只用两行就可以
////之前使用两行一般是一个pre和cur数组，在一小轮循环完后 pre=cur，然后在开始下轮
////这里是根据奇偶关系，两行的话，偶数行在上，奇数行在下，取余后刚好能满足条件，且避免每轮循环后的赋值。
//class Knapsack01 {
//public:
//	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
//		assert(w.size() == v.size());
//		int n = w.size();
//		if (n == 0)
//			return 0;
//		vector<vector<int>> memo(2, vector<int>(C + 1, -1)); // n * (C+1)
//
//		//memo[0][]时候初始化
//		for (int j = 0; j < C; j++) {
//			if (j >= w[0])
//				memo[0][j] = v[0];
//			else
//				memo[0][j] = 0;
//		}
//
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < C; j++) {
//				//考虑放入第i个物体，和不放入的最大值
//				memo[i%2][j] = memo[(i-1)%2][j];
//				if (j - w[i] >= 0)
//					memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j - w[i]]);
//			}
//		}
//		return memo[(n-1)%2][C];
//	}
//};

//动态规划，空间优化,只用1行就可以
//因为每小轮更新时候，当前元素是和上一行当前位置元素，以及以前的元素有关，那么考虑从后往前更新，这也直接原地修改，后续也用不到这些内容
class Knapsack01 {
public:
	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
		assert(w.size() == v.size());
		int n = w.size();
		if (n == 0)
			return 0;
		vector<int> memo(C + 1, -1); // 1 * (C+1)

		//memo[0][]时候初始化
		for (int j = 0; j < C; j++) {
			if (j >= w[0])
				memo[j] = v[0];
			else
				memo[j] = 0;
		}

		for (int i = 1; i < n; i++) 
			for (int j = C - 1; j >= w[i]; j--) 
				//考虑放入第i个物体，和不放入的最大值
				memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
			
		return memo[C];
	}
};

int main() {

	system("pause");
	return 0;
}