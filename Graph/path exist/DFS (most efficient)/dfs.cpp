int visited[MAX][MAX];
bool dfs(vector<vector<int>> &arr,int i,int j,int n)
{
    if(arr[i][j]==2)
    {
        return true;
        
    }
    if(visited[i][j]||arr[i][j]==0)
    return false;
    visited[i][j]=true;
    
    int row[]={0,0,1,-1};
    int col[]={1,-1,0,0};
    
    for(int k=0;k<4;k++)
    {
        int r=row[k]+i;
        int c=col[k]+j;
        if(r>=0&&c>=0&&r<n&&c<n)
        {
            
            if(dfs(arr,r,c,n))
            return true;
           
        }
    }
    return false;
}
bool is_possible(vector<vector<int>> &m, int N) {
    
    int n=N;
    int si=-1,sj=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
                si=i;
                sj=j;
                break;
            }
        }
    }
    if(si==-1||sj==-1)
    return false;// if source istelf does not exist
    memset(visited,false,sizeof(visited));
    
    return dfs(m,si,sj,n);
    
}