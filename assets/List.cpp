//
// Created by Razvan Statescu on 11/03/2018.
//

#include "List.h"

/*
 * Implementation of the List constructor
 */

List::List(int value, int priority) {
    this->value = value;
    this->priority = priority;
    this->next = 0;
}

