/*************************************
* 题目：789. 数的范围
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int BinSearch1(int a[], int l, int r, int x) {  // 找到第一个 >= x 的数 
	int ans = 0;  // 记得初始化，不然会越界 
	while(l <= r) {
		int mid = l + r >> 1;
		if(a[mid] >= x) {
			ans = mid;
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	if(a[ans] == x) return ans;
	else return -1;
}

int BinSearch2(int a[], int l, int r, int x) {   
	int ans = -1; 
	while(l <= r) {  // 找到第一个 > x 的数
		int mid = l + r >> 1;
		if(a[mid] > x) {
			ans = mid;
			r = mid - 1;
		}else {  // x >= a[mid]
			l = mid + 1;
		}
	}
	if(a[r] == x) return r;  // 最后一个元素等于 x
	else if(a[ans-1] == x) return ans - 1;  // x 的结束位置是 ans - 1 
	else return - 1; 
}

int main() {
	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while(q--) {
		int k;
		cin >> k;
		int lower = BinSearch1(a, 0, n-1, k);  
		int upper = BinSearch2(a, 0, n-1, k);  
		cout << lower << " ";  // 输出起始位置 
		if(lower != -1 && upper == -1) cout << lower << endl;  // 只有一个元素 
		else cout << upper << endl;  // 输出结束位置 
	}
	
	return 0;
}
