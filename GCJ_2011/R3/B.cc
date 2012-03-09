#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

typedef pair< int, int > ii;

int solve( int p, vector<int> &C, vector<ii> &G ) {
    if( p == C.size() ) {
        // cerr << "here!" << endl;
        int worst = 1000;
        for( int i = 0 ; i < G.size() ; ++i ) {
            if( G[i].first != 0 ) worst = min( worst, G[i].first );
        }
        if( worst == 1000 ) worst = 0;
        return worst;
    }

    int ret = 0;
    for( int i = 0 ; i < G.size() ; ++i ) {
        if( G[i].second+1 == C[p] ) {
            ii tmp = G[i];
            G[i].first++;
            G[i].second = C[p];
            ret = max( ret, solve( p+1, C, G ) );
            G[i] = tmp;
        }
    }

    G.push_back( ii( 1, C[p] ) );
    ret = max( ret, solve( p+1, C, G ) );
    G.pop_back();
    return ret;
}

int main() {
    int ncase;
    scanf("%d", &ncase);

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        int N;
        scanf("%d", &N);
        vector<int> C(N);
        for(int i = 0 ; i < N ; ++i) scanf("%d", &C[i]);
        sort( C.begin(), C.end() );
        
        vector< ii > G( 0 );
        printf("Case #%d: %d\n", caseno, solve(0,C,G) );

    }
    
}
