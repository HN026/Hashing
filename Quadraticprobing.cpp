#include<iostream>

using namespace std;

int size = 10;

// Here f(i) = i*i;
// It solves the clustering of elements problems which was a part of linear probing.
// for any function to be the most of the things that can be 

int hashfunc(int key)
{
    return key%size;
}

int probe(int H[], int key)
{
    int index = hashfunc(key);
    int i = 0;
    while(H[(index+i*i)%size]!=0)
    {
        i++;
    }
    return (index+i*i)%size;
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

    while(H[(index+i*i)%size]!=key)
    {
        i++;
    }
    return (index+i*i)%size;
}

int main()
{

    int HT[size] = {0};

    Insert(HT,23);
    Insert(HT,43);
    Insert(HT,13);
    Insert(HT,27);

    cout<<"Key found at "<<Search(HT,43)<<endl;
    
     return 0;
}