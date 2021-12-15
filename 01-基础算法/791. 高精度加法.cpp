/*************************************
* ��Ŀ��791. �߾��ȼӷ�
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> a, vector<int> b) {  // c = a + b
	vector<int> c;
	int t = 0;  // ��λ 
	for(int i = 0; i < a.size() || i < b.size(); i++) {
		if(i < a.size()) t += a[i];  // ��� a ��û�м��� 
		if(i < b.size()) t += b[i];  // ��� b ��û�м��� 
		c.push_back(t % 10);
		t /= 10;  // ��λ 
	}
	if(t) c.push_back(t);  // ���λ���н�λ 
	return c; 
}

int main() {
	
	string s1, s2;
	vector<int> a, b;
	// 1������ʹ洢 
	cin >> s1 >> s2;
	for(int i = s1.size() - 1; i >= 0; i--) {  // s1 ����洢�� a 
		a.push_back(s1[i] - '0');  // �ǵü� '0' 
	}
	for(int i = s2.size() - 1; i >= 0; i--) {  // s2 ����洢�� b 
		b.push_back(s2[i] - '0');  // �ǵü� '0'
	}
	// 2�����ӷ� 
	auto c = add(a, b);
	// 3���������
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}  

	return 0;
}
