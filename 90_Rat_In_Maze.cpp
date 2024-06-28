#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool isSafe(int newX,int newY, vector<vector<bool>>&visit,vector < vector < int >> & arr,int n)
{
    if((newX>=0 && newX<n) && (newY>=0 && newY<n) && visit[newX][newY]!=1 && arr[newX][newY]==1)return true;

    return false;
}

void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string>&ans,vector<vector<bool>>&visit,string path)
{

    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return ;
    }

    // DLRU

     visit[x][y]=1;

    // Down


    if(isSafe(x+1,y,visit,arr,n))
    {
       
        solve(x+1,y,arr,n,ans,visit,path+'D');
       

    }
    // left
    if(isSafe(x,y-1,visit,arr,n))
    {
       
        solve(x,y-1,arr,n,ans,visit,path+'L');
       

    }
    // right
    if(isSafe(x,y+1,visit,arr,n))
    {
        
        solve(x,y+1,arr,n,ans,visit,path+'R');
        

    }
    // UP
    if(isSafe(x-1,y,visit,arr,n))
    {
        
        solve(x-1,y,arr,n,ans,visit,path+'U');
       
    }
     visit[x][y]=0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>>visit(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0)return ans;

    solve(0,0,arr,n,ans,visit,path);
    return ans;
}

int main()
{
    vector<vector<int>>arr={{1 ,0 ,0 ,0 },
                            {1 ,1 ,0 ,1 },
                            {1 ,1 ,0 ,0 },
                            {0,1 ,1 ,1 }};
    int n=4;
    vector<string>s;
    s=searchMaze(arr,n);
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    return 0;
}