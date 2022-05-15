#include "zadachi.h"
#include <iostream>
#include <QString>

using namespace std;

zadachi::zadachi(){
    sum1 = 0;
    sum2 = 0;
    array = NULL;
    array = new int [razmer];
    for (int i = 0; i < razmer; ++i)
        array[i] = rand()%10;
    size_razmer1 = razmer;
    size_razmer2 = razmer;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::triandl90(int N){
    static int n = 0, n1 = ((N-1)/2), n2 = 0;
    if(n <= n1){
        for(int i = n; i < n1; i++){
            cout<<" ";
        }
        n++;
        for(int i = n; i > 0; --i){
            cout<<"*";
        }

        cout << endl;
        triandl90(N);
    }
    else {
        n2++;
        for(int i = 0; i < n2; i++){
            cout << " ";
        }
        for(int i = 0; i < n1; i++){
            cout << "*";
        }
        cout << endl;
        if(n1>0){
            n1--;
            triandl90(N);
        }
    }
}

void zadachi::triandl180(int N) {
    static int n = 0;
    if(N > 0){
        for(int i = 0; i < n; i++){
            cout << " ";
        }
        n++;
        for(int i = 0; i < N; i++){
            cout << "*";
        }
        cout << endl;
        triandl180(N-2);
    }
}

void zadachi::triandl270(int N){
    static int n = 0, n1 = ((N-1)/2+1);
    if(n <= n1){
        for(int i = 0; i < n; i++){
            cout << "*";
        }
        for(int i = 0; i < n1; i++){
            cout << " ";
        }
        n++;
        cout << endl;
        triandl270(N);
    }
    else {
        if(n1 > 0){
            n1--;
            for(int i = 0; i < n1; i++){
                cout << "*";
            }
            cout << endl;
            triandl270(N);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zadachi::fib(int k){
    if(k==1){
        return 1;
    }
    if(k==0){
        return 0;
    }
    return (fib(k-1)+fib(k-2));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::convert_two_to_sixteen(){
    char two[ ] = " ";
    cin >> two;
    string str = string(two);
    QString STR = STR.fromStdString(str);
    int temp = STR.toInt(nullptr, 2);
    QString A = QString::number(temp, 16);
    cout << A.toStdString();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::print_array() {
    for (int i = 0; i < razmer; i++){
        cout << array[i] << "  ";
    }
    cout << endl;
    cout <<"sum1 = " << sum1 << " sum1 = " << sum2 << endl;
}

void zadachi::Swap(int* n1, int* n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::Add() {
    if ((size_razmer1 - 1) % 2 == 0) {
        sum1 += array[size_razmer1 - 1];
    }
    else {
        sum2 += array[size_razmer1 - 1];
    }
    if (size_razmer1 - 1 > 0) {
        size_razmer1--;
        Add();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::task_3() {
    for (int i = 0; i < razmer; i+=2) {
        for (int j = 0; j < razmer - i - 2; ++j) {
            if (array[j] > array[j + 2] && j % 2 > 0) {
                Swap(&array[j], &array[j + 2]);
            }
        }
    }
}
void zadachi::task_3_5(){
    for (int i = 1; i < razmer; i+=2) {
        for (int j = 1; j < razmer - i - 2; ++j) {
            if (array[j] > array[j + 2] && j % 2 == 0) {
                Swap(&array[j], &array[j + 2]);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadachi::on_the_back(){
    if(size_razmer2 > 0){
        size_razmer2--;
        cout << array[size_razmer2] << "  ";
        on_the_back();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool zadachi::CheckBalance() {
    int left = 0;
    int right = razmer - 1;
    int sum_left = array[left];
    int sum_right = array[right];
    while (left != (right - 1)) {
        if (sum_left > sum_right) {
            right--;
            sum_right += array[right];
        }
        else {
            left++;
            sum_left += array[left];
        }
    }
    if (sum_left == sum_right){
        return true;
    }
    else {
        return false;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//struct zadachi::list{
//    int field;
//    struct list *next;
//    struct list *prev;
//};

//void  zadachi::init(int a)  // а- значение первого узла
//{
//  struct list *lst;
//  // выделение памяти под корень списка
//  lst = (struct list*)malloc(sizeof(struct list));
//  lst->field = a;
//  lst->next = NULL; // указатель на следующий узел
//  lst->prev = NULL; // указатель на предыдущий узел
//  //return(lst);
//}






















