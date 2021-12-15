/*************************************
* 题目：792. 高精度减法2
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];  // 自动初始化为 0 

bool cmp(string s1, string s2) {  // 若 s1 < s2，返回 true；否则返回 false 
	if(s1.size() != s2.size()) return s1.size() < s2.size();  // 位数不同，比位数 
	else return s1 < s2;  // 位数相同，比大小
}

int main() {

	// 1、读入、比较和存储 
	string s1, s2;
	cin >> s1 >> s2;
	if(cmp(s1, s2)) {  // s1 代表的数 < s2 代表的数，返回 true 
		cout << "-";
		swap(s1, s2);  // 字符串交换 
	}
	int len1 = s1.size(), len2 = s2.size();
	// s1 逆序存到 a
	for(int i = 0; i < len1; i++) {
		a[i] = s1[len1-i-1] - 48;  // - '0'
	}
	// s2 逆序存到 b 
	for(int i = 0; i < len2; i++) {
		b[i] = s2[len2-i-1] - '0';
	}
	// 2、做减法  a-b
	int len = max(len1, len2);
	for(int i = 0; i < len; i++) { 
		if(a[i] < b[i]) {  // 如果不够减，借位 
			a[i] += 10;
			a[i+1]--;
		}
		c[i] = a[i] - b[i];  // 减法 
	}
	// 3、去掉前导零，0~len-1
	while(len > 1 && c[len-1] == 0) len--;
	// 4、逆序输出 
	for(int i = len-1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
