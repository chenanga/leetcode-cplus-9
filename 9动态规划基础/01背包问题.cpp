#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

////���仯����
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
//	//�� [0...index] ����Ʒ������ݻ�Ϊc�ı���������ֵ
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


////��̬�滮
//class Knapsack01 {
//public:
//	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
//		assert(w.size() == v.size());
//		int n = w.size();
//		if (n == 0) 
//			return 0;
//		vector<vector<int>> memo (n, vector<int>(C + 1, -1)); // n * (C+1)
//
//		//memo[0][]ʱ���ʼ��
//		for (int j = 0; j < C; j++) {
//			if (j >= w[0])
//				memo[0][j] = v[0];
//			else
//				memo[0][j] = 0;
//		}
//
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < C; j++) {
//				//���Ƿ����i�����壬�Ͳ���������ֵ
//				memo[i][j] = memo[i - 1][j];
//				if (j - w[i] >= 0)
//					memo[i][j] = max(memo[i][j],  v[i] + memo[i - 1][j - w[i]] );
//			}
//		}
//		return memo[n-1][C];
//	}
//};
// 


////��̬�滮���ռ��Ż�,ֻ�����оͿ���
////֮ǰʹ������һ����һ��pre��cur���飬��һС��ѭ����� pre=cur��Ȼ���ڿ�ʼ����
////�����Ǹ�����ż��ϵ�����еĻ���ż�������ϣ����������£�ȡ���պ��������������ұ���ÿ��ѭ����ĸ�ֵ��
//class Knapsack01 {
//public:
//	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
//		assert(w.size() == v.size());
//		int n = w.size();
//		if (n == 0)
//			return 0;
//		vector<vector<int>> memo(2, vector<int>(C + 1, -1)); // n * (C+1)
//
//		//memo[0][]ʱ���ʼ��
//		for (int j = 0; j < C; j++) {
//			if (j >= w[0])
//				memo[0][j] = v[0];
//			else
//				memo[0][j] = 0;
//		}
//
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < C; j++) {
//				//���Ƿ����i�����壬�Ͳ���������ֵ
//				memo[i%2][j] = memo[(i-1)%2][j];
//				if (j - w[i] >= 0)
//					memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j - w[i]]);
//			}
//		}
//		return memo[(n-1)%2][C];
//	}
//};

//��̬�滮���ռ��Ż�,ֻ��1�оͿ���
//��ΪÿС�ָ���ʱ�򣬵�ǰԪ���Ǻ���һ�е�ǰλ��Ԫ�أ��Լ���ǰ��Ԫ���йأ���ô���ǴӺ���ǰ���£���Ҳֱ��ԭ���޸ģ�����Ҳ�ò�����Щ����
class Knapsack01 {
public:
	int knapsack01(const vector<int>& w, const vector<int>& v, int C) {
		assert(w.size() == v.size());
		int n = w.size();
		if (n == 0)
			return 0;
		vector<int> memo(C + 1, -1); // 1 * (C+1)

		//memo[0][]ʱ���ʼ��
		for (int j = 0; j < C; j++) {
			if (j >= w[0])
				memo[j] = v[0];
			else
				memo[j] = 0;
		}

		for (int i = 1; i < n; i++) 
			for (int j = C - 1; j >= w[i]; j--) 
				//���Ƿ����i�����壬�Ͳ���������ֵ
				memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
			
		return memo[C];
	}
};

int main() {

	system("pause");
	return 0;
}