#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std ;
#define ll long long 
#define maxn 3
ll n,mod;
struct mat 
{
    ll n,m , a[ maxn ][ maxn ] ;
    mat() 
    {
        memset( a , 0 , sizeof( a ) ) ;
    }
} e , f , I ;
mat operator * ( const mat &x , const mat &y ) {
    mat ret ;
    ret.n = x.n , ret.m = y.m ;
    for ( int i = 0 ; i < ret.n ; ++ i ) {
        for ( int j = 0 ; j < ret.m ; ++ j ) {
            for ( int k = 0 ; k < x.m ; ++ k ) {
                ( ret.a[ i ][ j ] += x.a[ i ][ k ] * y.a[ k ][ j ] ) %= mod ;
            }
        }
    }
    return ret ;
}
mat pow( mat x , ll cnt ) {
    mat ret = I , rec = x ;
    for ( ; cnt ; cnt >>= 1 ) {
        if ( cnt & 1 ) ret = ret * rec ;
        rec = rec * rec ;
    }
    return ret ;
}
ll Exp[ 19 ] ;
int search( ll x ) {
    if ( x < 10 ) return 1 ;
    if ( x == Exp[ 18 ] ) return 19 ;
    int l = 1 , r = 18 ;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1 ;
        if ( Exp[ mid ] <= x ) l = mid ; else r = mid ;
    }
    return r ;
}
int main(  ) {
    cin >> n >> mod ;
    Exp[ 0 ] = 1 ; for ( int i = 0 ; i ++ < 18 ; ) Exp[ i ] = Exp[ i - 1 ] * 10 ;
    f.n = 3 , f.m = 1 ;
    f.a[ 0 ][ 0 ] = f.a[ 1 ][ 0 ] = 0 , f.a[ 2 ][ 0 ] = 1 ;
    e.n = e.m = 3 ;
    e.a[ 0 ][ 1 ] = e.a[ 0 ][ 2 ] = e.a[ 1 ][ 1 ] = e.a[ 1 ][ 2 ] = e.a[ 2 ][ 2 ] = 1 ;
    I.n = I.m = 3 ;
    I.a[ 0 ][ 0 ] = I.a[ 1 ][ 1 ] = I.a[ 2 ][ 2 ] = 1 ;
    ll i = 1 ;
    while ( i <= n ) {
        int k = search( i ) ;
        ll pos = Exp[ k ] - 1 <= n ? Exp[ k ] - 1 : n ;
        e.a[ 0 ][ 0 ] = Exp[ k ] % mod ;
        f = pow( e , pos - i + 1 ) * f ;
        i = pos + 1 ;
    }
    cout << f.a[ 0 ][ 0 ] << endl ;
    return 0 ;
}