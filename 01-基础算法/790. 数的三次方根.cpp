/*************************************
* 题目：790. 数的三次方根
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	double n;
	scanf("%lf", &n);
	double l = -100, r = 100, ans;
	while(r - l >= 1e-8) {
		double mid = (l + r) / 2;
		if(mid * mid * mid >= n) {  // 可能是这个 mid，也有可能在左边 
			ans = mid;
			r = mid;
		}else {  // mid * mid * mid < n，mid 小了，往右找 
			l = mid;
		}
	}
	printf("%.6f", ans);

	return 0;
}
