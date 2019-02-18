#include <cstdio>

using namespace std;

int n;
long long ar[500008];
long long t[500008];
int ans;

// 在arg[beg], arg[end]间按升序归并排序，闭合区间。
void msrt(long long arg[], long long re[], int beg, int end) {
	if (beg == end) return;
	int i;
	int mid = (beg + end) / 2;
	msrt(arg, re, beg, mid);
	msrt(arg, re, mid + 1, end);

	long long *a = arg + beg, *b = arg + mid + 1, *ae = b, *be = arg + end + 1, *r = re + beg;
	while (a != ae | b != be) {
		if (a == ae) {
			*(r++) = *(b++);
		}
		else if (b == be) {
			*(r++) = *(a++);
		}
		else {
			if (*a < *b) {
				*(r++) = *(a++);
			}
			else {
				*(r++) = *(b++);
			}
		}
	}
	for (i = beg; i <= end; ++i) {
		arg[i] = re[i];
	}
}

int main() {
	int i;
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf_s("%lld", &ar[i]);
	}

	msrt(ar, t, 0, n - 1);

	return 0;
}