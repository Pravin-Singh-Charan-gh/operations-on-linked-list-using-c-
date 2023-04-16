#include <iostream>
using namespace std;
class linklist
{
private:
    struct node {
        int data;
        node *next;
    }*head;
public:
    linklist()
    {
        head=NULL;
    }
    void append(int num)
    {
        node*temp,*neu;
        if(head==NULL) {
            neu=new node;
            neu->data=num;
            neu->next=NULL;
            head=neu;
        } else {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            neu=new node;
            neu->data=num;
            neu->next=NULL;
            temp->next=neu;
        }
    }
    void addatbeg(int num)
    {
        node *beg;
        beg=new node;
        beg->data=num;
        beg->next=head;
        head=beg;

    }
    void addafter(int loc,int num)
    {
        node *temp=head,*r;

        for(int i=0; i<loc-1; i++) {

            if(temp==NULL) {
                cout<<"Elements less than the entered location "<<loc<<endl;
                return;
            }
            temp=temp->next;
        }
        r=new node;
        r->data=num;
        r->next=temp->next;
        temp->next=r;
    }
    int count()
    {
        node*t=head;
        int i;
        for(i=0; t!=NULL; t=t->next,++i);
        return i;
    }
    void display()
    {
        node *temp=head;
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


    void del(int num)
    {
        node*temp=head,*old;
        bool flag=0;
        while(temp!=NULL) {
            if(temp->data==num) {
                if(temp==head)
                    head=temp->next;

                else
                    old->next=temp->next;

                delete temp;
                flag=1;
                return ;
            } else {
                old=temp;
                temp=temp->next;
            }

        }
        if(!flag)
            cout<<"Element "<<num<<" not found\n";
    }
};


int main()
{
    linklist l;
    cout<<"Number of elements in l.l. : "<<l.count()<<endl;
    l.append(42);
    l.append(30);
    l.append(25);
    l.append(14);
    l.append(17);
    cout<<"Elements in the L.L : ";
    l.display();
    l.addatbeg(99);
    l.addatbeg(88);
    l.addatbeg(77);
    cout<<"Elements of L.L after adding new elemnts at the beginning : ";
    l.display();
    l.addafter(3,41);
    l.addafter(6,89);
    l.addafter(10,60);
    cout<<"L.L after adding elements in the beginning : ";
    l.display();
    l.del(99);
    l.del(103);
    l.del(30);
    l.display();
    return 0;
}
