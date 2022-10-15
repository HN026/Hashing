#include<iostream>

using namespace std;

int size = 10;

// Lamda should be always less or equal to 0.5
// Here f(i) = i;
// Avg succcessful search t = 1/lamda*ln(1/1-lamda)
// avg unsuccessful search t = 1/1-lamda
// Linear probing has a problem of primary clusting.
// In linear probing, we don't suggest deletion of elements as it will lead to rehashing of elements.

// Hashing using linear probing


int hashfunc(int key)
{
    return key%size;
}

int probe(int H[], int key)
{
    int index = hashfunc(key);
    int i = 0;
    while(H[(index+i)%size]!=0)
    {
        i++;
    }
    return (index+i)%size;
}


void Insert(int H[], int key)
{
     int index = hashfunc(key);
     if(H[index]!=0)
     {
        index = probe(H,key);
     }
     H[index] = key;
}

int Search(int H[], int key)
{
    int index = hashfunc(key);
    int i = 0;

    while(H[(index+i)%size]!=key)
    {
        i++;
    }
    return (index+i)%size;
}


int main()
{
    int HT[size] = {0};

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);

    
    cout<<"Key found at "<<Search(HT,35)<<endl;


    return 0;
}