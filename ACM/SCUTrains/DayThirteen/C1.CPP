#include <stdio.h>
#include <string.h>
const int N=128;
char a[N],b[N],c[N];
int n,m,k,f[N],v[N][N][N],r[N][N][N],u,w;
void cmp(int x,int z,int a,int b,int c){if(x>v[a][b][c])v[a][b][c]=x,r[a][b][c]=z;}
main(){
  scanf("%s%s%s",a,b,c);
  n=strlen(a),m=strlen(b),k=strlen(c);
  f[0]=-1;
  for(int i=1;i<=k;++i){
    int& x=f[i];
    x=f[i-1]+1;
    while(x>0&&c[i-1]!=c[x-1])x=f[x-1]+1;
  }
  memset(v,0xff,sizeof(v)),v[0][0][0]=0;
  for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)for(int l=0;l<k;++l){
    int x=v[i][j][l],z=(((i<<8)+j)<<8)+l;
    if(x>=0){
      cmp(x,z,i+1,j,l),cmp(x,z,i,j+1,l);
      if(a[i]==b[j]){
        int y=l+1;
        while(y>0&&a[i]!=c[y-1])y=f[y-1]+1;
        cmp(x+1,z,i+1,j+1,y);
      }
    }
  }
  for(int i=0;i<k;++i)if(v[n][m][i]>u)u=v[n][m][i],w=i;
  c[u]=0;
  for(int i=n,j=m,l=w,t=u;i||j||l;){
    int x=r[i][j][l],y=(x>>8)&0xff,z=x&0xff;x>>=16;
    if(x!=i&&y!=j)c[--t]=a[x];
    i=x,j=y,l=z;
  }
  puts(u?c:"0");
}