//
//  main.cpp
//  Lab1
//
//  Created by Giovanni Masella on 1/31/19.
//  Copyright © 2019 Giovanni. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int FibR(int n)
{
    if (n==0|| n==1)
        return n;
    else return (FibR(n-1) + FibR(n-2));

}

int FibNR(int n)
{
    int F[n];
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= n; i++)
        F[i] = F[i-1] + F[i-2];
    return F[n];
    
}
// This function increments x by 10s to make it easier to read the chart
// It also does the timing for each incrementation of the fibanacci numbers given
void Increment(int n)
{
    clock_t t0, t1;
    for (int i = 10; i <= n; i+=10)
    {
        cout << i;
        t0 = clock();
        cout << right << setw(30) << FibR(i);
        t0 = (clock() - t0) / CLOCKS_PER_SEC;
        cout << right << setw(30) << setprecision(2) << fixed << t0 << "s";
        
        t1 = clock();
        cout << right  << setw(30) << FibNR(i);
        t1 = (clock() - t1) / CLOCKS_PER_SEC;
        cout << right << setw(30) << setprecision(2) << fixed << t1 << "s" << endl;
        
    }
}


int main() {
    
    int x;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Input how many numbers of the Fibonacci sequence" << endl;
    cin >> x;
    
    cout << left << setw(30) << "Integer";
    cout << left << setw(30) << "Recusive Value";
    cout << left << setw(30) << "Recusive Time";
    cout << left << setw(30) << "Non-Recursive Value";
    cout << left << setw(30) << "Non-Recusive Time";
    cout << endl;
    
    Increment(x);
    
    cout << endl << INT_MAX;
    
    return 0;
}



