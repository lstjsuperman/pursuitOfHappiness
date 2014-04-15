#ifndef __DYNAMIC_PROGRAMMING__
#define __DYNAMIC_PROGRAMMING__

#include <iostream>
#include <algorithm>

using namespace std;

const int n = 4;
int weight[n] = {2, 1, 3, 2};
int value[n] = {3, 2, 4, 2};

const int Weight = 5;

int values[n+1][Weight];

void getMaxValue()
{
    for (int t = 2; t <= Weight; t++) {
        values[0][t] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= Weight; w++)
        {
            if (weight[i-1] > w)
            {
                values[i][w] = values[i-1][w];
            }
            else
            {
                values[i][w] = max(values[i-1][w], values[i-1][w-weight[i-1]] + value[i-1]);
            }
        }
    }
    cout << "max values is: " << values[n-1][Weight] << endl;
}


#endif // __DYNAMIC_PROGRAMMING__
