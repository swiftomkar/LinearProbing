//
// Created by Omkar Desai on 4/3/2018.
//
#pragma once
#include <iostream>

class linkedlist{
private:
    class node{
    public:
        int data;
        node* next;
        node(int data, node* next):data(data),next(next){}
    };
    node* head;
public:
    linkedlist():head(nullptr){}
    void addfront(int v){
        node* temp=new node(v,head);
        head=temp;
    }
    void addback(int v){
        if(head== nullptr)
            addfront(v);
        else {
            node *temp = new node(v, nullptr);
            node *i;
            for (i = head; i->next != nullptr; i = i->next);
            i->next = temp;
        }
    }
    int removefront(){
        if(head== nullptr)
            return NULL;
        node* rem=head;
        int data=rem->data;
        head=rem->next;
        delete rem;
        return data;
    }
    void removeback(){
        if(head== nullptr)
            return;
        node* i;
        for(i=head;i->next->next!= nullptr;i=i->next);
        node* rem=i->next;
        i->next= nullptr;
        delete rem;
    }
    friend std::ostream& operator <<(std::ostream& s, const linkedlist4& l){
        for (node* p = l.head; p != nullptr; p = p->next)
            s << p->data << ' ';
        return s;
    }
};