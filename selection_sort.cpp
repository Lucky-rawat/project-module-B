#include<iostream>
using namespace std;
int small(int L[], int n, int i);
int main ()
{
int i, j, k, index, t;
int L[10] = { 10, 12, 7, 9, 5 };
cout << "The list of element before sorting:" <<endl;
for(i = 0; i < 5; i++)
{
cout<<L[i]<<endl;
}
for( i = 0;i < 5; i++)
{
index = small(L, 5, i);
t = L[i];
L[i] = L[index];
L[index] = t;
}
cout << "The list of element after sorting:" <<endl;
for(i = 0; i < 5; i++)
{
cout<<L[i]<<endl;
}
return 0;
}
int small(int L[], int n, int i)
{
int s, index, j;
s = L[i];
index = i;
for( j = i+1; j < 5; j++)
{
if(L[j] < s )
{
s = L[j];
index = j;
}
}
return index;
}