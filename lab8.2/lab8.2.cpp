/*Вариант 11
Дана строка, набранная из слов, набранных заглавными буквами и
разделенных пробелами (одним или нескольким).
Вывести строку, содержащую эти же слова,
разделенные одним пробелом и расположенные в алфавитном порядке.
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    string str;
    cout << "Введите слова заглавными буквами" << endl;
    getline(cin, str, '\n');
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (((str[i] < 'A') || (str[i] > 'Z')) && (str[i] != ' ')) {
            cerr << "Ошибка! Не соответствует условию!" << endl;
            return 0;
        }
    }

    char* a = new char[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            a[k] = str[i];
            k++;
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i; j < k - 1; j++) {
            if (a[i] > a[j + 1]) {
                swap(a[i], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << a[i] << ' ';
    }

    delete[] a;
}