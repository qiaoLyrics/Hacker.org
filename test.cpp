#include <stdio.h>
int main()
{
	long long tot = 0, a[3] = { 0, 0, 1 } , day = 1, Limit = 47LL;
	while(tot < Limit) {
		int born = a[2] + a[1] , dead = a[0];
		tot += born;
		a[0] = a[1], a[1] = a[2], a[2] = born;
		day++;
		if(tot >= Limit) break;
		tot -= dead;
	}
	printf("%lld  %lld\n", day, tot);

	return 0;
}
