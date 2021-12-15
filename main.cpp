#include <iostream>
#include <thread>
#include <vector>
#include "Bee.h"
#include "WinnieThePooh.h"
#include <condition_variable>

std::vector <std::thread> threads;
std::vector<Bee> bees;
std::mutex winnie_and_bees;
std::unique_lock<std::mutex> locker(winnie_and_bees);

// Проверка входных данных.
bool checkData(int first_number, int second_number, int third_number) {
    if (first_number <= 0 || second_number <= 0 || third_number <= 0)
    {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int number_of_bees = 3, number_of_drinks = 3, max_number_of_portions = 5;
    std::condition_variable notification;
    try {
        if (argc != 4) {
            throw -1;
        }
        if (!checkData(std::stoi(argv[1]),
                       std::stoi(argv[2]), std::stoi(argv[3]))) {
            throw -1;
        }
        number_of_bees = std::stoi(argv[1]);
        number_of_drinks = std::stoi(argv[2]);
        max_number_of_portions = std::stoi(argv[3]);
        printf("Значения командной строки были успешно считаны!\n");
    } catch(...) {
        printf("Значения командной строки некорректны!\n");
        printf("Программа будет использовать значения по умолчанию\n\n");
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    printf("\n+----------------------------------------------------+\n");
    printf("                Количество пчел:\t%d\n", number_of_bees);
    printf("         Вместимость горшка с медом:\t%d\n", number_of_drinks);
    printf("   Максимальное число заполнений горшка с медом:\t%d\n", max_number_of_portions);
    printf("+----------------------------------------------------+\n\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    threads.reserve(number_of_bees);
    bees.reserve(number_of_bees);
    HoneyPot pot(number_of_drinks, max_number_of_portions);
    WinnieThePooh winnie_the_pooh(&pot, notification, locker);
    for (int i = 0; i < number_of_bees; ++i) {
        bees.emplace_back(&pot, i + 1, notification);
        threads.emplace_back(&Bee::run, bees[i]);
    }
    std::thread winnie_thread(&WinnieThePooh::run, winnie_the_pooh);
    winnie_thread.join();
    for (int i = 0; i < number_of_bees; ++i) {
        threads[i].join();
    }
    printf("\n+----------------------------------------------------+\n");
    printf("| Горшок был заполнен максимальное количество раз!   |\n");
    printf("|              Программа завершает работу!           |\n");
    printf("+----------------------------------------------------+\n");
    return 0;
}
