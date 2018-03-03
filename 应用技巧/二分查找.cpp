//二分查找

//lower_bound()函数 
lower_bound(a+begin,a+end,k) 
//返回第一个 键值 大于等于 k 的地址,若无则返回end的地址  

//upper_bound()函数
upper_bound(a+begin,a+end,k)
//返回第一个 键值 大于 k 的地址,若无则返回end的地址 

//一般写法 
int binarySearch(int nums[], int target) 
{ 
	int low = 0, high = nums.length-1; 
	while (low <= high) 
	{
		int mid = low + (high - low) / 2; 
		if (nums[mid] < target) 
		{ low = mid + 1; } 
		if (nums[mid] > target) 
		{ high = mid - 1; } 
		if (nums[mid] == target) 
		{ return mid; } 
	} 
	return low; 
}


