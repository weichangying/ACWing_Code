/*************************************
* ��Ŀ��789. ���ķ�Χ
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
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
		int lower = lower_bound(a, a + n, k) - a;  // ��һ�� >= k ��λ�� 
		int upper = upper_bound(a, a + n, k) - a;  // ��һ������ k ��λ��
		if(a[lower] == k) cout << lower << " ";  // �����ʼλ�� 
		else cout << "-1 ";
		if(a[upper-1] == k) cout << upper - 1 << endl; 
		else cout << "-1\n";  // �������λ�� 
	}
	
	return 0;
}
