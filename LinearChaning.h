//
// Created by Omkar Desai on 4/3/2018.
//
#pragma once

#include "LinkedList.h"
template <typename T>
class linearChaining{
private:
    T * arr;
    int size;
    int capacity;
    void grow(){
        T* bkp=arr;
        T* arr=new int[capacity*2];
        capacity=2*capacity;
        for(int i=0;i<capacity;i++)
            arr[i]=-1;
        for(int i=0;i<size;i++)
            if(bkp[i]!=-1)
                rehash(bkp[i]);
    }
    int hash(T key,int n){
        int ret;
        ret=key%n;
        return ret;
    }
    void rehash(T key){
        if(capacity<=2*size)
            grow();
        int pos=hash(key,capacity);
        while(arr[pos]!= -1){
            pos++;
            if(pos>=capacity)
                pos=0;
        }
        arr[pos]=key;
    }
public:
    linearChaining(int initSize):size(1),capacity(initSize){
        arr=new T[initSize*2];
        for(int i=0;i<capacity;i++)
            arr[i]=-1;
    }
    void add(T key){
        if(capacity<=2*size)
            grow();
        int pos=hash(key,capacity);

        while(arr[pos]!= -1){
            pos++;
            if(pos>=capacity)
                pos=0;
        }
        arr[pos]=key;
        size++;
    }
    int find(T key){
        int pos=hash(key,capacity);
        while(arr[pos]!=-1){
            if(arr[pos]==key)
                return key;
            pos++;
            if(pos>=capacity)
                pos=0;
        }
        return -1;
    }

};