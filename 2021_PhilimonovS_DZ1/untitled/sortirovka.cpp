#include "sortirovka.h"
#include <QCoreApplication>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QTime>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <utility>
#include <ctime>
#include <list>

using namespace std;

//==========================КОНСТРУКТОР И ДЕСТРУКТОР======================================================================//
sortirovka::sortirovka(){
       qDebug() << "The start\n";
       QFile file1("D:\\pyzirek.txt"); //1
       QTextStream out1(&file1);
       file1.open(QIODevice::WriteOnly);
       qDebug() << " pyzirek \n"; //1
       for(int X = 0;X<=N;X=X+1000){
           int a = pyzirek(X);
           out1 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file1.close();
       qDebug() << "\n";
       QFile file2("D:\\vstavka.txt"); //2
       QTextStream out2(&file2);
       file2.open(QIODevice::WriteOnly);
       qDebug() << " vstavka\n"; //2
       for(int X = 0;X<=N;X=X+1000){
           int a = vstavka(X);
           out2 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file2.close();
       qDebug() << "\n";
       QFile file3("D:\\qsortRecursive.txt"); //3
       QTextStream out3(&file3);
       file3.open(QIODevice::WriteOnly);
       qDebug() << " qsortRecursive\n"; //3
       for(int X = 0;X<=N;X=X+1000){
           int a = vstqsortRecursiveavka(N);
           out3 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file3.close();
       qDebug() << "\n";
       QFile file4("D:\\vibor.txt"); //4
       QTextStream out4(&file4);
       file4.open(QIODevice::WriteOnly);
       qDebug()<< " vibor\n"; //4
       for(int X = 0;X<=N;X=X+1000){
           int a = vibor(X);
           out4 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file4.close();
       qDebug() << "\n";
       QFile file5("D:\\sorto.txt"); //5
       QTextStream out5(&file5);
       file5.open(QIODevice::WriteOnly);
       qDebug() << " sorto\n"; //5
       for(int X = 0;X<=N;X=X+1000){
           int a = sorto(X);
           out5 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file5.close();
       qDebug() << "\n";
       QFile file6("D:\\gnome.txt"); //6
       QTextStream out6(&file6);
       file6.open(QIODevice::WriteOnly);
       qDebug() << " gnome_sort\n"; //6
       for(int X = 0;X<=N;X=X+1000){
           int a = Gnome_sort(X);
           out6 << a << " \n";
           cout << "=";
           if(a>1000)
               break;
       }
       file6.close();
       qDebug() << "\n";
}
sortirovka::~sortirovka(){
    cout << "The end.";
}
//===============================ПУЗЫРЬКОВАЯ СОРТИРОВКА(1)===============================================================//
int sortirovka::pyzirek(int N){
    QFile file1("D:\\test.txt");
    QTime Time;
    Time.start();

    double* digitals = new double[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;

    int start = Time.elapsed();

    for(int i = 1; i < N; ++i)
    {
        for(int r = 0; r < N-i; r++)
        {
            if(digitals[r] < digitals[r+1])
            {
                // Обмен местами
                int temp = digitals[r];
                digitals[r] = digitals[r+1];
                digitals[r+1] = temp;
            }
        }
    }

    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);
    QTextStream writeStream(&file1);

    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }
    file1.close();
    delete[] digitals;
    int a = stop - start;

    return a;
}
//===========================СОРТИРОВКА ВСТАВКАМИ(2)=====================================================================//
int sortirovka::vstavka(int N){
    QFile file1("D:\\test.txt");


    QTime Time;

    Time.start();
    double* digitals = new double[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;


    int start = Time.elapsed();

    int key=0;
    int temp=0;
    for (int i=0; i<N-1; i++)
    {
        key=i+1;
        temp=digitals[key];
        for (int j=i+1; j>0; j--)
        {
            if (temp<digitals[j-1])
            {
                digitals[j]=digitals[j-1];
                key=j-1;
            }
        }
        digitals[key]=temp;
    }

    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);

    QTextStream writeStream(&file1);


    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }

    file1.close();
    delete[] digitals;
    int a = stop - start;

    return a;
}
//===========================БЫСТРАЯ СОРТИРОВКА(3)=====================================================================//
int sortirovka::vstqsortRecursiveavka(int N){
    QFile file1("D:\\test.txt");


    QTime Time;

    Time.start();

    int* digitals = new int[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;

    int start = Time.elapsed();

    qsortRecursive(digitals,N);

    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);

    QTextStream writeStream(&file1);


    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }

    file1.close();
    delete[] digitals;
    int a = stop - start;

    return a;
}
void sortirovka::qsortRecursive(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];
    do {
        while(mas[i] < mid)
            i++;
        while(mas[j] > mid)
            j--;
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}
//=============================СОРТИРОВКА ВЫБОРОМ(4)===================================================================//
int sortirovka::vibor(int N){
    QFile file1("D:\\test.txt");


    QTime Time;

    Time.start();

    int* digitals = new int[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;

    int start = Time.elapsed();

    for (int i = 0; i < N - 1; ++i){
        int smallestIndex = i;
        for (int currentIndex = i + 1; currentIndex < N; ++currentIndex){
            if (digitals[currentIndex] < digitals[smallestIndex])
                smallestIndex = currentIndex;
        }
        std::swap(digitals[i], digitals[smallestIndex]);
    }

    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);

    QTextStream writeStream(&file1);


    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }

    file1.close();
    delete[] digitals;
    int a = stop - start;
    stop=0;
    start =0;

    return a;
}
//===============================СОРТИРОВКА ПРОСТАЯ(5)=================================================================//
int sortirovka::sorto(int N){
    QFile file1("D:\\test.txt");


    QTime Time;

    Time.start();

    int* digitals = new int[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;

    int start = Time.elapsed();

    int tmp;
    for (int i=0;i<N-1;++i) {
        for (int j=i+1; j<N;++j) {
            if (digitals[j]/10<digitals[i]/10) {
                tmp=digitals[i];
                digitals[i]=digitals[j];
                digitals[j]=tmp;
            }
        }
    }

    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);

    QTextStream writeStream(&file1);


    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }

    file1.close();
    delete[] digitals;
    int a = stop - start;

    return a;
}
//================================ГНОМЬЯ СОРТИРОВКА(6)================================================================//
int sortirovka::Gnome_sort(int N){
    QFile file1("D:\\test.txt");


    QTime Time;

    Time.start();

    int* digitals = new int[N];
    memset(digitals,1,N);
    srand(time(NULL));
    for(int i=0;i<N;i++)
        digitals[i]=rand()%1000;

    int start = Time.elapsed();

    int i = 0;
    while (i < N) {
    if (i == 0 || digitals[i-1] <= digitals[i])
        i++;
    else {
        int tmp = digitals[i];
        digitals[i] = digitals[i-1];
        digitals[--i] = tmp;}
    }


    int stop = Time.elapsed();

    file1.open(QIODevice::WriteOnly);

    QTextStream writeStream(&file1);


    for (int i = 0; i < N; i++) {
        writeStream <<i<<") "<< digitals[i] << " \n";
    }

    file1.close();

    delete[] digitals;

    int a = stop - start;

    return a;
}



