/*
罪犯转移
C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值越大罪越重。现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值之和不超过t，问有多少种选择的方式？ 

输入描述:
第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪行值ai(0≤ai≤1e9)


输出描述:
一行输出答案。

输入例子:
3 100 2
1 2 3

输出例子:
2
*/
#include <iostream>
#include <vector>
using namespace std;
int maxSumvArray(const vector<int> &cri ,const int total,const int cunt );
int main ()
{
    int n;//罪犯人数
    int total;//犯人罪行值之和
    int cunt;//转移犯人数目
    while (cin>>n>>t>>c)
    {
        if(cunt>n || cunt<0)
            return -1;
        vector<int> criminal(n);
        for(int i =0;i<n;i++)
        {
            cin>>criminal[i];
        }
        cout<<maxSumvArray(criminal,total,cunt)<<endl;
    }
}

int maxSumvArray(const vector<int> &cri ,const int total,const int cunt )
 {
    //
     int sum=0;//罪行值之和
     int count=0;//罪犯个数
     int count_number=0;//选择方式个数
    /*控制起始端与末尾
        i控制整个元素的范围
        j控制第一个元素的范围
    */
     for(vector<int>::size_type i =0,j =0;i< cri.size()&&j<=cri.size()-cunt;i++)
     {
         sum+=cri[i];
         count++;
         if(count == cunt && sum <= total)
            count_number++;
        //利用动态规划处理，已有的解来得出新解
        while(j <= cri.size()-cunt&&(count > cunt|| sum > total))
        {
            sum-=cri[j];
            j++;
            count--;
            if(count == cunt && sum <= total)
            count_number++;
        }
     }
    return count_number;
 }
