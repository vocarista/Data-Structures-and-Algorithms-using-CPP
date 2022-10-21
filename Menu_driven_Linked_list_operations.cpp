//To implement linked list using C++

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node<T> *next;
};

template <class T>
class list
{
    node<T> *a;
    public:
    list(){a=NULL;}
    void create(T);
    void create();
    void print();
    void deletenode(T);
    void searchnode(T);
    void insertf(T);    //Insert in front.
    void inserta(T);    //Insert after the given node.
    void insertb(T);    //Insert before the given node.
    void deletef();     //Delete the first node.
    void deletee();     //Delete the end node.
    void deletea(T);    //Delete after the given node.
    void deletelist();  //Delete the entire list.
    node<T>* msort(node<T>*); //Recursive function to perform merge sort
    node<T>* merge(node<T>*, node<T>*);  //Function to merge the two partitiion created during merge sort.
    void quit();
    void msort();       //A public function to call the actual msort function.
    void menu();        //To present the available operations to be perfomed on the linked list.
    void fncall(int);   //Function to call the desired function chosen during the execution of menu().
};

template <class T>
void list<T>::msort()
{
    a=msort(a);
}

template <class T>
void list<T>::create()
{
    int n;
    T x;
    cout<< "Enter the number of elements -> ";
    cin>>n;
    while(n--)
    {
        cout<< "Enter a number-> ";
        cin>>x;
        create(x);
    }
}

template <class T>
void list<T>::inserta(T x)
{
    node<T> *p, *q;
    T xe;
    cout<< "Enter data -> ";
    cin>>xe;
    p= new node<T>;
    p->data=xe;
    p->next=NULL;

    for (q=a;q!=NULL&&q->data!=x;q=q->next);
    if (q==NULL)
    {
        cout<<"\nElement not found.";
    }
    else
    {
        p->next=q->next;
        q->next=p;
    }
}

template <class T>
void list<T>::insertb(T x)
{
    node<T> *p, *q, *r;
    p= new node<T>;
    T xe;
    cout<< "Enter data -> ";
    cin>>xe;
    p= new node<T>;
    p->data=xe;
    p->next=NULL;

    if(x==a->data)
    {
        insertf(xe);
        goto END;
    }
    for (q=a,r=a;q!=NULL&&q->data!=x;q=q->next)
        r=q;
    if(q==NULL)
        cout<<"\nElement not found.";
    else
    {
        r->next=p;
        p->next=q;
    }
    END:;
}

template <class T>
void list<T>::deletef()
{
    node<T> *p;
    p=a;
    a=a->next;
    delete p;
}

template <class T>
void list<T>::deletee()
{
    node<T> *p, *q;
    for (p=a;p->next!=NULL;p=p->next)
        q=p;
    q->next=NULL;
    delete p;
}

template <class T>
void list<T>::deletea(T x)
{
    node<T>  *q, *p;
    for(q=a;q!=NULL&&q->data!=x;q=q->next);
    p=q->next;
    q->next=p->next;
    delete p;
}

template <class T>
void list<T>::deletelist()
{
    node<T> *p, *q;
    for (q=a;q!=NULL;)
    {
        p=q;
        q=q->next;
        delete p;
    }
    a=NULL;
}

template <class T>
void list<T>::create(T x)
{
    node<T> *p, *q;
    p= new node<T>;
    p->data=x;
    p->next=NULL;
    if (a==NULL)
        a=p;
    else
    {
        for (q=a;q->next!=NULL;q=q->next);
        q->next=p;
    }
}

template <class T>
void list<T>::print()
{
    node<T> *p;
    for (p=a;p!=NULL;p=p->next)
        cout<<" "<<p->data;
}

template <class T>
void list<T>::deletenode(T x)
{
    node<T> *p, *q;
    if (a->data==x)
        deletef();
    else
    {
        for (q=a,p=a->next;p!=NULL;)
        {
            if (p->data==x)
            {
                q->next=p->next;
                delete p;
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
    }
}

template <class T>
void list<T>::searchnode(T x)
{
    node <T> *p, *q;
    for (p=a;p!=NULL;p=p->next)
    {
        if (p->data==x)
        {
            cout<<"\nELement found.";
            break;
        }
    }
    if (p==NULL)
        cout<<"\nElement not found.";
}

template <class T>
void list<T>::insertf(T x)
{
    node<T> *p;
    p= new node<T>;
    p->data=x;
    p->next=a;
    a=p;
}

template <class T>
node<T>* list<T>::msort(node<T> *p)
{
    node<T> *b, *c, *k, *l;
    if (p->next!=NULL)
    {
        b=p;
        c=p->next->next;
        while(c!=NULL&&c->next!=NULL)
        {
            b=b->next;
            c=c->next->next;
        }
        c=b->next;
        b->next=NULL;

        k=msort(p);
        l=msort(c);

        return merge(k,l);
    }
    else
        return p;
}

template <class T>
node<T>* list<T>::merge(node<T> *L1, node<T> *L2)
{
    node<T> *p, *q, *r, *a;
    a=NULL;
    p=L1, q=L2;
    if (p->data<q->data)
    {
        a=r=p;
        p=p->next;
    }
    else
    {
        a=r=q;
        q=q->next;
    }

    while(p!=NULL&&q!=NULL)
    {
        if (p->data<q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            r=r->next;
            q=q->next;
        }
    }

    if(p!=NULL)
        r->next=p;
    if(q!=NULL)
        r->next=q;

    return a;
}

template <class T>
void list<T>::menu()
{
    int c;
    do{
    cout<<"\n              MAIN MENU            ";
    cout<<"\nCreate the list:                     1";
    cout<<"\nPrint the list:                      2";
    cout<<"\nAdd a node at the beginning:         3";
    cout<<"\nAdd a node at the end:               4";
    cout<<"\nAdd a node before a give node:       5";
    cout<<"\nAdd a node after a given node:       6";
    cout<<"\nDelete a node from the beginning:    7";
    cout<<"\nDelete a node from the end:          8";
    cout<<"\nDelete a given node:                 9";
    cout<<"\nDelete a node after a given node:    10";
    cout<<"\nDelete the entire list               11";
    cout<<"\nSort the list:                       12";
    cout<<"\nEXIT:                                13";
    cout<<"\nEnter your selection -> ";
    cin>>c;
    if (c==13)
        break;
    else
        fncall(c);
    }while(true);
}

template <class T>
T getinput()
{
    cout<< "Enter a number -> ";
    T x;
    cin>>x;
    return x;
}

template <class T>
void list<T>::fncall(int x)
{
    switch(x)
    {
        case 1: create();break;
        case 2: print();break;
        case 3: insertf(getinput());break;
        case 4: create(getinput());break;
        case 5: insertb(getinput());break;
        case 6: inserta(getinput());break;
        case 7: deletef();break;
        case 8: deletee();break;
        case 9: deletenode(getinput());break;
        case 10: deletea(getinput());break;
        case 11: deletelist();break;
        case 12: msort();break;
    }
}

int main()
{
    list <int> L1;
    L1.menu();
    return 0;
}
