#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map< string, int > num_moves;
vector< int > next( 32, -1 );
vector< int > shortcut( 32, -1 );

const int START = 29;
const int GOAL = 30;

int next_pos( int pos, int run ) {
    //cerr << pos << " ";
    for( int i = 0 ; i < run ; ++i ) {
        if( i == 0 && shortcut[pos] != -1 ) {
            pos = shortcut[pos];
        }
        else pos = next[pos];
        //cerr << pos << " ";
    }
    //cerr << "(" << run << ")-> " << pos << endl;
    // cerr << endl;
    
    if( pos == 31 ) pos = 22;
    return pos;
} 

bool check_catch( int turn, int P[] ) {
    int opp = 1 - turn;

    if( P[0] == GOAL || P[1] == GOAL ) return false;
    if( P[turn] == P[opp] ) {
        P[opp] = START;
        return true;
    }
    return false;
}

bool is_same( int f, int s ) {
    if( f == s ) return true;
    if( f == START )
        if( s == START || s == GOAL ) 
            return true;
    return false;
}
bool solve( const vector< int > &actions, int final[] ) {

    int pos[2] = { START, START };

    int turn = 0;

    for( int i = 0 ; i < actions.size() ; ++i ) {
        cerr << i << " " << actions[i] << " ";
        cerr << pos[0] << " " << pos[1] << endl;
        if( pos[0] == GOAL && pos[1] == GOAL ) {
            return false;
        }

        if( pos[turn] == GOAL ) {
            //cerr << "change?" << endl;
            turn = 1 - turn;
            i--;
            continue;
        }

        pos[turn] = next_pos( pos[turn], actions[i] );

        if( actions[i] >= 4 || check_catch( turn, pos ) ) {
            //cerr << "go on!" << endl;
            continue;  
        }
        turn = 1 - turn;
    }

    return is_same(final[0],pos[0]) && is_same(final[1],pos[1]);
}

int main() {
    num_moves["Do"] = 1;
    num_moves["Gae"] = 2;
    num_moves["Gul"] = 3;
    num_moves["Yut"] = 4;
    num_moves["Mo"] = 5;

    for( int i = 1 ; i <= 19 ; ++i ) {
        next[i] = (i+1) % 20;
    }

    for( int i = 20 ; i <= 23 ; ++i ) {
        next[i] = i+1;
    }

    next[24] = 15;
    next[25] = 26;
    next[26] = 31;
    next[31] = 27;
    next[27] = 28;
    next[28] = 0;
    next[0] = 30;
    next[GOAL] = GOAL;

    shortcut[5] = 20;
    shortcut[10] = 25;
    shortcut[22] = 27;

    next[START] = 1;

    int ncase;
    cin >> ncase;

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {

        int U, N, A, B;
        cin >> U >> N >> A >> B;

        vector<int> actions( N );
        for( int i = 0 ; i < N ; ++i ) {
            string foo;
            cin >> foo;
            actions[i] = num_moves[foo];
        }

        cout << "Case #" << caseno << ": ";

        int final[2] = {0};
        if( A > 0 ) cin >> final[0]; else final[0] = START;
        if( B > 0 ) cin >> final[1]; else final[1] = START;
        cout << ( solve( actions, final ) ? "YES" : "NO" ) << endl;
    }

}
