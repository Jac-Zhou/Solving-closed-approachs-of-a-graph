#include<iostream>
using namespace std;

//整体思路：深度优先搜索
//先枚举起始位置的顶点，再依次遍历每个顶点连接到的所有边，最后判断是否符合“总长为k的闭途径”且“经过每条边至少一次”

int n, k, s, A[20][20], a[20][20], w[20], Visited[20][20];
//n:顶点数  k:总长度    A:邻接矩阵    a：邻接表  
//w:路径上的顶点    s：闭途径条数    visited[][]:中间数组  

void search(int x, int y)   //x表示当前搜索的结点，y表示当前已走的路径长 
{
	w[y] = x;  //路径上第y个点为结点x 
	if(y==k)  //若当前路径长正好为k 
	{
		if(w[y]==w[0])  //闭途径
		{
			for(int i=1; i<=n; i++)
			    for(int j=1; j<=a[i][0]; j++)
			    {
			        Visited[i][a[i][j]] = 0;
			        Visited[a[i][j]][i] = 0;			    	
				}
			//这里的visited[i][j]是标志数组，对于一条从i到j的边，visited[i][j]表示当前闭途径经过这条边的次数 
			//初始状态visited[i][j]=0，每经过一次这条边，进行加1操作 
			for(int i=0; i<k; i++)
			{
				Visited[w[i]][w[i+1]] += 1;
				Visited[w[i+1]][w[i]] += 1; 
			}
			bool t = true;
			for(int i=1; i<=n; i++)
			    for(int j=1; j<=a[i][0]; j++)
			    	if(Visited[i][a[i][j]]==0 || Visited[a[i][j]][i]==0)  
					//若有从i到j的边还没有被遍历过，则该途径不符合条件
			    	{
					    t = false;
			    	    break; 
					}
			//验证 
			if(t==true)
			{
				s++;
				for(int i=0; i<=k; i++)
				    cout<<w[i]<<" ";
				cout<<endl;
				//输出 
			}	    
		} 
		return; 
	}	
	for(int j=1; j<=a[x][0]; j++)
	    search(a[x][j], y+1);	
}

int main()
{
	printf("请输入顶点个数和闭途径长度："); 
	cin>>n>>k;

	//使用邻接表的格式进行输入	
/*	cout<<"请输入邻接表：\n";
    for(int i=1; i<=n; i++)
	    {
	    	cin>>a[i][0];
	    	for(int j=1; j<=a[i][0]; j++)
	    	    cin>>a[i][j];
		}
*/	

	cout<<"请以空格分隔输入邻接矩阵：\n";
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>A[i][j];

    //邻接矩阵转换成邻接表    
	for(int i=1; i<=n; i++)
	{
		A[i][0] = 0;
		for(int j=1; j<=n; j++)
			if(A[i][j]!=0)
			{
				a[i][0]++;
				a[i][a[i][0]] = j;
			}
	}

	s=0;
	cout<<"所求闭途径如下：\n";
	for(int i=1; i<=n; i++)
	    search(i, 0);  //从第i个结点出发搜索 
	printf("长为%d的闭途径共有%d条", k, s);
}
