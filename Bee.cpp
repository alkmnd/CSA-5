//
// Created by Наталья Белова on 11.12.2021.
//

#include "Bee.h"
#include <chrono>
#include <condition_variable>

Bee::Bee(const HoneyPot* pot, int id, std::condition_variable& notification) :notification_{notification} {
    id_ = id;
    pot_ = const_cast<HoneyPot*>(pot);
}
void goForHive(int min, int max) {
    std::chrono::milliseconds timer(min + std::rand() % ((max + 1) - min));
    std::this_thread::sleep_for(timer);
}
void Bee::run() {
    while (true) {
        if (pot_->getNumberOfPortions() == pot_->max_number_of_portions) {
            return;
        }
        printf("Пчела под номером %d полетела за глотком меда\n", id_);
        goForHive(1000, 5000);
        if (pot_->changeAmountOfHoney() < pot_->getCapacity() &&
                pot_->getNumberOfPortions() < pot_->max_number_of_portions) {
            printf("Пчела под номером %d добавила в горшок один глоток\n", id_);
        }
        if (pot_->isFull()) {
            pot_->changeNumberOfPortions();
            printf("Пчела под номером %d разбудила медведя!\n", id_);
            notification_.notify_all();
        }
        goForHive(1000, 5000);
    }
}
