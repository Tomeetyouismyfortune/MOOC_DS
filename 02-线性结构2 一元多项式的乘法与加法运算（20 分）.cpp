#include<iostream>
#include<map>
using namespace std;

int main() {
	int ka, kb, exp, coef;
	map<int, int> a, b, r;
	cin >> ka;
	for (int i = 0; i<ka; i++) {
		cin >> coef >> exp;
		a[exp] = coef;
	}
	cin >> kb;
	for (int i = 0; i<kb; i++) {
		cin >> coef >> exp;
		b[exp] = coef;
	}
	map<int, int>::iterator pa, pb;
	map<int, int>::reverse_iterator rps, rpm;
	/*****
	加法部分
	*****/
	map<int, int> rs;
	pa = a.begin();
	pb = b.begin();
	while (1) {
		if((pa == a.end()) && (pb == b.end())) break;
		if (pa == a.end()) {
			rs[pb->first] = pb->second;
			pb++;
			continue;
		}
		if (pb == b.end()) {
			rs[pa->first] = pa->second;
			pa++;
			continue;
		}
		if (pa->first > pb->first) {
			rs[pb->first] = pb->second;
			pb++;
			continue;
		}
		if (pa->first < pb->first) {
			rs[pa->first] = pa->second;
			pa++;
			continue;
		}
		if (pa->first == pb->first) {
			rs[pa->first] = pa->second + pb->second;
			pa++;
			pb++;
			continue;
		}
	}
	/*****
	乘法部分
	*****/
	map<int, int> rm;
	for (pa = a.begin(); pa != a.end(); pa++) {
		for (pb = b.begin(); pb != b.end(); pb++) {
			if (rm.count(pa->first + pb->first)) rm[pa->first + pb->first] = rm[pa->first + pb->first] + pa->second * pb->second;
			else {
				rm[pa->first + pb->first] = pa->second * pb->second;
			}
		}
	}
	/*****
	输出部分
	*****/
	int counts = 0, countm = 0, ns = 0, nm = 0;
	for (rps = rs.rbegin(); rps != rs.rend(); rps++) {
		if (rps->second != 0) counts++;
	}
	for (rpm = rm.rbegin(); rpm != rm. rend(); rpm++) {
		if (rpm->second != 0) countm++;
	}
	if (countm == 0) cout << "0 0";
	else {
		for (rpm = rm.rbegin(); rpm != rm.rend(); rpm++) {
			if (rpm->second != 0) {
				if (nm != 0) cout << " ";
				cout << rpm->second << " " << rpm->first;
				nm++;
			}
		}
	}
	cout << endl;
	if (counts == 0) cout << "0 0";
	else {
		for (rps = rs.rbegin(); rps != rs.rend(); rps++) {
			if (rps->second != 0) {
				if (ns != 0) cout << " ";
				cout << rps->second << " " << rps->first;
				ns++;
			}
		}
	}
	return 0;
}
