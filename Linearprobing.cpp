#include<iostream>

using namespace std;

int size = 10;

// Lamda should be always less or equal to 0.5
// Avg succcessful search t = 1/lamda*ln(1/1-lamda)
// avg unsuccessful search t = 1/1-lamda
// Linear probing has a problem of primary clusting.
// In linear probing, we don't suggest deletion of elements as it will lead to rehashing of elements.

// Hashing using linear probing


int Hashed(int key)
{
    return key%size;
}

int probe(int H[], int key)
{
    int index = Hashed(key);
    int i = 0;
    while(H[(index+i)%size]!=0)
    {
        i++;
    }
    return (index+i)%size;
}


void Insert(int H[], int key)
{
     int index = Hashed(key);
     
     if(H[index]!=0)
     {
        index = probe(H,key);
        H[index] = key;
     }
}



int main()
{
    
    int HT[10];

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);


    return 0;
}