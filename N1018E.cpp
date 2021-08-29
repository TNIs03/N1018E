#include <iostream>
#include <cmath>
using namespace std;

long long x, k;
long long a[15];
bool f[15];
int n = 0;
long long i = 2;
long long x1 = 1, kq = 0;
int c = 0;

void pt(long long x) {
	while (i*i <= x) {
		if (x % i == 0) {
			a[++n] = i;
			while (x % i == 0) x /= i;
		}
		i++;
	}
	if (x != 1) a[++n] = x;
}

void ans(int i) {
	for (int j = 0; j <= 1; j++) {
		f[i] = j;
		if (f[i]) {
			x1 *= a[i];
			c++;
		}
		if (i == n) {
			(!(c & 1)) ? (kq += (k / x1)) : (kq -= (k / x1));
		}
		else ans(i + 1);
		if (f[i]) {
			x1 /= a[i];
			c--;
		}
	}
}

int main() {
	cin >> x >> k;
	pt(x);
	ans(1);
	cout << kq;
	return 0;
}