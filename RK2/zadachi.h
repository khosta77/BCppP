#ifndef ZADACHI_H
#define ZADACHI_H

#include <QString>

class zadachi{
private:
    int* array;
    const int razmer = 10; // размер массива постоянный
    int sum1, sum2;
    int size_razmer1; // для применения в рекурсивной функции
    int size_razmer2;
    //struct list;
public:
    zadachi();
    void init(int a);
    void triandl90(int N);
    void triandl180(int N);
    void triandl270(int N);
    void convert_two_to_sixteen();
    int fib(int k);
    void print_array();
    void Swap(int* n1, int* n2);
    void Add();
    bool CheckBalance();
    void task_3();
    void task_3_5();
    void on_the_back();
};

#endif // ZADACHI_H
