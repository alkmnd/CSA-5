//
// Created by Наталья Белова on 11.12.2021.
//

#ifndef CSA_5_HONEYPOT_H
#define CSA_5_HONEYPOT_H

#include <mutex>
#include <thread>

/**
 * Класс описывет кувшин с медом.
 */
class HoneyPot {
private:
    int current_amount_of_honey_{};
    int capacity_;
    int current_number_of_portions_{};
    std::mutex honey;
public:
    /**
     * Конструктор класса.
     * @param capacity - максимальная вместимость кувшина.
     * @param max_number_of_portions - максимальное количество заполнений кувшина.
     */
    HoneyPot(int capacity, int max_number_of_portions);
    /**
     * Метод позволяет получить текущее количество глотков в кувшине.
     * @return возвращает значение приватного поля current_amount_of_honey_.
     */
    int getCurrentAmountOfHoney();

    /**
     * Метод для получения вместимости кувшина.
     * @return возвращает значение приватного поля capacity_.
     */
    int getCapacity() const;

    /**
     * Метод очищает кувшин, то есть приравнивает значение поля current_amount_of_honey_
     * к нулю.
     */
    void clearPot();

    /**
     * Метод для изменения количества глотков в кувшине.
     * @return возвращает старое значение поля current_amount_of_honey_.
     */
    int changeAmountOfHoney();

    /**
     * Метод для получения текущего количества заполнений кувшина.
     * @return возвращает значение поля current_number_of_portions_.
     */
    int getNumberOfPortions();
    /**
     * Увеличивает значение количества заполнений кувшина.
     */
    void changeNumberOfPortions();
    /**
     * Максимальное количество заполнений кувшина.
     */
    int max_number_of_portions;
    /**
     * Показывает заполнен ли кувшин.
     * @return Возвращает значение равентсва текущего количества
     * глотков и вместимости кувшина.
     */
    bool isFull();
};


#endif //CSA_5_HONEYPOT_H
