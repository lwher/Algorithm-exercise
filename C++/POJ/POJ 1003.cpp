#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	const int size=301;
	double length[size]={0.0};
	double len;
	while(cin>>len && len)
	{
		int i;
		for(i=1;i<size;i++)
		{
			if(!length[i])
				length[i]=length[i-1]+1.0/(i+1.0);

			if(length[i]>=len)
				break;
		}
		cout<<i<<" card(s)"<<endl;
	}
	system("pause");
	return 0;
}
