
#include<iostream>
using namespace std;

class btreenode
{
public:
    int *keys;
    int t;
    btreenode **child;
    int n;
    bool leaf;

    btreenode(int tr,bool l)
    {
        t=tr;
        leaf=l;
        keys = new int[2*t-1];
        child= new btreenode*[2*t];
        n=0;
    }

    void traverse()
    {
        int i;
        for(i=0; i<n; i++)
        {
            if(!leaf) child[i]->traverse();
            cout<<keys[i]<<" ";
        }
        if(!leaf) child[i]->traverse();
    }

    btreenode* search(int k)
    {
        int i=0;
        while(i<n && k>keys[i])
            i++;
        if(i<n && keys[i]==k)
            return this;
        if(leaf)
            return nullptr;

        return child[i]->search(k);
    }

    void insert(int k)
    {
        int i=n-1;
        if(leaf)
        {
            while(i>=0 && keys[i]>k)
            {
                keys[i+1] = keys[i];
                i--;
            }
            keys[i+1] = k;
            n++;
        }
        else
        {
            while(i>=0 && keys[i]>k)
                i--;
            if(child[i+1]->n==2*t-1)
            {
                split(i+1,child[i+1]);
                if(keys[i+1]<k)
i++;
                }
            child[i+1]->insert(k);
        }
    }

    void split(int i,btreenode* y)
    {
        btreenode* z = new btreenode(y->t,y->leaf);
        z->n = t - 1;

        for(int j=0; j<t-1; j++)
            z->keys[j] = y->keys[j+1];
        if(!y->leaf)
            for(int j=0; j<t; j++)
                z->child[j] = y->child[j+t];

        y->n = t-1;

        for(int j=n; j>=i+1; j--)
            child[j+1]=child[j];

        child[i+1] =z;

        for(int j=n-1; j>=1; j--)
            keys[j+1] = keys[j];

        keys[i] = y->keys[t-1];
        n++;
    }

};

class btree
{
    btreenode* root;
    int t;
public:
    btree(int tr):t(tr),root(nullptr) {}

    void insert(int k)
    {
        if(!root)
        {
            root=new btreenode(t,true);
            root->keys[0]=k;
            root->n=1;
        }
        else
        {
            if(root->n = 2*t-1)
            {
                btreenode* s = new btreenode(t,false);
                s->child[0] =root;
                s->split(0,root);
                int i=(s->keys[0]<k) ? 1:0;
                s->child[i]->insert(k);
                root = s;

            }
            else
            {
                root-> insert(k);
            }
        }
    }

    void search(int k)
    {
        btreenode* result= root?root->search(k) : nullptr;
        if(result)
            cout<<"key" << k <<"found."<<endl;
        else
            cout<<"key" << k <<"not found."<<endl;
    }

    void traverse()
    {
        if(root)
        {
            cout<<"inorder traversel:";
            root->traverse()<<endl;
        }
        else
        {
            cout<<"tree is empty.\n";
        }
    }
};
int main()
{
    btree bt(2);
    cout<<"b tree of order 3";

    int choice,key;
    do
    {
        cout<<"\n1.insert\n2.search\n3.inorder traversal\n4.exit\n";
        cout<<"enter choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"enter key to insert: ";
            cin>>key;
            bt.insert(key);
            cout<<"inserted " <<key<<endl;
            break;

        case 2:
            cout<<"enter key to search: ";
            cin>>key;
            bt.search(key);
            break;


        case 3:
            bt.traverse();
            break;

        case 4:
            cout<<"invalid choice"<<endl;
        }
    }
    while(choice!=4);

    return 0;

}
