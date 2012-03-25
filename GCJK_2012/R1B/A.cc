#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const ll inf = 987654321987654321LL;
ll N;
ll P[7];
ll R[7][7];

typedef pair< ll, pair<ll,ll> > node;
map< node, ll > cache;

ll solve( ll now, ll P1, ll P2 ) {
    if( now == N ) return 0;
    ll P3 = N - now - P1 - P2;

    //node state = make_pair( now, make_pair( P1, P2 ) );

    //if( cache.count( state ) ) return cache[state];

    //ll &ret = cache[state];
    ll ret = -inf;
    
    ll S[4] = { 0, P1, P2, P3 };

    for( int j = 1 ; j <= 3 ; ++j ) {
        if( S[j] > 0 ) {
            for( int i = 4 ; i <= 6 ; ++i ) {
                if( P[i] > 0 ) {
                    ll mini = min( S[j], P[i] );
                    S[j] -= mini;
                    P[i] -= mini;
                    ret = max( ret, solve( now+mini, S[1], S[2] ) + mini * R[j][i] );
                    S[j] += mini;
                    P[i] += mini;
                }
            }
        }
    }

    return ret;
}
int main() {
    clock_t start_time = clock();
    //freopen("A.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        cin >> N;
        for( int i = 1 ; i <= 6 ; ++i ) cin >> P[i];

        for( int i = 1 ; i <= 3 ; ++i  ) {
            for( int j = 4 ; j <= 6 ; ++j ) {
                cin >> R[i][j];
            }
        }

        cache.clear();
        printf("Case #%d: ", caseno);
        cout << solve( 0, P[1], P[2] ) << endl;
        // cout << solve(0,P[1],P[2]) << endl;
        fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
