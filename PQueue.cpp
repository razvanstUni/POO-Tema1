//
// Created by Razvan Statescu on 11/03/2018.
//

#include "PQueue.h"

PQueue::PQueue() {
    //this->list =(List *)malloc( sizeof(List) );
    this->elements = 0;
}

/*PQueue::~PQueue() {
    List *list1 = this->list;
    List *list2 = this->list;
    while(list1) {
        list1 = list1->next;
        delete list2;
        list2 = list1;
    }
}*/

PQueue& PQueue::operator+(const PQueue &l) {
    List *list = l.list;
    PQueue newL;
    while(list) {
        newL.insert(list->value, list->priority);
        list = list->next;
    }
    list = this->list;
    while(list) {
        newL.insert(list->value, list->priority);
        list = list->next;
    }
    return newL;
}

PQueue PQueue::operator++(int) {
    List *list = this->list;
    while(list) {
        list->priority++;
        list = list->next;
    }
    return *this;
}

PQueue PQueue::operator--(int) {
    List *list = this->list;
    while(list) {
        list->priority--;
        list = list->next;
    }
    this->freeList();
    return *this;
}

ostream& operator<<(ostream& os, const PQueue& list)
{
    List *q = list.list;
    os << "\nList: ";
    while(q) {
        os << q->value << "(" << q->priority << ") ";
        q = q->next;
    }
    return os;
}

void PQueue::freeList() {
    List *q = list;
    while(q->priority < 0) q = this->remove();
    while(q->next) {
        if(q->next->priority < 0)
            q->next = q->next->next;
        q = q->next;
    }
}

int PQueue::count() {
    return this->elements;
}

int PQueue::empty() {
    if(elements) return 0;
    else return 1;
}

void PQueue::insert(int x, int priority) {

    if(this->empty()) {
        this->list = new List;
        this->list->init(x, priority);
        last = list;
    } else {
        List *newL;
        List *q = list;
        newL = new List;
        newL->init(x, priority);
        if(priority < list->priority) {
            newL->next = list;
            list = newL;
        } else if( priority > last->priority ) {
            last->next = newL;
            last = newL;
        } else {
            while(q->next) {
                if( q->next->priority > priority ) {
                    newL->next = q->next;
                    q->next = newL;
                    break;
                }
                q = q->next;
            }
        }
    }

    this->elements++;
}

List* PQueue::remove() {
    List *q = this->list;
    this->list = this->list->next;
    delete q;
    return this->list;
}

int PQueue::maxValue() {
    List *list = this->list;
    int max = list->value; list = list->next;
    while(list) {
        if(max < list->value) max = list->value;
        list = list->next;
    }
    return max;
}

int PQueue::maxPriority() {
    List *list = this->list;
    int max = list->priority; list = list->next;
    while(list) {
        if(max < list->priority) max = list->priority;
        list = list->next;
    }
    return max;
}