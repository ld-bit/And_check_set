 //是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 //给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
  public:
class UnionFindSet
{
  public:
    UnionFindSet(int n)
    {
      _v.resize(n,-1);
    }
    int FindRoot(int x)
    {
      while(_v[x]>=0)
      {
       x=_v[x];
      }
      return x;
    }
    bool Union(int x1 ,int x2)
    {
      int root1=FindRoot(x1);
      int root2=FindRoot(x2);
      if(root1==root2)
      {
        return false;
      }
      _v[root1]=_v[root1]+_v[root2];
      _v[root2]=root1;
      return true;
    }
    int size()
    {
      int res=0;
      for(int i=0;i<_v.size();i++)
      {
          if(_v[i]<0)
          {
            ++res;
          }
      }
      return res;
    }
  private:
    vector<int>_v;
};
int FindCirclem(vector<vector<int>>& M)
{
    UnionFindSet ufs(M.size());
    for(int i=0;i<M.size();i++)
    {
      for(int j=0;j<M[0].size();j++)
      {
        if(i!=j) 
        {
          if(M[i][j]==1)
          ufs.Union(i,j);
        }
      }
    }
    return ufs.size();
}
};
int main()
{
  vector<vector<int>>arr;
  int rows;
  int cols;
  cout << "please input row and col: ";
  cin >> rows >> cols;
  arr.resize(rows);
  for(int i=0;i<rows;i++)
  {
    arr[i].resize(cols);
  }
  cout << "please input the element of the arr: ";
  for(int i=0;i< rows;i++)
  {
    for(int j=0; j<cols ;j++)
    {
      cin >> arr[i][j];
    }
  }
  Solution s;
  cout << s.FindCirclem(arr) <<endl;
}
