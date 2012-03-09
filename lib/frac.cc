struct frac {
    ll x, y; // x / y

    void set(ll a = 0, ll b = 1) {
        x = a; y = b;
        ll g = __gcd(x,y); if(g<0) g = -g; // __gcd(x,y)���� x�� ������ ���� ��� ������ ��ȯ�ϴ� ��� �߻�!(����)
        x /= g; y /= g;
    }
   
    frac(ll a, ll b) {
        set(a,b);
    }
    frac operator + (const frac &f) const {
        ll a = x; ll b = y; ll c = f.x; ll d = f.y;
        ll up = a * d + b * c;
        ll dn = b * d;
        return frac(up,dn);
    }
    frac operator - (const frac &f) const {
        return frac(x,y) + frac(-f.x,f.y);
    }
    frac operator * (const frac &f) const {
        ll a = x; ll b = y; ll c = f.x; ll d = f.y;
        return frac(a*b,c*d);
    }
    frac operator / (const frac &f) const {
        ll a = x; ll b = y; ll c = f.x; ll d = f.y;
        return frac(a*d,b*c);   
    }
    bool operator == (const frac &f) const {
        ll a = x; ll b = y; ll c = f.x; ll d = f.y;
        frac ff = frac(a,b)-frac(c,d);
        return ff.x == 0;
    }
    bool operator < (const frac &f) const {
        ll a = x; ll b = y; ll c = f.x; ll d = f.y;
        frac ff = frac(a,b)-frac(c,d);
        return ff.x < 0;
    }

}

