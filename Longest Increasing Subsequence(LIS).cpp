#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int inf = 1048576;
// input
int a[inf];
// the longest one.
int lst[inf];
// output
int len;

int main() {
	int n;
	int i;
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; ++i) {
		scanf_s("%d", &a[i]);
	}

	lst[0] = a[0];
	len = 1;

	for (i = 1; i < n; ++i) {
		if (a[i] >= lst[len - 1]) {
			lst[len] = a[i];
			len++;
		}
		else {
			int *lsti = upper_bound(lst, lst + len, a[i]);
			*lsti = a[i];
		}
	}

	printf("%d", len);

	return 0;
}