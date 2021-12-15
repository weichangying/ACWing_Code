/*************************************
* 题目：
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

/*************************************
* 题目：793. 高精度乘法
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> a, int b, int& r) {  // a / b，商 c，余 r 
	vector<int> c;
	for(int i = a.size() - 1; i >= 0; i--) {  // 从高位开始除 
		r = r * 10 + a[i];
		c.push_back(r / b);  // 商 
		r %= b;  // 余数 
	} 
	reverse(c.begin(), c.end());  // 翻转 
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
	// 2、做除法
	int r  = 0;  // 余数 
	auto c = div(a, b, r);  // 商 
	// 3、逆序输出 
	for(int i = c.size() - 1; i >= 0; i--) {  // 输出商 
		cout << c[i];
	}
	cout << endl << r << endl;  // 输出余数 
	
	return 0;
}
