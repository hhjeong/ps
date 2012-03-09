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
    vector< bool > used( N, false );
    for( int phase = 0 ; phase < N ; ++phase ) {
        int best = -1;
        double best_gap;
        double best_run_time;
        double best_tot_time;
        for( int i = 0 ; i < N ; ++i ) if( !used[i] ) {
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

            if( best == -1 || normal_time / tot_time > best_gap ) {
                best = i;
                best_gap = normal_time / tot_time;
                best_run_time = run_time;
                best_tot_time = tot_time;
            }
        }

        assert( best != -1 );
        T -= best_run_time;
        ret += best_tot_time;
        used[best] = true;

        fprintf( stderr, "DEBUG : [%d] %d %d %.5f (%.5f)\n", best, SEG[best].first, SEG[best].second, best_gap, T );
    }

    return ret;
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
        printf("%.10f\n", solve( segments, S, R, T ) );
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
