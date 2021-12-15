//
// Created by Наталья Белова on 11.12.2021.
//

#include "WinnieThePooh.h"
#include <condition_variable>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

void WinnieThePooh::run() {
    while (true) {
        if (pot_->getNumberOfPortions() == pot_->max_number_of_portions) {
            notification_.notify_all();
            return;
        }
        notification_.wait(locker_);
        printf("\n=====================================\n");
        printf("Винни-пух проснулся и выпил весь мед\n");
        printf("=====================================\n\n");
        pot_->clearPot();
        notification_.notify_all();
    }
}

WinnieThePooh::WinnieThePooh(const HoneyPot *pot, std::condition_variable& notification,
                             const std::unique_lock<std::mutex>& locker):
notification_{notification}, pot_{const_cast<HoneyPot*>(pot)}, locker_{
        const_cast<std::unique_lock<std::mutex> &>(locker)}{}
