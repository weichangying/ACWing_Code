/*************************************
* ��Ŀ��793. �߾��ȳ˷�
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> a, int b) {  // c = a * b
	vector<int> c;
	int t = 0;  // ��λ
	for(int i = 0; i < a.size() || t; i++) {  // �� b ����һ���������� 
		if(i < a.size()) t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;  // ��λ 
	} 
	// ȥǰ����
	while(c.size() > 1 && c.back() == 0) c.pop_back(); 
	return c; 
}

int main() {
	
	// 1������ʹ洢
	string s;
	int b;
	vector<int> a;
	cin >> s >> b;
	for(int i = s.size() - 1; i >= 0; i--) {  // s ����洢�� a  
		a.push_back(s[i] - '0');  // �ǵü� '0' 
	}
	// 2�����˷�
	auto c = mul(a, b);
	// 3��������� 
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
