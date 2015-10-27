/*
钓鱼比赛
ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子每分钟有不同的概率钓上鱼，cc一直在坐标(x,y)的格子钓鱼，而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的概率大？为多少？

输入描述:
第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1)


输出描述:
输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)

输入例子:
2 2 1 1 1
0.2 0.1
0.1 0.4

输出例子:
equal
0.20
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main ()
{
    int rows,lines,x,y,time;
    while(cin >> rows >> lines >> x >> y >> time)
    {
    double **possi = new double *[rows];
    for(int i=0;i<rows;++i)
        possi[i] = new double[lines];

    for(int i=0;i<rows;++i)
    for(int j=0;j<lines;++j)
        cin >> possi[i][j];

    double sum_ss=0.0;
    for(int i=0;i<rows;++i)
    for(int j=0;j<lines;++j)
        sum_ss+=possi[i][j];

    //每分钟的概率
    sum_ss = sum_ss/rows/lines;
    sum_ss = 1 - pow(1-sum_ss,time);

    double sum_cc = possi[x-1][y-1];
    sum_cc = 1 - pow(1-sum_cc,time);

    cout << setiosflags(ios::fixed) << setprecision(2);
    if(sum_ss > sum_cc)
        cout<<"ss"<<endl<<sum_ss<<endl;
    else if(sum_ss <sum_cc)
        cout<<"cc"<<endl<<sum_cc<<endl;
    else
        cout<<"equal"<<endl<<sum_ss<<endl;

    for(int i=0;i<rows;++i)
        delete[]possi[i];
    delete[]possi;
    }
    return 0;
}

