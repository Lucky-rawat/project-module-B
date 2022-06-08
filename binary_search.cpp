#include <iostream>
using namespace std;
int binarysearch(int array[],int a, int b, int num){
 if(a<=b){
     int div = (a+b)/2;
     if (array[div] == num)
     return div;
     if (array[div] > num)
       return binarysearch(array,a, div-1, num);
 if (array[div] < num)
      return binarysearch(array, div+1, b, num);
 }
 return -1;
}
int main(void) {
int array[] = {2,4,8,16,32,64,128,3,256,512,1022};
int n = sizeof(array)/sizeof(array[0]);
int num = 128;
int index = binarysearch (array,0,n-1,num);
if(index == -1)
cout<< num <<" is not present in the array";
else
cout<< num<<" is "<< index << "th element in the array";
return 0;
}
