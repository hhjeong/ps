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
const int inf = 987654321;
int main() {
    clock_t start_time = clock();
    freopen("C.in","r",stdin);
//	freopen("C-small-0.in","r",stdin);
//	freopen("C-small-0.out","w",stdout);
//	freopen("C-large-0.in","r",stdin);
//	freopen("C-large-0.out","w",stdout);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);

        int N, P, M;
        
        scanf("%d %d %d", &N, &P, &M);
       
        vector< int > X( P );
        vector< int > V( P );
        
        for( int i = 0 ; i < P ; ++i ) {
            cin >> X[i] >> V[i];
            X[i]--;
        }

        vector< vector<int> > G( N, vector<int>( N, inf ) );
        for( int i = 0 ; i < N ; ++i ) G[i][i] = 0;

        for( int i = 0 ; i < M ; ++i ) {
            int D, L;
            scanf("%d %d", &D, &L );
            
            vector< int > road( L );
            for( int j = 0 ; j < L ; ++j ) scanf("%d", &road[j] );

            for( int j = 1 ; j < L ; ++j) {
                int here = road[j-1] - 1;
                int there = road[j] - 1;
                G[here][there] = G[there][here] = D;
            }
        }

        for( int k = 0 ; k < N ; ++k ) {
            for( int i = 0 ; i < N ; ++i ) {
                for( int j = 0 ; j < N ; ++j ) {
                    G[i][j] = min( G[i][j], G[i][k] + G[k][j] );
                }
            }
        }

        int ret = -1;
        for( int dest = 0 ; dest < N ; ++dest ) {
            int maxi = -inf;
            bool possible = true;
            for( int i = 0 ; i < P ; ++i ) {
                if( G[X[i]][dest] >= inf ) {
                    possible = false;
                    break;
                }
                maxi = max( maxi, G[X[i]][dest] * V[i] );
            }
            if( possible ) {
                if( ret == -1 || ret > maxi ) ret = maxi;
            }
        }
		//fprintf(stderr,"%d/%d\n", caseno, ncase);
        printf("%d\n",ret );
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
