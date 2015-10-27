/*
裁减网格纸
度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的话，每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把这个正方形剪下来。问剪掉正方形的最小面积是多少。 
输入描述:
第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi,yi(－1e9<=xi,yi<=1e9)表示网格上的点


输出描述:
一行输出最小面积

输入例子:
2
0 0
0 3

输出例子:
9
*/

#include <iostream>
#include <vector>
using namespace std;
int miniSquare(vector<int> &x1,vector<int> &y1);

int main ()
{
    int number;//点数
    while(cin>>number)
    {
       vector<int> x(number);
       vector<int> y(number);
       for(int i =0;i<number;++i)
       {
            cin>>x[i]>>y[i];
       }
       int minSquare = miniSquare(x,y);
       cout<<minSquare<<endl;
    }

}

int miniSquare(vector<int> &x1,vector<int> &y1)
{
    int max_X=x1[0],min_X=x1[0];
    int max_Y=y1[0],min_Y=y1[0];
    for(vector<int>::size_type i = 1;i!=x1.size();++i)
    {
        if(max_X < x1[i])
            max_X = x1[i];
        if(min_X > x1[i])
            min_X = x1[i];
        if(max_Y < y1[i])
            max_Y = y1[i];
        if(min_Y > y1[i])
            min_Y = y1[i];
    }
        int x_Length = max_X - min_X;
        int y_Length = max_Y - min_Y;
        int max_Length = x_Length > y_Length?x_Length:y_Length;
        int minSquare = max_Length*max_Length;
    return minSquare;
}
