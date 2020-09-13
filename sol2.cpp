//给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
//只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
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
bool equationsPossible(vector<string>arr)
{
  UnionFindSet ufs(arr.size());
  for(auto& e : arr)
  {
    if(e[1]=='=')
    {
      ufs.Union(e[0]-'0',e[3]-'0');
    }
  }
  for(auto& e : arr)
  {
    if(e[1]=='!')
    {
      int root1=ufs.FindRoot(e[0]-'0');
      int root2=ufs.FindRoot(e[3]-'0');
      if(root1==root2)
        return false;
    }
  }
  return true;
}
};
int main()
{
   vector<string>arr;
   int n;
   cout << "please input size : ";
   cin >> n;
   arr.resize(n,"");
   cout << "please input the element like \"a==b\" or \"a!=b\":  ";
   for (auto &e : arr)
   {
     cin >> e;
   }
   Solution s;
   bool judge = s.equationsPossible(arr);
   if(judge == true)
   {
     cout << "true" <<endl;
   }
   else 
     cout << "false"  << endl;
   return 0;
}
