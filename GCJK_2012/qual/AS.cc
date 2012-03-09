#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

int main() {
    clock_t start_time = clock();
    freopen("A.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
        ll N, D, W;
        cin >> N >> D >> W;
        ll ret = 0;
        ll nmod = 0;
        for( int i = 0 ; i < N ; ++i ) {
            ll nlines = ( nmod + D ) / W + ( ( nmod + D ) % W > 0 );
            nmod = ( nmod + D ) % W; 
            ret += nlines;
        }
        cout << ret << endl;
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
