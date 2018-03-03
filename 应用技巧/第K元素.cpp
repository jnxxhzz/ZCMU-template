//取第k个的元素
//平均复杂度O(n)
//注意a[]中的顺序被改变
#define _cp(a,b) ((a)<(b))
//输入数组长度n，数组a，第k大元素 
template <class elemType>/
elemType kthElement(int n,const elemType *a, int k)
{
	elemType t,key;
	int l=0,r=n-1,i,j;
	while(l<r)
	{
		for(key=a[((i=l-1)+(j=r+1))>>1];i<j;)
		{
			for(j--;_cp(key,a[i]);j--);
			for(i++;_cp(a[i],key);i++);
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		if(k>j) l=j+1;
		else r=j;
	}
	return a[k];
}


