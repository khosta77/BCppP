#include <QCoreApplication>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string digits = "0123456789ABCDEFdh";
    string value;
    int from = 0;
    int to = 0;
    int number = 0;

    cout << "Vvedite number(12d or 12Ah): ";
    cin >> value;

    int k = value.length();

    for(int i=0, size = value.length();i < size;i++){ // проверяем откуда куда преобразовать
        if(value[i] == 'd'){
            from = 10;
            to = 16;
        }
        if(value[i] == 'h'){
            to = 10;
            from = 16;
        }
    }

    k--;

    for (int i = 0; i < k; ++i){ // переводим в 10тичную сс без учета определителя сс h или d
        char k = tolower(value[i]);
        number = number*from + ((k>='a') ? k-'a' + 10 : k-'0');
    }

    string result;

    while(number){ // считаем число
        result.push_back(digits[number%to]);
        number /= to;
    }

    for(int i = 0, j = result.length()-1; i < j; ++i, --j){ // записываем его снова в сторку чтобы вывести
        char x = result[i];
        result[i] = result[j];
        result[j] = x;
    }

    if(to == 10)
        cout << "Dec: " << result << "d" << endl;
    if(to == 16)
        cout << "Hex: "<< result << "h" << endl;

    return 0;
}


