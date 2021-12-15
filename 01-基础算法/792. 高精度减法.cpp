/*************************************
* 题目：792. 高精度减法
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) {  // 若 s1 < s2，返回 true；否则返回 false 
	if(s1.size() != s2.size()) return s1.size() < s2.size();  // 位数不同，比位数 
	else return s1 < s2;  // 位数相同，比大小
}

vector<int> sub(vector<int> a, vector<int> b) {  // c = a - b
	vector<int> c;
	int t = 0;  // 借位
	for(int i = 0; i < a.size(); i++) {
		t = a[i] - t;  // 减去借位 
		if(i < b.size()) t -= b[i];  // 减去 b[i] 
		c.push_back((t + 10) % 10);  // t >= 0，就是本身；t < 0，就是借位之后的值 
		if(t < 0) t = 1;  // 借位 
		else t = 0;  // 没有借位 
	} 
	// 去前导零
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c; 
}

int main() {
	
	string s1, s2;
	vector<int> a, b;
	// 1、读入、比较和存储
	cin >> s1 >> s2;
	if(cmp(s1, s2)) {  // 若 s1 < s2，输出负号并且交换 s1 s2 
		cout << "-";
		swap(s1, s2);
	}
	for(int i = s1.size() - 1; i >= 0; i--) {  // s1 逆序存储到 a
		a.push_back(s1[i] - '0');  // 记得减 '0' 
	}
	for(int i = s2.size() - 1; i >= 0; i--) {  // s2 逆序存储到 b 
		b.push_back(s2[i] - '0');  // 记得减 '0' 
	}
	// 2、做减法
	auto c = sub(a, b);
	// 3、逆序输出 
	for(int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}

	return 0;
}
