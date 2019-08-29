/*
带修改的主席树
Q x y k 查询区间[x,y]中第k小
C x y 修改a[x]为y 
*/


#include<bits/stdc++.h>
#define low(x) (x & (-x))
using namespace std;
const int N = 6e4+1000;
const int M = N*32;
int ls[M],rs[M],sum[M],sz,rt[N],root[N];
int v[N],w[N],L[N],R[N],A[N],B[N],K[N],a,b;
bool vis[N];
int n,m,top;

void update(int pre, int &now,int l, int r, int k, int c){
    now = ++sz;
    sum[now] = sum[pre] + c; ls[now] = ls[pre]; rs[now] = rs[pre]; 
    if (l + 1 == r) return;
    int mid = (l + r) >> 1;
    if (k < mid) update(ls[pre],ls[now],l,mid,k,c); 
    if (k >= mid) update(rs[pre],rs[now],mid,r,k,c);

}

int query(int now1, int now2, int l, int r, int k){
    if (l+1 == r) return l;
    int sum1 = 0,sum2 = 0,temp;
    for (int i = 0; i < a; ++i) sum1+=sum[ls[L[i]]];
    for (int i = 0; i < b; ++i) sum2+=sum[ls[R[i]]];

    temp = sum2 - sum1 + sum[ls[now2]] - sum[ls[now1]];
    int mid = (l+r)>>1;
    if (temp >= k){
        for (int i = 0; i < a; ++i) L[i] = ls[L[i]];
        for (int i = 0; i < b; ++i) R[i] = ls[R[i]];
        return query(ls[now1],ls[now2], l,mid,k);
    } else{
        for (int i = 0; i < a; ++i) L[i] = rs[L[i]];
        for (int i = 0; i < b; ++i) R[i] = rs[R[i]];
        return query(rs[now1],rs[now2],mid,r,k-temp);
    }
}

void init(){
    top = sz = 0;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i){
        scanf("%d",&v[i]);
        w[++top] = v[i];
    }
    char s[3];
    for (int i = 0; i < m; ++i){
        scanf("%s",s);
        scanf("%d%d",&A[i],&B[i]);
        if (s[0]=='Q'){
            scanf("%d",&K[i]);
            vis[i] = 1;
        } else w[++top] = B[i];
    }
    sort(w+1,w+top+1);
    top = unique(w+1,w+1+top)-w-1;//离散化
    for (int i = 1; i <= n; ++i){
        int t = lower_bound(w+1,w+top+1,v[i]) - w;
        update(rt[i-1],rt[i],1,top+1,t,1);
    }

}

void solve(){
    for (int i = 0; i < m; ++i)
    if (vis[i]){
        vis[i] = 0;
        a = b = 0;
        for (int j = A[i]-1; j; j -= low(j))
            L[a++] = root[j];
        for (int j = B[i]; j; j -= low(j))
            R[b++] = root[j];
        int t = query(rt[A[i]-1],rt[B[i]],1,top+1,K[i]);
        printf("%d\n",w[t]);
    } else{
        int t = lower_bound(w+1,w+top+1,v[A[i]]) - w;
        for (int j = A[i]; j <= n; j+=low(j))
            update(root[j],root[j],1,top+1,t,-1);
        t = lower_bound(w+1,w+top+1,B[i]) - w;
        for (int j = A[i]; j <= n; j += low(j))
            update(root[j],root[j],1,top+1,t,1);
        v[A[i]] = B[i];
    }
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        init();
         solve();
        for (int i = 0; i <= top; ++i) sum[i] = 0;
        for (int i = 0; i <= n; ++i) rt[i] = 0,root[i] = 0;
    }
    return 0;
}
