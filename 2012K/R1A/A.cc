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


int solve( int day, const vector<ii> &F, vector<bool> &used ) {
    const int N = (int)F.size(); 

    int ret = day;
    for( int i = 0 ; i < N ; ++i ) if( !used[i] ) {
        if( day > F[i].first ) continue;
        used[i] = true;
        ret = max( ret, solve( day + F[i].second, F, used ) );
        used[i] = false;
    }
    return ret;
}

int main() {
    clock_t start_time = clock();

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
        int N;
        cin >> N;
        vector< ii > F( N );
        for( int i = 0 ; i < N ; ++i ) {
            cin >> F[i].first >> F[i].second;
        }
        sort( F.begin(), F.end() );

        vector< bool > used( N, false );

        cout << solve( 0, F, used ) << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
