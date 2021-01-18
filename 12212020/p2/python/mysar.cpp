#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], del[N];

int query(int l1, int r1, int l2, int r2) {
	printf("Q %d %d %d %d\n", l1, r1, l2, r2);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &a[1], &a[n]);
	for (int i = 1; i < n; i ++) del[i] = query(i, i + 1, i, i + 1);
	for (int i = 2; i < n; i ++) {
		if (a[i]) continue;
		if (!del[i-1]) a[i] = a[i-1];
		else {
			int c = query(i - 1, i, i, i + 1);
			if (!del[i]) {
				if (c > 0) a[i] = a[i-1] - del[i-1];
				else a[i] = a[i-1] + del[i-1];
				a[i+1] = a[i];
			}
			else {
				if (c == 0) a[i] = a[i-1] + del[i-1], a[i+1] = a[i] + del[i];
				else if (c == del[i-1] + del[i]) a[i] = a[i-1] - del[i-1], a[i+1] = a[i] - del[i];
				else if (del[i-1] != del[i]) {
					if (c == del[i]) a[i] = a[i-1] + del[i-1], a[i+1] = a[i] - del[i];
					else a[i] = a[i-1] - del[i-1], a[i+1] = a[i] + del[i];
				}
				else a[i+1] = a[i-1];
			}
		}
	}
	int k = 1;
	while (1) {
		if (a[k] && a[k+1]) break;
		k ++;
	}
	int c = min(a[k], a[k+1]);
	for (int i = 1; i <= n; i ++) {
		if (a[i]) continue;
		int val = query(i, i + 1, k, k + 1) + c;
		if (val == a[i+1]) a[i] = a[i+1] - del[i];
		else a[i] = a[i+1] + del[i];
	}
	printf("!");
	for (int i = 1; i <= n; i ++) printf(" %d", a[i]); puts("");
	fflush(stdout);

    return 0;
}
