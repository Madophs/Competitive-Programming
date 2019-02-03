#include <bits/stdc++.h>
using namespace std;
double Calc(double stdev, double zscore)
{
    double n = 100;
    double stdErr = stdev/sqrt(n);
    double marginError = stdErr*zscore;
    return marginError;
}
int  main()
{
    double mean = 500;
    double stdev = 80;
    double zscore = 1.96;
    double sum = mean-Calc(stdev, zscore);
    double sum1 = mean+Calc(stdev, zscore);
    printf("%.2f\n",sum);
    printf("%.2f\n",sum1);
    return 0;
}