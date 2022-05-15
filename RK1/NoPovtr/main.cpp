#include <QCoreApplication>
#include <iostream>
#include <qdebug.h>
#include <ctime>
#include <QFile>

using namespace std;

int main(){
    QFile savefile("D:\\C++ Semerenko\\RK1\\NoPovtr\\RezultSort.txt");//для записи в файл
    QTextStream save(&savefile);
    savefile.open(QIODevice::WriteOnly);
    srand(time(NULL));

    int size = 0; // размер массива
    int SummaMass =0; // сумма чисел массива

    size = rand()%100;
    if(size == 0){ // если равно ноль то прекращаем прорамму
        qDebug() << "error 404";
        return 0;
    }

    int* mass = new int[size];

    save << "size: " << size << "\n\n";

    save << "mass: ";
    for (int i = 0; i < size; i++) {
        mass[i] = rand() % 3; // генерируем массив и получаем сумму массива
        SummaMass += mass[i];
        save << mass[i] << " ";
    }

    save << "\n\n";
    save << "SummaMass: " << SummaMass << "\n";
    save << "\n";
    save << "MASS: ";

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(mass[i]==mass[j]){ // если в массиве есть повторяющиеся число, то просто они становятся равны сумме массива предварительно увеличенной на 1, повторные числа исключены
                for(int g = 0; g < size; g++){
                    mass[j]+=mass[g];
                }
                //SummaMass++;
                //mass[j] = SummaMass;
            }
        }
    }


    for (int i = 0; i < size; i++) { // вывод массива
        save << mass[i] << " ";
    }

    qDebug() << "The end";
    delete [] mass;
    savefile.close();
    return 0;
}


