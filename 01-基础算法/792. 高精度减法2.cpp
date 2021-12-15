/*************************************
* ��Ŀ��792. �߾��ȼ���2
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];  // �Զ���ʼ��Ϊ 0 

bool cmp(string s1, string s2) {  // �� s1 < s2������ true�����򷵻� false 
	if(s1.size() != s2.size()) return s1.size() < s2.size();  // λ����ͬ����λ�� 
	else return s1 < s2;  // λ����ͬ���ȴ�С
}

int main() {

	// 1�����롢�ȽϺʹ洢 
	string s1, s2;
	cin >> s1 >> s2;
	if(cmp(s1, s2)) {  // s1 ������� < s2 ������������� true 
		cout << "-";
		swap(s1, s2);  // �ַ������� 
	}
	int len1 = s1.size(), len2 = s2.size();
	// s1 ����浽 a
	for(int i = 0; i < len1; i++) {
		a[i] = s1[len1-i-1] - 48;  // - '0'
	}
	// s2 ����浽 b 
	for(int i = 0; i < len2; i++) {
		b[i] = s2[len2-i-1] - '0';
	}
	// 2��������  a-b
	int len = max(len1, len2);
	for(int i = 0; i < len; i++) { 
		if(a[i] < b[i]) {  // �������������λ 
			a[i] += 10;
			a[i+1]--;
		}
		c[i] = a[i] - b[i];  // ���� 
	}
	// 3��ȥ��ǰ���㣬0~len-1
	while(len > 1 && c[len-1] == 0) len--;
	// 4��������� 
	for(int i = len-1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
