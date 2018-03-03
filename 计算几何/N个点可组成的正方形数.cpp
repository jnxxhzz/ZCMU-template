/*	给出N个点，求可组成的正方形数 */ 

const int N = 1010;
const int H = 10007;
int ptx[N], pty[N];
struct Node{
    int x,y,next;
};
Node node[N];
int cur,n;
LL ans;
int hashTable[H];
void initHash()
{
    for (int i = 0; i < H; ++i) hashTable[i] = -1;
    cur = 0;
    ans = 0;
}
void insertHash(int x, int y)
{
    int h = (x*x + y * y) % H;
    node[cur].x=x;
    node[cur].y=y;
    node[cur].next=hashTable[h];
    hashTable[h]=cur;
    ++cur;
}
bool searchHash(int x, int y)
{
    int h=(x*x+y*y)%H;
    int next;
    next = hashTable[h];
    while (next != -1)
    {
        if (x == node[next].x && y == node[next].y)return true;
        next = node[next].next;
    }
    return false;
}
int main()
{
    while (~scanf("%d", &n))
    {
        initHash();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &ptx[i], &pty[i]);
            insertHash(ptx[i], pty[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int x1 = ptx[i] - (pty[i] - pty[j]);
                int y1 = pty[i] + (ptx[i] - ptx[j]);
                int x2 = ptx[j] - (pty[i] - pty[j]);
                int y2 = pty[j] + (ptx[i] - ptx[j]);
                if (searchHash(x1, y1) && searchHash(x2, y2)) ++ans;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int x1 = ptx[i] + (pty[i] - pty[j]);
                int y1 = pty[i] - (ptx[i] - ptx[j]);
                int x2 = ptx[j] + (pty[i] - pty[j]);
                int y2 = pty[j] - (ptx[i] - ptx[j]);
                if (searchHash(x1, y1) && searchHash(x2, y2)) ++ans;
            }
        }
        ans >>= 2;
        printf("%lld\n", ans);
    }
    return 0;
}
