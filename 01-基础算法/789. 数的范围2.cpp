/*************************************
* 题目：789. 数的范围
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while(q--) {
		int k;
		cin >> k;
		int lower = lower_bound(a, a + n, k) - a;  // 第一个 >= k 的位置 
		int upper = upper_bound(a, a + n, k) - a;  // 第一个大于 k 的位置
		if(a[lower] == k) cout << lower << " ";  // 输出起始位置 
		else cout << "-1 ";
		if(a[upper-1] == k) cout << upper - 1 << endl; 
		else cout << "-1\n";  // 输出结束位置 
	}
	
	return 0;
}
