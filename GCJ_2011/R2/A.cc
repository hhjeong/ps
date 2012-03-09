#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

double solve( vector< ii > &SEG, int S, int R, double T ) {
    double ret = 0.0;
    const int N = SEG.size();
    for( int i = 0 ; i < N ; ++i ) {
        double normal_time = double( SEG[i].first ) / double( S + SEG[i].second );
        double possible_run_len = T * ( R + SEG[i].second );
        double must_walk_len =  SEG[i].first - possible_run_len;

        double run_time, tot_time;

        if( must_walk_len > 0.0 ) {
            tot_time = T + must_walk_len / double( S + SEG[i].second );
            run_time = T; 
        }
        else {
            tot_time = SEG[i].first / double( R + SEG[i].second );
            run_time = tot_time;
        }

        T -= run_time;
        ret += tot_time;
    }

    return ret;
}

bool cmp( const ii &a, const ii &b ) {
    if( a.second != b.second ) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    clock_t start_time = clock();
    //freopen("A.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);

        int X, S, R, T, N;
        cin >> X >> S >> R >> T >> N;

        vector< ii > segments;
        int last = 0;
        for( int i = 0 ; i < N ; ++i ) {
            int begin, end, added;
            cin >> begin >> end >> added;
            if( last < begin ) {
                segments.push_back( ii( begin-last, 0 ) );
            }
            segments.push_back( ii( end-begin, added ) );
            last = end;
        }

        if( last < X ) {
            segments.push_back( ii( X-last, 0 ) );
        }

        sort( segments.begin(), segments.end(), cmp );
        printf("%.10f\n", solve( segments, S, R, T ) );
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
