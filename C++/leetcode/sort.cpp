#include <iostream>
#include <vector>
using namespace std;

// no increment
void insert_sort(vector<int> &arr)
{
    for (vector<int>::iterator iter = arr.begin() + 1; iter != arr.end(); iter++)
    {
        int key = *iter;
        vector<int>::iterator pos = iter - 1;
        while (pos >= arr.begin() && *pos > key)
        {
            *(pos + 1) = *pos;
            pos--;
        }

        /*         cout << endl
             << *(pos + 1) << " "; */
        *(pos + 1) = key;
        /*         cout << *(pos + 1) << endl;
        for (auto i : arr)
        {
            cout << i << " ";
        } */
    }
    //cout << *(arr.end() - 1) << endl;
}

int main(int argc, char *argv[])
{
    vector<int> arr{5, 4, 3, 2, 1, 1, 1, -1};

    insert_sort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}