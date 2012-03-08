#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cassert>
#include <cmath>
using namespace std;

typedef pair< double, double > point;
typedef deque< point > boundary;
#define X first
#define Y second

double getY( double linepos, point A, point B ) {

    double dx = B.X - A.X;
    double dy = B.Y - A.Y;
    double disp = linepos - A.X;

    return A.Y + disp * dy / dx;
    
}

double get_area( deque< point > P ) {
    double ret = 0.0;
    const int N = (int)P.size();

    for( int i = 0 ; i < N ; ++i ) {
        ret += P[i].X * P[(i+1)%N].Y;
        ret -= P[i].Y * P[(i+1)%N].X;
    }
    return fabs( ret ) * 0.5;
}

double get_total_area( const boundary &L, const boundary &U ) {
    boundary P;
    for( int i = 0 ; i < (int)L.size() ; ++i) P.push_back( L[i] );
    for( int i = (int)U.size()-1 ; i >= 0 ;--i ) P.push_back( U[i] );
    return get_area( P );
}

boundary cut( double xpos, const boundary &P ) {
    boundary ret;
   
    int where = 0; 
    for( int i = 0 ; i < (int)P.size() - 1 ; ++i ) {
        if( P[i].X <= xpos && xpos <= P[i+1].X ) {
            where = i;
            break;
        }
    }

    point new_point = point( xpos, getY( xpos, P[where], P[where+1] ) );


    for( int i = 0 ; i < P.size() ; ++i ) {
        if( P[i].X < xpos ) 
            ret.push_back( P[i] );
    }
    ret.push_back( new_point );
    return ret;
}

double find_feasible_pos( boundary &L, boundary &U, double target_area )  {
    double lo = L.front().X;
    double hi = L.back().X;
    double candX; 

    boundary nextL, nextU;
    int niter = 100;
    while( niter-- ) {
        candX = (lo+hi) / 2.0;
        
        nextL = cut( candX, L );
        nextU = cut( candX, U );

        double cand_area = get_total_area( nextL, nextU );

        // fprintf( stderr,"[debug : cand_area(%g) %f %f]\n", cand_area, lo, hi );
        // fprintf( stderr,"[debug : %f,%f %f,%f\n", nextL.front().X, nextL.front().Y, nextU.front().X, nextU.front().Y );
        if( target_area > cand_area ) lo = candX;
        else if ( target_area < cand_area ) hi = candX;
    }

    while( !L.empty() && L.front().X < candX ) L.pop_front();
    L.push_front( nextL.back() );

    while( !U.empty() && U.front().X < candX ) U.pop_front();
    U.push_front( nextU.back() );
    return candX;
}

deque< double > solve( int W, boundary &L , boundary &U, int G ) {

    deque< double > ret;
    double area = get_total_area( L, U );
    
    for( int i = 0 ; i < G-1 ; ++i ) {
        double feasible_pos = find_feasible_pos( L, U, area / G  );
        ret.push_back( feasible_pos );

    }
    return ret;
}

int main() {
    int ncase;
    scanf("%d", &ncase);

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        int width, nlower, nupper, ngroup;
        scanf("%d %d %d %d", &width, &nlower, &nupper, &ngroup);
        
        boundary L( nlower ), U( nupper );
        for( int i = 0 ; i < nlower ; ++i )
            scanf("%lf %lf", &L[i].X, &L[i].Y );

        for( int i = 0 ; i < nupper ; ++i )
            scanf("%lf %lf", &U[i].X, &U[i].Y );

        deque< double > ret = solve( width, L, U, ngroup );
        printf("Case #%d:\n", caseno); 
        for( int i = 0 ; i < (int)ret.size() ; ++i ) {
            printf("%.7f\n", ret[i] );
        }
    }
}
