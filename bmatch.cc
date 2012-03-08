#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct BipartiteMatching {

    int N;
    vector< vector< int > > list;
    vector< int > bmatch;
    vector< bool > seen;

    BipartiteMatching() {
        N = 0;
        list.clear();
    }

    BipartiteMatching( const vector< vector<int> > &_list ) {
        N = (int)_list.size();
        list.clear();
        list = _list; 
    }

    bool dfs(int u) {
        if(seen[u]) return false;
        seen[u] = true;
        for(int i=0;i<list[u].size();++i) {
            int v = list[u][i];
            if(bmatch[v]==-1||dfs(bmatch[v])) {
                bmatch[v] = u; return true;
            }
        }
        return false;
    }

    int matching() {
        int ret = 0;
        bmatch.clear();
        bmatch.resize( N, -1 );
        for(int i=0;i<N;++i) { 
            seen.clear();
            seen.resize( N, false );
            if(dfs(i)) ++ret; 
        }
        return ret;    
    }

};

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    vector< vector< int > > list( N, vector<int>() );
    for(int i = 0 ; i < T ; ++i ) {
        int u, v;
        scanf("%d %d", &u, &v);
        list[u].push_back(v);
    }

    BipartiteMatching bm( list );
    printf("%d\n", bm.matching() );
}

