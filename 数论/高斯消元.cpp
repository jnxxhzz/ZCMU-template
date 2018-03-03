//高斯消元
//求解线性方程组 

//高斯消元法解异或方程组，返回方程解得个数。  
const int N = 30;  
int A[N][N];//关系矩阵  
int Gauss(int equ,int var)
{//返回解得个数。  
    int row,col;  
    for(row=0,col=0;row<equ&&col<var;col++,row++)
	{  
        int max_r=row;//默认最大为本行  
        for(int i=row+1;i<equ;i++)
		{//从上到下找出最大的，此处01矩阵为1  
            if(A[row][col]==1)  break;  
            if(A[max_r][col]<A[i][col])
			{  max_r=i;break;  }  
        }  
        if(max_r!=row)
		{  
            for(int j=0;j<=var;j++)
				swap(A[max_r][j],A[row][j]);  
        }  
        if(A[row][col]==0) row--;//重新查找本行下一列   
        for(int i=row+1;i<equ;i++)
		{  
            if(A[i][col]==0)continue;//如果某行已为0，则跳过本行  
            for(int j=col;j<=var;j++)
                A[i][j]^=A[row][j];   
        }  
    }  
    for(int i=row;i<equ;i++)  
        if(A[i][col]!=0) return -1;  
    return 1<<(n-row);//可能会用long long  1LL<<(n-row)  
}  




//高斯消元法解异或方程组（枚举所有解）  
const int N = 30;  
int n;  
int A[N][N];  
int Major[N];//记录主元所在位置  
int x[N];//临时解 x[]={0,1};  
  
void DFS_freevar(int n,int r,int var){//递归枚举自由元  
    if(var==-1){  
          
        //...对于每一个解进行处理。  
    }  
    if(var==Major[r]){//当前为主元  
        int y=A[r][n];  
        for(int i=var+1;i<n;i++){  
            y^=(A[r][i]*x[i]);  
        }  
        x[var]=y;  
        DFS_freevar(n,r-1, var-1) ;  
    }  
    else{//不是主元枚举  
        for(int i=0;i<2;i++){  
            x[var]=i;  
             DFS_freevar(n,r, var-1) ;  
        }  
    }  
    
}  
int Gauss(int equ,int var){//返回是否有解  
    int row,col;  
    for(row=0,col=0;col<var&&row<equ;col++,row++){  
        int max_r=row;  
        for(int i=row+1;i<equ;i++){  
            if(A[row][col]==1)break;  
            if(A[max_r][col]<A[i][col]){  
                max_r=i;break;  
            }  
        }  
        if(A[max_r][col]==0){  
            row--;  
            continue;  
        }  
        if(max_r!=row)  
            for(int j=0;j<=var;j++)  
                swap(A[row][j],A[max_r][j]);  
        for(int i=row+1;i<equ;i++){  
            if(A[i][col]==0)continue;  
            for(int j=col;j<=var;j++){  
                A[i][j]^=A[row][j];  
            }  
        }  
        Major[row]=col;  
    }  
    for(int i=row;i<equ;i++){//无解的情况  
        if(A[i][col]!=0)return -1;  
    }  
    DFS_freevar(n,row-1,col-1);  
    return 1;  
}  


//浮点型只有唯一解时可计算  
double A[N][N];  
double x[N];  
void Gauss(int equ,int var){  
    int row,col;  
    for(row=0,col=0;col<var&&row<equ;col++,row++){  
        int max_r=row;  
        for(int i=row+1;i<equ;i++){  
            if(eps<fabs(A[i][col])-fabs(A[max_r][col])){  
                max_r=i;  
            }  
        }  
        if(max_r!=row)  
            for(int j=0;j<var+1;j++)  
                swap(A[row][j],A[max_r][j]);  
        for(int i=row+1;i<equ;i++){  
            if(fabs(A[i][col])<eps)continue;  
            double tmp=-A[i][col]/A[row][col];  
            for(int j=col;j<var+1;j++){  
                A[i][j]+=tmp*A[row][j];  
            }  
        }  
         
    }  
       for(int i=var-1;i>=0;i--){//计算唯一解。  
        double tmp=0;  
        for(int j=i+1;j<var;j++){  
            tmp+=A[i][j]*x[j];  
        }  
        x[i]=(A[i][var]-tmp)/A[i][i];  
    }  
}  
