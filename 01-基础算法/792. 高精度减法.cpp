/*************************************
* ��Ŀ��792. �߾��ȼ���
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) {  // �� s1 < s2������ true�����򷵻� false 
	if(s1.size() != s2.size()) return s1.size() < s2.size();  // λ����ͬ����λ�� 
	else return s1 < s2;  // λ����ͬ���ȴ�С
}

vector<int> sub(vector<int> a, vector<int> b) {  // c = a - b
	vector<int> c;
	int t = 0;  // ��λ
	for(int i = 0; i < a.size(); i++) {
		t = a[i] - t;  // ��ȥ��λ 
		if(i < b.size()) t -= b[i];  // ��ȥ b[i] 
		c.push_back((t + 10) % 10);  // t >= 0�����Ǳ���t < 0�����ǽ�λ֮���ֵ 
		if(t < 0) t = 1;  // ��λ 
		else t = 0;  // û�н�λ 
	} 
	// ȥǰ����
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c; 
}

int main() {
	
	string s1, s2;
	vector<int> a, b;
	// 1�����롢�ȽϺʹ洢
	cin >> s1 >> s2;
	if(cmp(s1, s2)) {  // �� s1 < s2��������Ų��ҽ��� s1 s2 
		cout << "-";
		swap(s1, s2);
	}
	for(int i = s1.size() - 1; i >= 0; i--) {  // s1 ����洢�� a
		a.push_back(s1[i] - '0');  // �ǵü� '0' 
	}
	for(int i = s2.size() - 1; i >= 0; i--) {  // s2 ����洢�� b 
		b.push_back(s2[i] - '0');  // �ǵü� '0' 
	}
	// 2��������
	auto c = sub(a, b);
	// 3��������� 
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}

	return 0;
}
