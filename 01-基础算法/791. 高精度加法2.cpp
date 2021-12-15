#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];

int main() {

	// 1、输入和存储 
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	for(int i = 0; i < len1; i++) {  // s1 逆序存储到 a 中 
		a[i] = s1[len1-1-i] - '0';  // 记得减去 '0'
	}
	for(int i = 0; i < len2; i++) {  // s2 逆序存储到 b 中 
		b[i] = s2[len2-1-i] - '0';  // 记得减去 '0'
	}
	// 2、做加法（边加边进位） 
	int len = max(s1.size(), s2.size());
	for(int i = 0; i < len; i++) {
		c[i] += a[i] + b[i];  // 当前位相加，再加上刚刚的进位
		if(c[i] >= 10) {  // 需要向前进位 
			c[i+1] = c[i] / 10;  
			c[i] %= 10;
		}
	}
	// 3、检查最高位的进位情况 
	if(c[len] > 0) {  // 最高位有进位
		len++;
	}
	// 4、逆序输出 
	for(int i = len-1; i >= 0; i--) {  // 逆序输出
		cout << c[i];
	}

	return 0;
}
