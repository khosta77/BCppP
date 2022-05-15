#include <QCoreApplication>
#include <qdebug.h>
#include <QFile>
#include <iostream>
#include <ctime>

using namespace std;

void bubblesort(int* Kucha,int size);

int main(){
    QFile savefile("D:\\C++ Semerenko\\RK1\\Kucha\\save rezult.txt");//для записи в файл
    QTextStream save(&savefile);
    savefile.open(QIODevice::WriteOnly);
    srand(time(NULL)); // для случйного числа

    int size = 10;// раазмер массива
    int sizekucha1 = 0; // размер кучи 1
    int sizekucha2 = 0; // размер кучи 2
    int X=0; // X и Y для дополнительных значений
    int Y=0;
    int ControlSize =0; // контроль длины если размер массива равен одномы то не красиво будет по этому надо кое что уточнять
    int SUMMAKucha = 0; // половина кучи, не коректно записал
    int SummaKucha=0; // сумма Kucha

//    size = rand()%100; // получение массива случайной длины

//    if(size == 0){ // если равно ноль то прекращаем прорамму
//        qDebug() << "error 404";
//        return 0;
//    }

    save << "Razmer massiva = " << size << "\n";

    save << "massiv: ";

    int Kucha[] = {65, 48, 19, 11, 11, 9, 9, 7, 5, 4}; // заполнение массивов
    int* kucha0 = new int[size];
    int* kucha1 = new int[size];
    int* kucha2 = new int[size];

//    for(int i=0;i<size;i++){ // инициализция кучи
//        Kucha[i]=rand()%300;// если больше 300 то большоей разбросс значений
//        if (Kucha[i]==0) // может выпасть ноль
//            Kucha[i]=10;
//        save << Kucha[i] << "  "; // вывод значений
//        ////save << i << ") " << Kucha[i] << "\n";
//    }

    bubblesort(Kucha,size); // сортируем массив чтобы после можно было коректно разделить на кучи

    save << "\notsortirovan massiv: ";
    int size0 = 0;
    for(int i=size-1;i>0;i--){ // вывод сорированного массива
        SummaKucha += Kucha[i];
        ////save << Kucha[i] << "  ";
        kucha0[size0] = Kucha[i];

        save << kucha0[size0] << "  ";
        size0++;
        ////save << i << ") " << Kucha[i] << "\n";
    }

    save << "\n";
    save << "Summa mass Kuchi = " << SummaKucha << "\n";
    save << "\n";

    SUMMAKucha = SummaKucha/2; // сумма кучи деленная на два чтобы было проще найти половину

//    if(size>1) // как писал выше если размер массива равен 1 то есть проблемчики
//       ControlSize = size;
//    else
//       ControlSize = size-1;

//    for(int i = size-1; i>0;i--){

//    }
//    for(;sizekucha1<size;sizekucha1++){
//        X += Kucha[sizekucha1]; // начинаем набирать сумму
//        if(( X >= SUMMAKucha ) && ( sizekucha1 < ControlSize )){ // проверям перешлили мы половину отфильрованого массива или нет а так же дошлили мы до конца массива ну к примеру масса камней 10 20 25 1000, ну никак не разделить пополам)
//            X -= Kucha[sizekucha1]; // там это выходит одна лишня операция
//            break; // выход
//        }
//        kucha1[sizekucha1] = Kucha[sizekucha1];
//    }

    kucha1[0]=kucha0[0];
    for(int i = 0; i<size0;i++){
        if()
    }

//    sizekucha2 = sizekucha1;

//    kucha1[0]=kucha0[0];
//    for(int i = sizekucha2 ;i<size ;i++){ // записываем вторую кучу и ее сумму
//        kucha2[i]=Kucha[i];
//        Y +=  kucha2[i];
//    }


    // выводим массив сумму и т д
    save << "SummaKucha1: " << X << "; sizekucha1: " << sizekucha1 << "\n";
    for(int i=0 ; i < sizekucha1 ;i++){
        save << kucha1[i] << "  ";
        ////save << i << ") " << Kucha[i] << "\n";
    }
    save << "\n";
    save << "SummaKucha2: " << Y << "; sizekucha1: " << size - sizekucha2 << "\n";
    for(int i = sizekucha2 ;i<size ;i++){
        save << kucha2[i] << "  ";
        ////save << i << ") " << Kucha[i] << "\n";
    }

    delete [] kucha2; // удаление данных
    delete [] kucha1;
    delete [] kucha0;
   // delete [] Kucha;
    qDebug() << "end"; // чтоб зпустить и увидеть когда закончится

    savefile.close();
    return 0;
}

void bubblesort(int* Kucha,int size){ // сортировка пузырьком из ДЗ1 взял
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Kucha[j] > Kucha[j + 1]) {
                temp = Kucha[j];
                Kucha[j] = Kucha[j + 1];
                Kucha[j + 1] = temp;
            }
        }
    }
}
