#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];

int main() {

	// 1������ʹ洢 
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	for(int i = 0; i < len1; i++) {  // s1 ����洢�� a �� 
		a[i] = s1[len1-1-i] - '0';  // �ǵü�ȥ '0'
	}
	for(int i = 0; i < len2; i++) {  // s2 ����洢�� b �� 
		b[i] = s2[len2-1-i] - '0';  // �ǵü�ȥ '0'
	}
	// 2�����ӷ����߼ӱ߽�λ�� 
	int len = max(s1.size(), s2.size());
	for(int i = 0; i < len; i++) {
		c[i] += a[i] + b[i];  // ��ǰλ��ӣ��ټ��ϸոյĽ�λ
		if(c[i] >= 10) {  // ��Ҫ��ǰ��λ 
			c[i+1] = c[i] / 10;  
			c[i] %= 10;
		}
	}
	// 3��������λ�Ľ�λ��� 
	if(c[len] > 0) {  // ���λ�н�λ
		len++;
	}
	// 4��������� 
	for(int i = len-1; i >= 0; i--) {  // �������
		cout << c[i];
	}

	return 0;
}
