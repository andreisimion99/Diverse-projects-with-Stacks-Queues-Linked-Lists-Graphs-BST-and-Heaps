#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
void dfs(vector<int>& deg, vector<vector<int> > & adj, vector<int>& path, int st , int ct,int e)
{
	if(ct==e)
	{
		ans=path;
		return;
	}

	if(deg[st]>0)
	{
		vector<int> x = adj[st];

		for(int i=0;i<x.size();i++)
		{
			deg[st]--;

			path.push_back(st);

			dfs(deg,adj,path,x[i],ct+1,e);

			deg[st]++;
			path.pop_back();
		}
	}

	return ;
}
using namespace std;
int main()
{
	int n,e;
	cout<<"cate noduri are graful : ";
	cin>>n;
	cout<<"cate muchii are graful : ";
	cin>>e;
	int x= e;
	vector<vector<int> > adj(n);
	while(x--)
	{
		int a, b;
		cout<<"muchia: ";
		cin>>a>>b;
		adj[a].push_back(b);
	}

	vector<int> deg(n);
	for(int i=0;i<n;i++)
	{
		deg[i]=adj[i].size();
	}
	vector<int> path;
	int st;
	cout<<"punctul din care plecam este ";
	cin>>st;
	dfs(deg,adj,path,st,0,e);
    cout<<"drumul este : ";
	for(int i=0;i<ans.size();i++)
	{

		cout<<ans[i]<<"->";
	}
	cout<<st<<endl;
	cout<<endl;

}
