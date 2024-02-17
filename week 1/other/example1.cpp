#include <iostream>
#define ll long long int
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
    node() {
        this->data;
        this->next=NULL;
        this->prev=NULL;
    }
    node(int data){
    
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    node(int data,node *next){
        this->data=data;
        this->next=next;
        this->prev=NULL;
    }
    node(int data,node *next,node *prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
    void print(){
        cout<<data;
        if(next!=NULL){
            cout<<" ";
            next->print();
        }
    }
};
struct linked_list{
    node *head=NULL;
    node *tail=NULL;
    void push_back(int x){
        if(head==NULL){
            head = new node(x);
            tail=head;
        }else if(head!=NULL && head==tail){
            node *second=new node(x);
            tail=second;
            head->next=tail;
        }else{
            node *last=new node(x);
            tail->next=last;
            tail=last;
        }
        
    }
    void push_front(int x){
        if(head==NULL){
            head = new node(x);
            tail=head;
        }else{
            node *n=new node(x);
            n->next=head;
            head=n;

        }
    }
    void pop_back(){
        if(tail==NULL){
            cerr<<"Empty";
            return;
        }
        if(head==tail){
            head=NULL;
            tail=NULL;
            delete  head;
            return;
        }
        node *cur=head;
        while(cur->next->next!=0){
            cur=cur->next;
        }
        tail=cur;
        delete cur->next;
        cur->next=NULL;
    }
    void pop_front(){
        if(head==NULL){
            cerr<<"empty";
        }else if(head==tail){
            head=NULL;
            tail=NULL;
            delete head;
            return;
        }
        node *old_head=head;
        head=head->next;
        old_head=NULL;
        delete old_head;
    }
    void print(){
        if(head==NULL){
            cerr<<"empty";
            return;
        }
        cout<<head->data;
        if(head!=tail){
            cout<<" ";
            head->next->print();
        }

    }
    int print(int i){
        int count=0;
        node *cur=head;
        while(i!=count){
            if(cur==NULL){
                cerr<<"list is NULL in index";
                return 0;
            }
            cur=cur->next;
            count++;
        }
        return cur->data;
    }
    void insert(int x,int i){
        int count=0;
        node *cur=head;
        if(i==0){
            this->push_front(x);
        }
        while(i!=count+1){
            if(cur->next==NULL){
                this->push_back(x);
                return; 
            }
            cur=cur->next;
            count++;
        }
        node *inserting=new node(x);
        if(cur->next==tail){
            cur->next=inserting;
            inserting->next=tail;
            return;
        }
        node *after_inserting_node=cur->next;
        cur->next=inserting;
        inserting->next=after_inserting_node;


    }
};

int main(){
    linked_list *linked_list;
    for(int i=0;i<9;i++){
        linked_list->push_back(i);
    }
    linked_list->print();
}