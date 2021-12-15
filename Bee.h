//
// Created by Наталья Белова on 11.12.2021.
//

#ifndef CSA_5_BEE_H
#define CSA_5_BEE_H

#include "HoneyPot.h"
#include <condition_variable>
/**
 * Класс описывает пчелу.
 */
class Bee {
private:
    int id_;
    HoneyPot* pot_;
    std::condition_variable &notification_;
public:
    /**
     *  Конструктор класса.
     * @param pot - кувшин с медом, объект класса HoneyPot.
     * @param id - номер пчелы.
     * @param notification - условная переменная, необходимая для уведомления
     * медведя о том, что кувшин заполнен.
     */
    Bee(const HoneyPot *pot, int id, std::condition_variable &notification);
    /**
     * Метод позволяет управлять потоком.
     */
    void run();
};

#endif //CSA_5_BEE_H
