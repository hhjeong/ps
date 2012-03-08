#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

#define sqr(x) ((x)*(x))

struct Point {
    double x, y;
    Point( double _x, double _y ) : x(_x), y(_y) {}
    Point() {}
};

struct Line {
    // form of ax + by + c = 0
    double a, b, c;

    Line() {}
    Line( const Point &p1, const Point &p2 ) {
        toLine( p1, p2 ); 
    }

    void toLine(const Point &p1, const Point &p2) {
        if(p1.x==p2.x) { a = 1; b = 0; c = -p1.x; }
        else { 
            b = 1; a = -(double)(p1.y-p2.y)/(double)(p1.x-p2.x);
            c = -(a*p1.x)-(b*p1.y);
        }
    }
    bool same(const Line &rhs) {
        return (a == rhs.a)&&(b == rhs.b)&&(c == rhs.c);
    }
};

int dir(const Point &a, const Point &b, const Point &c) {
    int dx1, dx2, dy1, dy2;
    dx1 = b.x - a.x; dy1 = b.y - a.y;
    dx2 = c.x - a.x; dy2 = c.y - a.y;
    if(dx1*dy2 > dy1*dx2) return  1;
    if(dx1*dy2 < dy1*dx2) return -1;
    if(dx1*dx2 < 0 || dy1*dy2 < 0) return -1;
    if(sqr(dx1)+sqr(dy1) < sqr(dx2)+sqr(dy2)) return 1;
    return 0;
}

int intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    int lhs = dir(a,b,c) * dir(a,b,d);
    int rhs = dir(c,d,a) * dir(c,d,b);
    //	printf("%d %d\n",lhs,rhs);
    return (lhs<=0||rhs<=0);
}

bool intersect_point(const Line &a, const Line &b, double &x, double &y) {
    // ax + by = -c
    double A = a.a, B = a.b;
    double C = b.a, D = b.b;
    double E = -a.c, F = -b.c;
    double det = A*D-B*C;
    if(det==0.0) return false;
    x = (D*E-B*F)/det; y = (-C*E+A*F)/det;
    return true;
}

//  example of usage
int main() {
    int N;
    Point p[4];
    scanf("%d",&N);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i = 0 ; i < N ; ++i ) {
        for(int j = 0 ; j < 4 ; ++j ) 
            scanf("%lf %lf",&p[j].x,&p[j].y);

        Line a(p[0],p[1]), b(p[2],p[3]);
        int ret = intersect(p[0],p[1],p[2],p[3]);

        if(a.same(b)) {
            printf("LINE\n");
            continue;

        }
        if(ret==1) 
        {
            double x, y;
            if(intersect_point(a,b,x,y)) {
                printf("POINT %.2lf %.2lf\n",x,y);
            }
            else printf("LINE\n");
        }
        else {
            printf("NONE\n");
        }
    }
    printf("END OF OUTPUT\n");
}


