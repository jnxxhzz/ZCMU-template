//最大公约数与最小公倍数 

//库函数  
__gcd(a,b) 

//定理： A * B = gcd(a,b) * lcm(a,b)
//两数之积等于其最大公约数与最小公倍数之积  

//最大公约数  辗转相除法 
int GCD( int A, int B)
{
    int temp;
    while( B!= 0 )
    {
        temp=B;
        B=A%B;
        A=temp;
    }
    return A;
}  
