#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve( char *bit ) {
    int len = strlen( bit );

    reverse( bit, bit+len );

    ll lower = 0;
    for( ll i = 0 ; i < len ; ++i ) if( bit[i] == '1' ) lower |= (1LL<<i);

    ll ret = 0;

    for( ret = (ll)sqrt( lower ) ; ; ++ret ) {
        ll sq = ret * ret;

        if( (lower & sq) >= lower ) {
            ret = sq;
            break;
        }
    }

    fprintf( stderr,"found : %I64d\n", ret);
    for( ll i = 0 ; i < len ; ++i ) if( bit[i] == '?' ) {
        bit[i] = '0' + ( ret >> i ) % 2;
    }
    reverse( bit, bit+len );
}

int main() {
    int ncase;
    scanf("%d", &ncase);
    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        char inp[100];
        scanf("%s", inp);
        fprintf( stderr, "DEBUG : %s\n", inp);
        solve( inp );
        fprintf( stderr, "DEBUG : %s\n\n", inp);
        printf("Case #%d: %s\n", caseno, inp);
    }
}
