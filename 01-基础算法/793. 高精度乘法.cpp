/*************************************
* 题目：793. 高精度乘法
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> a, int b) {  // c = a * b
	vector<int> c;
	int t = 0;  // 进位
	for(int i = 0; i < a.size() || t; i++) {  // 把 b 当作一个整体来乘 
		if(i < a.size()) t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;  // 进位 
	} 
	// 去前导零
	while(c.size() > 1 && c.back() == 0) c.pop_back(); 
	return c; 
}

int main() {
	
	// 1、读入和存储
	string s;
	int b;
	vector<int> a;
	cin >> s >> b;
	for(int i = s.size() - 1; i >= 0; i--) {  // s 逆序存储到 a  
		a.push_back(s[i] - '0');  // 记得减 '0' 
	}
	// 2、做乘法
	auto c = mul(a, b);
	// 3、逆序输出 
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
