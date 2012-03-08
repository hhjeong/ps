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
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,ll> node;
const ll inf = 2147483647LL;

void dijkstra( const int &start, const ll &speed, const vector< vector<node> > &G, vector< ll > &max_dist ) {
    const int N = (int)G.size();
    priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll,int> > > pq;
    vector< ll > dist( N, inf );
    dist[start] = 0;
    pq.push( make_pair( 0, start ) );
    
    while( ! pq.empty() ) {
        pair<ll,int> top = pq.top();
        pq.pop();
        ll howfar = top.first;
        int where = top.second;
        if( dist[where] < howfar ) continue;
        // cerr << howfar << " " << where << endl;
        for( int i = 0 ; i < (int)G[where].size() ; ++i ) {
            int next = G[where][i].first;
            int length = G[where][i].second;

            if( howfar + length < dist[next] ) {
                pq.push( make_pair( howfar + length, next ) );
                dist[next] = howfar + length;
            }
        }
    }
    //for( int i = 0 ; i < N ; ++i ) cerr << dist[i] << " "; cerr << endl;
    for( int i = 0 ; i < N ; ++i ) {
        max_dist[i] = max( max_dist[i], dist[i] * speed );
    }
    //for( int i = 0 ; i < N ; ++i ) cerr << max_dist[i] << " "; cerr << endl;
}

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
        vector< ll > V( P );
        
        for( int i = 0 ; i < P ; ++i ) {
            cin >> X[i] >> V[i];
            X[i]--;
        }

        vector< vector<node> > G( N, vector<node>() );

        for( int i = 0 ; i < M ; ++i ) {
            int D, L;
            scanf("%d %d", &D, &L );
            
            vector< int > road( L );
            for( int j = 0 ; j < L ; ++j ) scanf("%d", &road[j] );

            for( int j = 1 ; j < L ; ++j) {
                int here = road[j-1] - 1;
                int there = road[j] - 1;
                G[here].push_back( node( there, D ) );
                G[there].push_back( node( here, D ) );
            }
        }
        
        vector< ll > max_dist( N, 0 );
        for( int i = 0 ; i < P ; ++i ) {
            dijkstra( X[i], V[i], G, max_dist );
        }
		fprintf(stderr,"%d/%d\n", caseno, ncase);
        ll ret = inf;
        for( int i = 0 ; i < N ; ++i ) if( ret > max_dist[i] ) ret = max_dist[i];
        if( ret >= inf ) ret = -1;
        cout << ret << endl;
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
