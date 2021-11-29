#include <bits/stdc++.h>
using namespace std;

uint64_t prime(uint64_t n)
{

    // All prime numbers are odd except two
    if (n & 1)
        n -= 2;
    else
        n--;

    uint64_t i, j;
    for (i = n; i >= 2; i -= 2)
    {
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= sqrt(i); j += 2)
        {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }

    // It will only be executed when n is 3
    return 2;
}

// Driver Code
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    cout << prime(n);
    return 0;
}