/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist.cpp
 * Author: Josh
 * 
 * Created on August 20, 2018, 6:14 PM
 */

#include "linkedlist.h"
#include <iostream>

using namespace std;

linkedlist::linkedlist() {
    this->head = nullptr;
    this->tail = nullptr;
}

linkedlist::linkedlist(const linkedlist& orig) {
}

linkedlist::~linkedlist() {
}

void linkedlist::insert(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    n->prev = nullptr;
    if (this->head == nullptr) {
        this->head = n;
        this->tail = this->head;
    } else {
        this->tail->next = n;
        this->tail->next->prev = this->tail;
        this->tail = this->tail->next;
    }
}

void linkedlist::insertAt(int index, int data) {
    Node* current = new Node;
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    n->prev = nullptr;

    current = this->head;

    int count = 0;
    while (current != nullptr) {

        if (count == index) {
            break;
        }
        current = current->next;
        count++;
    }

    if (current->next != nullptr && current->prev != nullptr) {
        n->next = current;
        current->prev->next = n;
        n->prev = current->prev;
        current->prev = n;
    } else if (current->prev == nullptr && current->next != nullptr) {
        n->next = this->head;
        this->head->prev = n;
        this->head = n;
    } else if (current->prev != nullptr && current->next == nullptr) {
        insert(data);
    } else {
        n->next = current;
        current->prev = n;
        this->head = n;
        this->tail = current;
    }
}

void linkedlist::show() {
    Node* current = new Node;
    current = this->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

}

void linkedlist::reverse() {
    Node* current = new Node;
    current = this->tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

void linkedlist::showAt(int index) {
    Node* current = new Node;
    current = this->head;
    int count = 0;
    while (current != nullptr) {
        if (count == index) {
            cout << current->data << endl;
            break;
        }
        count++;
        current = current->next;
    }
}

void linkedlist::remove() {
    if (this->head != nullptr && this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        this->tail->prev->next = nullptr;
        this->tail = this->tail->prev;
    }
}

void linkedlist::removeAt(int index) {
    Node* current = new Node;
    current = this->head;
    int count = 0;
    while (current != nullptr) {
        if (count == index) {
            break;
        }
        current = current->next;
        count++;
    }
    
    if(count != index){
        remove();
        return;
    }

    if (count == index) {
        if (current->next != nullptr && current->prev != nullptr) {
            //Case 1: Removing from the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = nullptr;

        } else if (current->next == nullptr && current->prev != nullptr) {
            //Case 2: Removing the tail but the tail is not equal to the head.
            current->prev->next = nullptr;
            this->tail = current->prev;
            current = nullptr;

        } else if (current->next != nullptr && current->prev == nullptr) {
            //Case 3: Removing the head but head isn't the only node.
            current->next->prev == nullptr;
            this->head = current->next;
            current = nullptr;

        } else {
            //Case 4: Removing the head itself;
            this->head = nullptr;
            this->tail = nullptr;
            current = nullptr;

        }
    }
}

int linkedlist::getDataAt(int index) {
    Node* current = new Node;
    current = this->head;
    int count = 0;
    while (current != nullptr) {

        if (count == index) {
            break;
        }
        current = current->next;
        count++;
    }

    if (count != index) {
        return this->tail->data;
    }

    return current->data;
}