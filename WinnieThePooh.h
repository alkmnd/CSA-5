//
// Created by Наталья Белова on 11.12.2021.
//

#ifndef CSA_5_WINNIETHEPOOH_H
#define CSA_5_WINNIETHEPOOH_H


#include "HoneyPot.h"
#include <condition_variable>

/**
 * Класс описывает Винни-пуха.
 */
class WinnieThePooh {
public:
    /**
     * Метод для управления потоком.
     */
    void run();
    /**
     * Конструктор класса.
     * @param pot - кувшин с медом.
     * @param notification - условная переменная, необходимая для уведомления
     * @param locker - локер, по которому медведь ожидает уведомления.
     */
    WinnieThePooh(const HoneyPot *pot, std::condition_variable &notification,
                  const std::unique_lock<std::mutex>& locker);
private:
    HoneyPot* pot_;
    std::condition_variable &notification_;
    std::unique_lock<std::mutex> &locker_;
};


#endif //CSA_5_WINNIETHEPOOH_H
