//三分法求单峰函数极值
//Y=a*X^2+b*X+c 
//求某点 P(x,y) 到该二次函数曲线的最近距离 
const double mid=0.000001;
int a, b, c; // 函数的三个参数 
int x, y;  // 该点的坐标 
double left, right; // 函数定义域 ，需要赋值 
double calc(double x)
{ return a*x*x+b*x+c; } 
//获取函数的y值
double dist(double dd)
{ return (dd-x)*(dd-x)+(calc(dd)-y)*(calc(dd)-y);} 
//获取函数曲线上的点到线外一点的距离
double Three_search()
{
	double mid, midmid;
    double mid_value, midmid_value;
    //left=?  right=?
    while(left+eps<right)
    {
        mid = (left+right)/2; mid_value=dist(mid);
        midmid=(mid+right)/2; midmid_value=dist(midmid);
        if(mid_value>=midmid_value )
        { left=mid; }//区间逼近
		else
		{ right=midmid; }//区间逼近
    }
    double ans=dist(left);
    //此时的left与right已经逼近到值几乎相同了
    ans = sqrt(ans);
    return ans;
}



