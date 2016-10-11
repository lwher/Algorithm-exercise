#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
vector<int> digit;
long long int data[40][40];
long long int note[40];
void ini()
{
  data[0][0] = 1;
  note[1] = 1;note[2] = 2;
  for (long long int i(1); i<32; ++i) {
    data[i][0] = data[i][i] = 1;
    long long int end = i/2;
    for (long long int j(1); j<=end; ++j) {
      data[i][j] = data[i][i-j] = data[i][j-1]*(i-j+1)/j; 
    }
    if (i > 2) {
      long long int start = (i-1)/2;
      if ((i-1)%2)start++;
      note[i] = note[i-1]+1;
      for (long long int j(start); j<i-2; ++j) {
        note[i] += data[i-2][j];               
      }
    }  
  }  
}
void change(int &start, int zero, int n) 
{
  for (; start<=n; ++start) {
    if (start + zero >= n-start)return ; 
  }
  start = 40;   
}
long long int get_cnt(long long int x) 
{
  if (x == 0)return 1;
  int cnt = 0;
  while (x) {
    if (x&1) {
      digit.push_back(cnt);  
    }
    x >>= 1;
    ++cnt;  
  }                      
  int end = digit.size() - 1;
  long long int ans = note[digit[end]+1];
  if (digit.size() != 1 && digit[end] + 1 >= digit.size()*2)ans++;
  for (int i(0); i<digit.size()-1; ++i) {                        
    int zeros = ((digit[end] - digit[i]) - (end - i)) - (end - i) + 1; 
    int start = 0;                                               
    change(start,zeros,digit[i]);
    for (int j = max(start,0); j<=digit[i]; ++j) {
      ans += data[digit[i]][j];  
    }
    if (i == digit.size()-2)ans--;            
  }
  digit.clear();
  return ans;
}

int main()
{  
  ini();
  long long int fir,sec;
  while (cin>>fir>>sec) {
      long long int fir_cnt = get_cnt(fir-1);
      long long int sec_cnt = get_cnt(sec);
      cout<<sec_cnt - fir_cnt<<endl;
  }
  return 0;  
}
