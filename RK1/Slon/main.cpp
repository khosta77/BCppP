#include <QCoreApplication>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x1 =0; //кординаты слона и пункта назначения
    int y1=0;
    int x2=0;
    int y2=0;
    bool rez=false;// для красивого ответа

    cout << "Start posion (1 - 8):" << endl;
    cout << "x = ";
    cin >> x1;
    cout << "y = ";
    cin >> y1;

    cout << "punct naznachen (1 - 8):" << endl;
    cout << "x = ";
    cin >> x2;
    cout << "y = ";
    cin >> y2;
    cout << "wait.\n";
    if (abs(x1 - x2) == abs(y1 - y2))// проверка на один ход
        cout << "One motion" << endl;
    else {
        for(int i=x1;i>0;i--){ // начинается проверка наличия двух ходов методом ходьбы вверх/вниз по диагонали слоном
            int t = y1;
            if (abs(i - x2) == abs(t - y2))
                rez = true;
            t--;

        }
        for(int i=x1;i<8;i++){
            int t = y1;
            if (abs(i - x2) == abs(t - y2))
                rez = true;
            t++;
        }
        for(int i=x1;i>0;i++){
            int t = y1;
            if (abs(i - x2) == abs(t - y2))
                rez = true;
            t++;
        }
        for(int i=x1;i>0;i--){
            int t = y1;
            if (abs(i - x2) == abs(t - y2))
                rez = true;
            t++;
        }

        if(rez) // вывод тк максимально только два хода может быть то соответсвенно больше двух ходов не может быть
            cout << "Two motion" << endl;
        else
            cout << "No motion" << endl;

   }

    return 0;
}
