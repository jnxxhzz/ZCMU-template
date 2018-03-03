//欧拉函数
//求1~(N-1)中有多少个数与N互质 
//时间复杂度：sqrt(N) 
int eular(long long a)  
{
    long long tem=a;
    for(int i=2;i*i<=a;i++)
    {
    	if(a%i==0)  
        {  
            tem=tem/i*(i-1);//欧拉函数  
            while(!(a%i)) a/=i;  
        }  
	} 
    if(a!=1) tem=tem/a*(a-1);  //a本身就是素数  
    return tem;  
}



