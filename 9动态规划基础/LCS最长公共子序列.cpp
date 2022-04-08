#include<iostream>
#include<vector>

using namespace std;


//问题描述
/*
给出两个字符串S1和S2，求这两个字符串的最长公共子序列的长度
S1 = ABCD  --ABD
S2 = AEBD	--ABD
*/

//问题思路
/*
需要两个维度

LCS( m , n ) S1[0…m] 和 S2[0…n] 的最长公共子序列的长度

当 S1[m] == S2[n] : 
	LCS(m,n) = 1 + LCS(m-1,n-1)
当 S1[m] != S2[n] :  
LCS(m,n) = max( LCS(m-1,n) , LCS(m,n-1) )

*/


//递归
class LCS1 {
public:
	int lcs(string & s1, string & s2) {
		return __lcs(s1, s2, s1.size()-1, s2.size()-1 );
	}

private:
	//LCS(m, n) S1[0…m] 和 S2[0…n] 的最长公共子序列的长度
	int __lcs(string& s1, string& s2, int m, int n) {
		if (m < 0 || n < 0)
			return 0;

		if (s1[m] == s2[n]) {
			return 1 + __lcs(s1, s2, m - 1, n - 1);
		}
		else {
			return max(__lcs(s1, s2, m, n - 1), __lcs(s1, s2, m - 1, n));
		}


	}
};



//记忆化搜索
class LCS2 {
public:
	int lcs(string& s1, string& s2) {
		memo = vector<vector<int>>(s1.size() , vector<int>(s2.size() , -1));
		return __lcs(s1, s2, s1.size() - 1, s2.size() - 1);
	}

private:
	vector<vector<int>> memo;
	//LCS(m, n) S1[0…m] 和 S2[0…n] 的最长公共子序列的长度
	int __lcs(string& s1, string& s2, int m, int n) {
		if (m < 0 || n < 0)
			return 0;
		if (memo[m][n] != -1)
			return memo[m][n];

		if (s1[m] == s2[n]) {
			cout << "s1[m]" << s1[m] << endl;
			return memo[m][n] = 1 + __lcs(s1, s2, m - 1, n - 1);
		}
		else {
			return memo[m][n] = max(__lcs(s1, s2, m, n - 1), __lcs(s1, s2, m - 1, n));
		}


	}
};
//动态规划

int main() {
	string s1 = "ABCDFEEA";
	string s2 = "AEBDEGEEA";
	cout << LCS2().lcs(s1, s2);
	system("pause");
	return 0;
}