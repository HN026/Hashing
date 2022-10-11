#include<iostream>

using namespace std;

// It will try to search the trees less than logn time.
// Drawback of hashing is that a lot of space gets wasted in it.
// In hashing when two keys are mapped at same position, we call it collision. (It happens in many-one type of mapping.)
// For solving the problem of collision, we have two methods: 
// 1. Open hashing -> Chaining
// 2. Closed Hashing -> Open addressing -> a) Linear probing, b) Quadratic probing, c) Double hashing

// Chaining
// Important term in hashing is loading factor which gets denoted by lamda and is equal to No.of keys/size of hashtable.
// For successful search in chaining, avg time taken will be t = 1 + lamda/2
// for unseccessful search in chaining, avg time taken will be t = 1 + lamda

// Hashing using chaining: 

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert( struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(*H == NULL)
    {
        *H = t;
    }
    else
    {
        while(p!=NULL && p->data<x)
        {
            q = p;
            p = p->next;
        }
        if(p==*H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search (struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
};

int hashed(int key)
{
    return key%10;
}


void Insert(struct Node *H[], int key)
{
    int index = key%10;
    SortedInsert(&H[index], key);
}  


int main()
{

    struct Node *HT[10];
    struct Node *temp;
    int i;
    for(i = 0 ; i<10; i++)
    { 
        HT[i] = NULL;
    }

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,32);

    temp = Search(HT[hashed(21)],21);
    cout<<temp->data<<" ";
    

    return 0;
}