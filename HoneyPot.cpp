//
// Created by Наталья Белова on 11.12.2021.
//

#include "HoneyPot.h"
#include <mutex>
#include <thread>

int HoneyPot::getCurrentAmountOfHoney() {
    honey.lock();
    int buffer = current_amount_of_honey_;
    honey.unlock();
    return buffer;
}

int HoneyPot::getCapacity() const {
    return capacity_;
}

void HoneyPot::clearPot() {
    honey.lock();
    current_amount_of_honey_ = 0;
    honey.unlock();
}

int HoneyPot::changeAmountOfHoney() {
   honey.lock();
   int buffer = current_amount_of_honey_;
   if (current_amount_of_honey_ + 1 <= capacity_) {
       current_amount_of_honey_++;
   }
   honey.unlock();
   return buffer;
}

int HoneyPot::getNumberOfPortions() {
    honey.lock();
    int buffer = current_number_of_portions_;
    honey.unlock();
    return buffer;
}

void HoneyPot::changeNumberOfPortions() {
    honey.lock();
    if (current_number_of_portions_ + 1 <= max_number_of_portions) {
        current_number_of_portions_++;
    }
    honey.unlock();
}

HoneyPot::HoneyPot(int capacity, int max_number_of_portions) {
    capacity_ = capacity;
    this->max_number_of_portions = max_number_of_portions;
}

bool HoneyPot::isFull() {
    honey.lock();
    bool buffer = current_amount_of_honey_ == capacity_;
    honey.unlock();
    return buffer;
}
