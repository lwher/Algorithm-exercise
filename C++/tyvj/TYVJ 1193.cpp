#include<iostream>
#include<cstring>
using namespace std;
#define _D_MIN(a,b) ((a)<(b)?(a):(b))
int _gdp[300][300],_gn;
char _gstr[300];
void _fInit()
{
    cin >> _gstr;
    _gn = strlen(_gstr);
    for( int i = 0;i <= _gn;++i )
        for( int j = 0;j <= _gn;++j )
            _gdp[i][j] = 0;    
    for( int i = 0;i < _gn;++i )
        _gdp[i][i] = 1; 
}
int main()
{
    _fInit();
    for( int l = 1;l < _gn;++l )
        for( int i = 0;i+l < _gn;++i )
        {
            int j = i+l,min = 0x7fffffff;
            if( (_gstr[i] == '(' && _gstr[j] == ')') || (_gstr[i] == '[' && _gstr[j]==']' ))
                min = _D_MIN(min,_gdp[i+1][j-1]);
            for( int k = i;k < j;++k )    min = _D_MIN(min,_gdp[i][k] + _gdp[k+1][j]);
            _gdp[i][j] = min;
        }
    cout << _gdp[0][_gn-1] << endl;
    return 0;
}
