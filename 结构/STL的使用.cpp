//STL的使用

//队列优先级的控制 
struct stop{
	int dis,gas;
	stop(int x,int y):dis(x),gas(y){}
	friend bool operator<(const stop &a,const stop &b)
	{ return a.dis<b.dis; }   //从大到小排序 
};
struct cmp{
	bool operator()(int x,int y)
	{ return x<y; }    //从大到小排序 
};
//结构题内部 
priority_queue<int,vector<int>,cmp> pq;
priority_queue<stop> s;

//set
set<int> s;//建立set， 插入元素 
s.insert(1); s.insert(3); s.insert(5);         
//建立set指针                                  
set<int>::iterator it;                         
//查找                                         
it=s.find(1);                                  
if(it==s.end()) puts("Not found\n");           
else puts("Found!\n");                         
//删除                                         
s.erase(3);                                    
//查找计数                                     
if( s.count(3) != 0 ) puts("Found!\n");        
else puts("Not found\n");                      
//遍历所有元素                                 
for(it=s.begin();it!=s.end();++it)             
	printf("%d\n",*it);                        
	              
				                               
//map申明，int为键，string为值	               
map<int,const char*> m;                        
//插入元素                                     
m.insert(make_pair(1,"One"));                  
m.insert(make_pair(2,"Two"));                  
m[100]="Hundred";                              
//查找元素                                     
map<int,const char*>::iterator its;            
it=m.find(1);                                 
puts(it->second);                             
it=m.find(2);                                 
if(it==m.end()) puts("Not found!\n");         
else puts(it->second);                        
puts(m[10]);                                   
//删除元素                                     
m.erase(10);                                   
//遍历所有元素                                 
for(it=m.begin();it!=m.end();it++)          
printf("%d:%s\n",it->first,it->second);  	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
