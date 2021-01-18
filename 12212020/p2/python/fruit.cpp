#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sz=1;
		int start=2;
		while(start<n)
		{
			start=2*start+2;
			sz++;
		}
		int hash[sz];
		int cap[sz];
		cout<<sz<<"\n";
		start=2;
		for(int i=1;i<sz;i++)
		{
			cout<<start<<" ";
			cap[i-1]=start;
			start=2*start+2;
		}
		cap[sz]=n;
		cout<<n<<"\n";
		memset(hash,0,sizeof(hash));
		int i=0;
		for(int j=1;j<=n;j++)
		{
			vector<pair<int,int> >v;
			hash[i]++;
			v.push_back({i+1,hash[i]});
			int put=1;
			while(put<4 and i+1<sz and hash[i+1]<j)
			{
				hash[i+1]++;
				v.push_back({i+2,hash[i+1]});
				put++;
			}
			while(put<4 and i+2<sz and hash[i+2]<j)
			{
				hash[i+2]++;
				v.push_back({i+3,hash[i+2]});
				put++;
			}
			while(put<4 and i+3<sz and hash[i+3]<j)
			{
				hash[i+3]++;
				v.push_back({i+4,hash[i+3]});
				put++;
			}
			cout<<put<<"\n";
			for(int k=0;k<v.size();k++)cout<<v[k].second<<" "<<v[k].first<<"\n";
			if(hash[i]==cap[i])i++;
		}
	}
}