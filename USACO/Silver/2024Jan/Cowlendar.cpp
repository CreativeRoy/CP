#include <iostream>
#include <set>
#include <cmath>

using namespace std;

long long upper_bound = 4e9;
set<long long> months; 

//should be n = m_1 - m_2, m1-m_3, ..., m_3-m_4
void add_divisors(set<long long> &cand, long long n) {
	//lim is a general limit of the divisors
	long long lim = sqrt(n);
	for (long long i = 1; i <= lim; i++) {
		if (n % i == 0) {
			if (i <= upper_bound) cand.insert(i);
			if (n/i <= upper_bound) cand.insert(n/i);
		}
	}
}

bool test(int n) {
	set<long long> rems;
	for (long long m : months) {
		rems.insert((m%n));
		if (rems.size() > 3) return false;
	}
	return true;
}


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long m;
		cin >> m;
		upper_bound = min(m, upper_bound);
		months.insert(m);
	}
	upper_bound /= 4;
	long long ans = 0;
	if (months.size() <= 3) {
		ans = upper_bound*(upper_bound+1)/2;
		cout << ans << endl;
	} else {
		set<long long> cand;
		cand.insert(2);
		cand.insert(3);
		long long first[4];
		int i = 0;
		for (auto it = months.begin(); i < 4; i++, it++) {
			first[i] = *it;
		} 
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 4; j++) {
				add_divisors(cand, abs(first[i]-first[j]));
			}
		}
		for (const auto &c : cand) {
			if (test(c)) {
				ans += c;
			} 
		}
		cout << ans << endl;
	}	
}


