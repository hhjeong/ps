#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

int N;
vector< ii > F;
int cache[1001][101001];
bool cmp( const ii &a, const ii &b ) {
    int sa = a.first + a.second;
    int sb = b.first + b.second;
    if( sa != sb ) return sa < sb;
    return a < b;
}

int solve( int day, int pos ) {
    if( pos == N ) return day;
    int &ret = cache[ pos ][ day ];
    if( ret != -1 ) return ret;
    ret = max( day, solve( day, pos+1 ) );
    if( day <= F[pos].first ) {
        ret = max( ret, solve( day+F[pos].second, pos+1 ) );
    }
    return ret;
}
int main() {
    clock_t start_time = clock();
    // freopen("A.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
        cin >> N;
        F.clear();
        F.resize( N );
        for( int i = 0 ; i < N ; ++i ) cin >> F[i].first >> F[i].second;

        sort( F.begin(), F.end(), cmp );
        memset( cache, -1, sizeof cache );
        cout << solve( 0, 0 ) << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
