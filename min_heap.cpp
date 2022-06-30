#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void show(priority_queue<int, vector<int>, greater<int>> q)
{
    priority_queue<int, vector<int>, greater<int>> mh = q;

    while (!mh.empty())
    {
        cout << "\t" << mh.top();
                mh.pop();
    }

    cout << endl;
}

int main()
{
    int i;
    priority_queue<int, vector<int>, greater<int>> minHeap;



    for (i = 1; i < 6; i++)
    {
        minHeap.push(i * 20);
    }

    cout << "number of elements in  Min Heap  : " << minHeap.size();

    cout << "\n elements in the Min Heap : ";
    show(minHeap);

    cout << "\nAfter Deleting the first element from the Min Heap: ";
    minHeap.pop();
    show(minHeap);
    cout << "\n\n";

    return 0;
}
