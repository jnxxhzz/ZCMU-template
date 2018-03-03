//Ê÷×´Êý×é Ò»Î¬

int res[MAXN];
int lowbit(int x)
{ return x & (-x); }
void update(int x,int add)
{  
    while(x<=MAXN)  
    {      
        res[x]+=add;    
        x+=lowbit(x); 
    }
}
int get_sum(int x)
{  
    int ret=0; 
    while(x!=0)  
    {       
        ret+=res[x];   
        x-=lowbit(x);   
    }  
    return ret;
}



