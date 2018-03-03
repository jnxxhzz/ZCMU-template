/*	扫描线  矩形面积合并 
	原理 ：线段树 
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#define lson id*2
#define rson id*2+1  
using namespace std;
map<double,int>hashx;//表示每一个坐标对应的hash后的值 
map<double,int>hashy;//表示每一个坐标对应的hash后的值 
map<int,double>mpx;//表示hash后的值对应的实际坐标 
map<int,double>mpy;//表示hash后的值对应的实际坐标 
struct edge1{
    int val; //记录这个点所表示的区间是否被线段所覆盖 
    double len;//记录节点所代表区间已经被覆盖的长度 
}tree[1000];
//注意此时每一个叶子节点要想象成个长度为1的区间
//例如原本应代表位置1的节点此时应代表1~2的区间 
struct edge2{
    double xnow,yup,ydown;
    //xnow表示它实际的横坐标 
    //yup与ydown分别表示它的两个纵坐标 
    int id;//表示是矩形的靠前的边或是靠后的边 
}s[1000];
double px[1000],py[1000];//用于hash 
int cmp(edge2 a,edge2 b)
{
    if (a.xnow!=b.xnow)
    return a.xnow<b.xnow;
    else  if (a.ydown!=b.ydown)
    return a.ydown<b.ydown;
    else 
    return a.yup<b.yup; 
}//按x排序矩形的边 
//线段树内容 
void push_up(int id)
{
    tree[id].len=tree[lson].len+tree[rson].len;
    tree[id].val=tree[lson].val+tree[rson].val;
    return ;
}
void build_tree(int id,int l,int r)
{
    if (l==r)
    {
        tree[id].val=0;
        tree[id].len=0;
        return ;
    }
    int mid=(l+r)/2;
    build_tree(lson,l,mid);
    build_tree(rson,mid+1,r);
    push_up(id);
    return ;
}
void add_tree(int id,int l,int r,int L,int R,int v)
{
    if (l==r&&l>=L&&r<=R)
    {
        tree[id].len=0;
        tree[id].val+=v;
        if (tree[id].val>0)
        tree[id].len=mpy[l+1]-mpy[l]; 
        //这里加1的原因是此时的l代表的是l~l+1的这个区间 
     return ;
    }
    int mid=(l+r)/2;
    if (mid>=L)
    add_tree(lson,l,mid,L,R,v);
    if (mid+1<=R)
    add_tree(rson,mid+1,r,L,R,v);
    push_up(id);
    return ;
}//线段树完 
int n,t=0;
double x1,x2,y1,y2;
int main()
{
    while(cin>>n)
    {
        if (n==0)
        return 0;
        t++;//hash开始 
        for (int i=1;i<=n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            s[i].xnow=x1;
            s[i].yup=y2;
            s[i].ydown=y1;
            s[i].id=1;
            s[i+n].xnow=x2;
            s[i+n].yup=y2;
            s[i+n].ydown=y1;
            s[i+n].id=-1;
            px[i]=x1;
            px[i+n]=x2;
            py[i]=y1;
            py[i+n]=y2;
        }
        sort(px+1,px+1+2*n);//注意此处是2*n，因为 每一个矩形存了两个横坐标 
        sort(py+1,py+1+2*n);
        int numx=0,numy=0;
        for (int i=1;i<=2*n;i++)
        {
            if (px[i]!=px[i+1])
            {
                numx++;
                hashx[px[i]]=numx;
                mpx[numx]=px[i];
            }
            if (py[i]!=py[i+1])
            {
                numy++;
                hashy[py[i]]=numy;
                mpy[numy]=py[i];
            }
        }   //hash结束 
        sort(s+1, s+1+ 2*n ,cmp);//注意2*n 
        build_tree(1,1,n);
        double ans=0.0;
        for (int i=1;i<=2*n;i++)
        {
            //每次到达一个新的x坐标时先计算再加边 
            ans+=tree[1].len*(s[i].xnow-s[i-1].xnow);
            while(s[i].xnow==s[i+1].xnow)
            {
                add_tree(1,1,numy,hashy[s[i].ydown],hashy[s[i].yup]-1,s[i].id);
                //要让 hashy[s[i].yup]减1是因为每一个节点原本所代表的位置x被当做x~x+1 
                i++;
            }
            add_tree(1,1,numy,hashy[s[i].ydown],hashy[s[i].yup]-1,s[i].id);
        }
        printf("Test case #%d\n",t);
        printf("Total explored area: %.2f\n\n",ans);//poj上的输出格式很坑       
    }
}
