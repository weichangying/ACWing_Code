/*************************************
* ��Ŀ��
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

/*************************************
* ��Ŀ��793. �߾��ȳ˷�
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> a, int b, int& r) {  // a / b���� c���� r 
	vector<int> c;
	for(int i = a.size() - 1; i >= 0; i--) {  // �Ӹ�λ��ʼ�� 
		r = r * 10 + a[i];
		c.push_back(r / b);  // �� 
		r %= b;  // ���� 
	} 
	reverse(c.begin(), c.end());  // ��ת 
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
	// 2��������
	int r  = 0;  // ���� 
	auto c = div(a, b, r);  // �� 
	// 3��������� 
	for(int i = c.size() - 1; i >= 0; i--) {  // ����� 
		cout << c[i];
	}
	cout << endl << r << endl;  // ������� 
	
	return 0;
}
