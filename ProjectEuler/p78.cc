// 1, 2, 3, 5, 7, 11, 15, 22, 30, 42
// Partition numbers!
// it's a very slow version
// see p78.py for better 'fast' function
#include <cstdio>
#include <cstring>

const int N = 100;
typedef long long ll;
ll cache[N][N];

ll solve( int n, int m ) {
	if( n == 0 ) return 1;

	ll &ret = cache[n][m];
	if( ret != -1 ) return ret;
	ret = 0;
	for( int i = m ; i >= 0 ; --i ) {
		int remain = n-i;
		if( remain < 0 ) continue;
		ret += solve( remain, i );	
	}

}

int main() {
	memset( cache, -1, sizeof cache );
	for( int i = 1 ; i <= 10 ; ++i ) {
		ll ret = solve( i, i );
		printf("%d %d\n", i, ret-1 );
	}
}

