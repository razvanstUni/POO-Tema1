//
// Created by Razvan Statescu on 08/03/2018.
//

#ifndef PROIECT_POO_1_PQUEUE_H
#define PROIECT_POO_1_PQUEUE_H

#endif //PROIECT_POO_1_PQUEUE_H
#include "List.cpp"
#include <iostream>
using namespace std;

class PQueue {
    List *list;
    List *last;
    int elements;

    void freeList();

    public:
        PQueue();
        //~PQueue();
        int empty();
        void insert(int, int);
        List* remove();
        int count();
        int maxValue();
        int maxPriority();
        PQueue& operator+(const PQueue&);
        PQueue operator++(int);
        PQueue operator--(int);
        friend ostream& operator<<(ostream&, const PQueue&);
};






