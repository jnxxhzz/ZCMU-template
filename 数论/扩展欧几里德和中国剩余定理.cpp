//扩展欧几里德
//对于不完全为 0 的非负整数 a，b，
//必然存在整数对 x，y ，使得 gcd（a，b）=ax+by。
//x 即是 a 对于 b 的乘法逆元：a * x % b = 1 
int e_gcd(int a,int b,int &x,int &y)
{
    if (b==0)
	{
        x=1,y=0;
        return a;
    }
    int res=e_gcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}

//费马小定理：
//假如p是素数，且a与p互质，那么a^(p-1) = 1 (mod p);
//这个公式可转化为 : a * a^(p-2) = 1 (mod p)
//即：a^(p-2) 是 a 关于 p 的 乘法逆元 


//用扩展欧几里德解决中国剩余定理
/*	中国剩余定理：
	X % Bi = Ai,求最小的未知数X 
*/

int solve(int a[],int b[],int n)
{
	int sum=0,s=1,x,y;
	for(int i=0;i<n;i++) s*=a[i];
	for(int i=0;i<n;i++)
	{
		m=s/a[i];
		e_gcd(m,a[i],x,y);
		x=(x%a[i]+a[i])%a[i];
		sum=(sum+m*b[i]*x%s)%s;
	}
	return sum;
}

