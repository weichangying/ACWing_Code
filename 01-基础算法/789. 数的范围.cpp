/*************************************
* ��Ŀ��789. ���ķ�Χ
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int BinSearch1(int a[], int l, int r, int x) {  // �ҵ���һ�� >= x ���� 
	int ans = 0;  // �ǵó�ʼ������Ȼ��Խ�� 
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
	while(l <= r) {  // �ҵ���һ�� > x ����
		int mid = l + r >> 1;
		if(a[mid] > x) {
			ans = mid;
			r = mid - 1;
		}else {  // x >= a[mid]
			l = mid + 1;
		}
	}
	if(a[r] == x) return r;  // ���һ��Ԫ�ص��� x
	else if(a[ans-1] == x) return ans - 1;  // x �Ľ���λ���� ans - 1 
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
		cout << lower << " ";  // �����ʼλ�� 
		if(lower != -1 && upper == -1) cout << lower << endl;  // ֻ��һ��Ԫ�� 
		else cout << upper << endl;  // �������λ�� 
	}
	
	return 0;
}
