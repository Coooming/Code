#include <bits/stdc++.h>
using namespace std;
const int maxn=70;
int n,m,sum,len,a[maxn],Next[maxn];
bool getans,boo[maxn];
bool cmp(int A,int B) { return A>B; }
void finds(int k,int last,int left)
{
	if (!left)
	{
		if (k==m)
		{
			getans=true;
			return;
		}
		for (last=2;last<=n;last++) if (!boo[last]) break;
		boo[last]=true;
		finds(k+1,last,len-a[last]);
		boo[last]=false;
		return;
	}
	int L=last,R=n+1,mid;
	while (L+1<R)
	{
		mid=L+R>>1;
		if (a[mid]<=left) R=mid; else L=mid;
	}
	for (int i=R;i<=n;i++)
		if (!boo[i])
		{
			boo[i]=true;
			finds(k,i,left-a[i]);
			boo[i]=false;
			if (getans || left==len || left==a[i]) return;
			i=Next[i];
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if (x<=50) a[++m]=x,sum+=x;
	}
	n=m;
	sort(a+1,a+1+n,cmp);
	for (int i=n;i>=1;i--) Next[i]=(a[i]==a[i+1])?Next[i+1]:i;
	for (int i=a[1];i<=(sum>>1);i++)
		if (!(sum%i))
		{
			m=sum/i;
			len=i;
			boo[1]=true;
			finds(1,1,i-a[1]);
			boo[1]=false;
			if (getans)
			{
				printf("%d\n",i);
				return 0;
			}
		}
	printf("%d\n",sum);
	return 0;
}
