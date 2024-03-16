#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	string bes = "bessie";
	long long suf = str.size();
	long long wait[7] = {};//0 is null 6 is e
	long long ans = 0;
	for (char c : str) {
		wait[0]++;
		for (int i = 5; i >= 0; i--) {
			if (bes.at(i) == c) {
				wait[i+1] += wait[i];
			   	wait[i] = 0;	
			}
		}
		ans += wait[6]*suf;
		wait[0] += wait[6];
		wait[6] = 0;
		suf--;
	}
	cout << ans << endl;
}
