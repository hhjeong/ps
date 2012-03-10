#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

int N, M, K;
char board[50][50][50];
int ngroup = 0;
int group[50][50][50];

void dfs( int f, int i, int j ) {
    if( group[f][i][j] != -1 ) return;
    if( board[f][i][j] != '.' ) return;
    //fprintf( stderr, "DFS : %d %d %d %d\n", f, i, j, ngroup);
    group[f][i][j] = ngroup;
    if( i >= 1 ) dfs( f, i-1, j );
    if( i < N-1 ) dfs( f, i+1, j );
    if( j >= 1 ) dfs( f, i, j-1 );
    if( j < M-1 ) dfs( f, i, j+1 );
}

vector< vector<int> > G;
//int cache[10000][2];
//
int color[10000];

int best = 0;
void solve( int where, int cur ) {
    if( where >= ngroup ) {
        best = max(cur,best);
        return;
    }
    int remain = ngroup - where;

    if( cur + remain < best ) return;

    if( G[where].size() == 0 ) {
        color[where] = 1;
        solve( where+1, cur+1 );
        color[where] = 0;
        return;
    } 
    color[where] = 1;
    bool ok = true;
   
    for( int i = 0 ; i < G[where].size() ; ++i ) {
        int to = G[where][i];
        if( color[to] ) {
            ok = false;
            break;
        }
    }
    if( ok ) {
        solve( where+1, cur+1 );
        if( cur + remain < best ) return;
    }
    color[where] = 0;

    solve( where+1, cur );
}

int main() {
    clock_t start_time = clock();
    //freopen("C.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        cin >> N >> M >> K;
        for(int k = 0 ; k < K ; ++k ) {
            for( int i = 0 ; i < N ; ++i ) {
                    cin >> board[k][i];
            }
        }

        ngroup = 0;
        memset( group, -1, sizeof group );
        for( int f = 0 ; f < K ; ++f ) for( int i = 0 ; i < N ; ++i ) for( int j = 0 ; j < M ; ++j ) if( board[f][i][j] == '.' && group[f][i][j] == -1 ) {
            dfs( f, i ,j );
            ngroup++;
            //fprintf( stderr, "%d %d %d\n", f, i, j );
        }

        set< ii > edges;
        G.clear();
        G.resize( ngroup, vector<int>(0,0) );
        for( int f = 0 ; f < K-1 ; ++f ) {
            for( int i = 0 ; i < N ; ++i ) for( int j = 0 ; j < M ; ++j ) if( board[f][i][j] == '.' && board[f+1][i][j] == '.' ) {
                int here = group[f][i][j];
                int there = group[f+1][i][j];
                assert( here != -1 );
                assert( there != -1 );
                assert( here != there );
                // cerr << here << " " << there << endl;
                if( edges.find( ii(here,there) ) != edges.end() ) continue;
                edges.insert(ii(here,there));
                edges.insert(ii(there,here));
                G[here].push_back( there );
                G[there].push_back( here );
            }
        }


        memset( color, 0 ,sizeof color );
        best = 0;
        solve( 0, 0 );
        printf("Case #%d: ", caseno);
        //cerr << ngroup << " ";
        cout << best << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
