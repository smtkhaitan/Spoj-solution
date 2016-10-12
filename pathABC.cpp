/*
Template belongs to : SUMIT KHAITAN
*/
 
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
 
typedef long long int LL;
 
#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)
#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define gcd(a,b)  __gcd(a,b)
 
#define  VI vector<int>
#define  VL vector<LL>
#define  VC vector<char>
#define  VS vector<string>
#define  pb push_back
#define  sz size
 
#define MOD       1000000007
#define PI        2*acos(0)

int n,m;
char ax[55][55];

int dp[55][55];

int dfs(int i,int j,char bx)
{
	if(i>=n || j>=m || i<0 || j<0 )return 0;
	else if(ax[i][j]=='Z')return 0;
	else if(dp[i][j]!=-1)return dp[i][j];

	int ans=0;

	if( ((i+1)<n) && ax[i+1][j]==(bx+1))
		ans = max(ans,1+dfs(i+1,j,bx+1));

	if( ((i-1)>=0) && ax[i-1][j]==(bx+1))
		ans = max(ans,1+dfs(i-1,j,bx+1));

	if( ((j+1)<m) && ax[i][j+1]==(bx+1))
		ans = max(ans,1+dfs(i,j+1,bx+1));

	if( ((j-1)>=0) && ax[i][j-1]==(bx+1))
		ans = max(ans,1+dfs(i,j-1,bx+1));

	if( ((i+1)<n) && ((j+1)<m) && ax[i+1][j+1]==(bx+1))
		ans = max(ans,1+dfs(i+1,j+1,bx+1));

	if( ((i-1)>=0) && ((j-1)>=0) && ax[i-1][j-1]==(bx+1))
		ans = max(ans,1+dfs(i-1,j-1,bx+1));

	if( ((i+1)<n) && ((j-1)>=0) && ax[i+1][j-1]==(bx+1))
		ans = max(ans,1+dfs(i+1,j-1,bx+1));

	if( ((i-1)>=0) && ((j+1)<m) && ax[i-1][j+1]==(bx+1))
		ans = max(ans,1+dfs(i-1,j+1,bx+1));

	dp[i][j] = ans;

	return ans;
}


int main()
{
	int cu1=0;
	for(;;)
	{
		memset(dp,-1,sizeof(dp));
		cu1++;
		cin>>n>>m;
		if(n==0 && m==0)break;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin>>ax[i][j];
			}
		}

		int ans=0;

		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(ax[i][j]=='A')
				{
					ans =  max(ans,1+dfs(i,j,'A'));
				}
			}
		}
		cout<<"Case "<<cu1<<": "<<ans<<endl;
	}

	
	return 0;
}