/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist.h
 * Author: Josh
 *
 * Created on August 20, 2018, 6:14 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class linkedlist {
public:
    linkedlist();
    linkedlist(const linkedlist& orig);
    virtual ~linkedlist();
    void insert(int data);
    void insertAt(int index, int data);
    void remove();
    void removeAt(int index);
    void show();
    void reverse();
    void showAt(int index);
    int getDataAt(int index);
private:
    Node* head;
    Node* tail;
};

#endif /* LINKEDLIST_H */

