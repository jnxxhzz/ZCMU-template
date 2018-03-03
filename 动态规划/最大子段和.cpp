//最大子段和
//时间复杂度：O(n)
//返回： 最大子段和res 
//子段起点终点位置 start end (同结果下取较长靠前区间)
int start,end;
int maxsub(int n,int a[])
{
	int sum,res=-INF, k=0;
	start=end=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>res)
			res=sum,start=k,end=i;
		if(sum<0)
			sum=0,k=i+1;
	}
	return res;
} 





