/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Josh
 *
 * Created on August 20, 2018, 6:14 PM
 */

#include <cstdlib>
#include <iostream>

#include "linkedlist.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {

    linkedlist ll = linkedlist();
    ll.insert(3);
    ll.insert(5);
    ll.insert(9);
    ll.insert(32);
    ll.insert(21);
    ll.insert(19);
    ll.insert(105);
    ll.insert(33);
    ll.insert(32);
    ll.insert(5);
    ll.insert(0);
    ll.insert(10);
    ll.insert(78);
    ll.show();
    cout << endl << endl;
    ll.reverse();
    ll.showAt(5);
    cout << endl << endl;
    ll.remove();
    ll.show();
                    
    cout << endl << endl;
    ll.removeAt(100);
    ll.show();
    
    cout << ll.getDataAt(40) << endl;
    
    return 0;
}

