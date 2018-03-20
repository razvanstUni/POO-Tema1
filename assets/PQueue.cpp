//
// Created by Razvan Statescu on 11/03/2018.
//

#include "PQueue.h"

/*
 * Implementation of the List class
 */


//Class constructor without params
PQueue::PQueue() {
    this->elements = 0;
}

//Class constructor with params
PQueue::PQueue(int count, int value, int priority) {
    this->elements=0;
    int i;
    for(i=1;i<=count;i++) {
        this->insert(value, priority);
    }
}

//Copy constructor
PQueue::PQueue(PQueue& list) {
    this->elements = list.elements;
    List *q = list.list;
    while(q) {
        this->insert(q->value, q->priority);
        q = q->next;
    }
}

//Class destructor, where the memory gets freed
PQueue::~PQueue() {
    List *list1 = this->list;
    List *list2 = this->list;
    while(list2) {
        //cout << "des";
        list1 = list1->next;
        //cout << list2;
        delete list2;
        list2 = list1;
    }
}

//Override of the "+" operator
PQueue& PQueue::operator+(const PQueue &l) {
    List *list = l.list;
    PQueue *newList = new PQueue;
    while(list) {
        newList->insert(list->value, list->priority); newList->elements++;
        list = list->next;
    }
    list = this->list;
    while(list) {
        newList->insert(list->value, list->priority); newList->elements++;
        list = list->next;
    }
    return *newList;
}

//Override of the "=" operator
PQueue& PQueue::operator=(const PQueue &l) {
    List *list = l.list;
    PQueue *newList = new PQueue;
    while(list) {
        newList->insert(list->value, list->priority);
        list = list->next;
    }
    this->list = newList->list;
    this->elements = l.elements;
    return *newList;
}

//Override of the "++" operator
PQueue& PQueue::operator++(int) {
    List *list = this->list;
    while(list) {
        list->priority++;
        list = list->next;
    }
    return *this;
}

//Override of the "--" operator
PQueue& PQueue::operator--(int) {
    List *list = this->list;
    while(list) {
        list->priority--;
        list = list->next;
    }
    this->freeList();
    return *this;
}

//Overrider of the "<<" operator
ostream& operator<<(ostream& os, const PQueue& list)
{
    List *q = list.list;
    while(q) {
        os << q->value << "(" << q->priority << ") ";
        q = q->next;
    }
    return os;
}

//Overrider of the ">>" operator
istream& operator>>(istream& is, PQueue& list)
{
    List *list1 = list.list;
    List *list2 = list.list;
    while(list2) {
        list1 = list1->next;
        delete list2;
        list2 = list1;
    }
    list.elements = 0;

    int count,i,value,priority;
    is >> count;
    for(i=1;i<=count;i++) {
        is >> value >> priority;
        list.insert(value, priority);
    }
    return is;
}

//Rmeove elements with negative priority from the list
void PQueue::freeList() {
    List *q = list;
    while(q->priority < 0) q = this->remove();
    while(q->next) {
        if(q->next->priority < 0)
            q->next = q->next->next;
        q = q->next;
    }
}

//Get the number of elements in the list
int PQueue::count() {
    return this->elements;
}

//Check if the list is empty
int PQueue::empty() {
    if(elements == 0) return 1;
    return 0;
}

//Insert an element into the list
void PQueue::insert(int x, int priority) {
    if(this->empty()) { //If the list is empty
        this->list = new List(x, priority);
        last = list;
    } else {
        List *newList;
        List *q = list;
        newList = new List(x, priority);
        if(priority <= this->list->priority) { //If the element is added at the beginning
            newList->next = list;
            list = newList;
        } else if( priority >= last->priority ) { //If the element is added at the end
            last->next = newList;
            last = newList;
        } else { //If the element is added in the middle
            while(q->next) {
                if( q->next->priority > priority ) {
                    newList->next = q->next;
                    q->next = newList;
                    break;
                }
                q = q->next;
            }
        }
    }

    this->elements++;
}

//Remove an element from the list
List* PQueue::remove() {
    List *q = this->list;
    this->list = this->list->next;
    delete q;
    return this->list;
}

//Get the element with the highest value
int PQueue::maxValue() {
    List *list = this->list;
    int max = list->value; list = list->next;
    while(list) {
        if(max < list->value) max = list->value;
        list = list->next;
    }
    return max;
}

//Get the value of the highest priority
int PQueue::maxPriority() {
    List *list = this->list;
    int max = list->priority; list = list->next;
    while(list) {
        if(max < list->priority) max = list->priority;
        list = list->next;
    }
    return max;
}