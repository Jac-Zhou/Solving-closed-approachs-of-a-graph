#include<iostream>
using namespace std;

//����˼·�������������
//��ö����ʼλ�õĶ��㣬�����α���ÿ���������ӵ������бߣ�����ж��Ƿ���ϡ��ܳ�Ϊk�ı�;�����ҡ�����ÿ��������һ�Ρ�

int n, k, s, A[20][20], a[20][20], w[20], Visited[20][20];
//n:������  k:�ܳ���    A:�ڽӾ���    a���ڽӱ�  
//w:·���ϵĶ���    s����;������    visited[][]:�м�����  

void search(int x, int y)   //x��ʾ��ǰ�����Ľ�㣬y��ʾ��ǰ���ߵ�·���� 
{
	w[y] = x;  //·���ϵ�y����Ϊ���x 
	if(y==k)  //����ǰ·��������Ϊk 
	{
		if(w[y]==w[0])  //��;��
		{
			for(int i=1; i<=n; i++)
			    for(int j=1; j<=a[i][0]; j++)
			    {
			        Visited[i][a[i][j]] = 0;
			        Visited[a[i][j]][i] = 0;			    	
				}
			//�����visited[i][j]�Ǳ�־���飬����һ����i��j�ıߣ�visited[i][j]��ʾ��ǰ��;�����������ߵĴ��� 
			//��ʼ״̬visited[i][j]=0��ÿ����һ�������ߣ����м�1���� 
			for(int i=0; i<k; i++)
			{
				Visited[w[i]][w[i+1]] += 1;
				Visited[w[i+1]][w[i]] += 1; 
			}
			bool t = true;
			for(int i=1; i<=n; i++)
			    for(int j=1; j<=a[i][0]; j++)
			    	if(Visited[i][a[i][j]]==0 || Visited[a[i][j]][i]==0)  
					//���д�i��j�ı߻�û�б������������;������������
			    	{
					    t = false;
			    	    break; 
					}
			//��֤ 
			if(t==true)
			{
				s++;
				for(int i=0; i<=k; i++)
				    cout<<w[i]<<" ";
				cout<<endl;
				//��� 
			}	    
		} 
		return; 
	}	
	for(int j=1; j<=a[x][0]; j++)
	    search(a[x][j], y+1);	
}

int main()
{
	printf("�����붥������ͱ�;�����ȣ�"); 
	cin>>n>>k;

	//ʹ���ڽӱ�ĸ�ʽ��������	
/*	cout<<"�������ڽӱ�\n";
    for(int i=1; i<=n; i++)
	    {
	    	cin>>a[i][0];
	    	for(int j=1; j<=a[i][0]; j++)
	    	    cin>>a[i][j];
		}
*/	

	cout<<"���Կո�ָ������ڽӾ���\n";
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>A[i][j];

    //�ڽӾ���ת�����ڽӱ�    
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
	cout<<"�����;�����£�\n";
	for(int i=1; i<=n; i++)
	    search(i, 0);  //�ӵ�i������������ 
	printf("��Ϊ%d�ı�;������%d��", k, s);
}
