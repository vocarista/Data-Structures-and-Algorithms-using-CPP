//To implement linked list using C++

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
    node *a;
    public:
    list(){a=NULL;}
    void create(int);
    void create();
    void print();
    void deletenode(int);
    void searchnode(int);
    void insertf(int);
    void inserta(int);
    void insertb(int);
    void deletef();
    void deletee();
    void deletea(int);
    void deletelist();
    void merge(node*,node*,node*);
    node* msort(node*);
    node* merge(node*, node*);
    void quit();
    void msort();
    void menu();
    void fncall(int);
};

void list::msort()
{
    a=msort(a);
}

void list::create()
{
    int n, x;
    cout<< "Enter the number of elements -> ";
    cin>>n;
    while(n--)
    {
        cout<< "Enter a number-> ";
        cin>>x;
        create(x);
    }
}

void list::inserta(int x)
{
    node *p, *q;
    int xe;
    cout<< "Enter a number -> ";
    cin>>xe;
    p= new node;
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

void list::insertb(int x)
{
    node *p, *q, *r;
    p= new node;
    int xe;
    cout<< "Enter a number -> ";
    cin>>xe;
    p= new node;
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

void list::deletef()
{
    node *p;
    p=a;
    a=a->next;
    delete(p);
}

void list::deletee()
{
    node *p, *q;
    for (p=a;p->next!=NULL;p=p->next)
        q=p;
    q->next=NULL;
    delete(p);
}

void list::deletea(int x)
{
    node  *q, *p;
    for(q=a;q!=NULL&&q->data!=x;q=q->next);
    p=q->next;
    q->next=p->next;
    delete(p);
}

void list::deletelist()
{
    node *p, *q;
    for (q=a;q!=NULL;)
    {
        p=q;
        q=q->next;
        delete(p);
    }
    a=NULL;
}

void list::create(int x)
{
    node *p, *q;
    p= new node;
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

void list::print()
{
    node *p;
    for (p=a;p!=NULL;p=p->next)
        cout<<" "<<p->data;
}

void list::deletenode(int x)
{
    node *p, *q;
    if (a->data==x)
        deletef();
    else
    {
        for (q=a,p=a->next;p!=NULL;)
        {
            if (p->data==x)
            {
                q->next=p->next;
                delete(p);
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

void list::searchnode(int x)
{
    node *p, *q;
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

void list::insertf(int x)
{
    node *p;
    p= new node;
    p->data=x;
    p->next=a;
    a=p;
}

node* list::msort(node *p)
{
    node *b, *c, *k, *l;
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

node* list::merge(node *L1, node *L2)
{
    node *p, *q, *r, *a;
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

void list::menu()
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

int getinput()
{
    cout<< "Enter a number -> ";
    int x;
    cin>>x;
    return x;
}

void list::fncall(int x)
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
    list L1;
    L1.menu();
    return 0;
}