/*************************************
* ��Ŀ��790. �������η���
* ���ߣ�Wei Changying
* ���䣺weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	double n;
	scanf("%lf", &n);
	double l = -100, r = 100, ans;
	while(r - l >= 1e-8) {
		double mid = (l + r) / 2;
		if(mid * mid * mid >= n) {  // ��������� mid��Ҳ�п�������� 
			ans = mid;
			r = mid;
		}else {  // mid * mid * mid < n��mid С�ˣ������� 
			l = mid;
		}
	}
	printf("%.6f", ans);

	return 0;
}
