/*************************************
* 题目：791. 高精度加法
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> a, vector<int> b) {  // c = a + b
	vector<int> c;
	int t = 0;  // 进位 
	for(int i = 0; i < a.size() || i < b.size(); i++) {
		if(i < a.size()) t += a[i];  // 如果 a 还没有加完 
		if(i < b.size()) t += b[i];  // 如果 b 还没有加完 
		c.push_back(t % 10);
		t /= 10;  // 进位 
	}
	if(t) c.push_back(t);  // 最高位还有进位 
	return c; 
}

int main() {
	
	string s1, s2;
	vector<int> a, b;
	// 1、读入和存储 
	cin >> s1 >> s2;
	for(int i = s1.size() - 1; i >= 0; i--) {  // s1 逆序存储到 a 
		a.push_back(s1[i] - '0');  // 记得减 '0' 
	}
	for(int i = s2.size() - 1; i >= 0; i--) {  // s2 逆序存储到 b 
		b.push_back(s2[i] - '0');  // 记得减 '0'
	}
	// 2、做加法 
	auto c = add(a, b);
	// 3、逆序输出
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}  

	return 0;
}
