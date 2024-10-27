#include <iostream>
#include <fstream>
#include <algorithm>

// Увеличение размера стека (автоматической памяти),
// чтобы влезло 3 млн интов, 16777216 - размер стека в байтах.
#pragma comment(linker, "/STACK:16777216")
using namespace std;

void sort_Shell(int* ar, int n) {
    int h = 1;
    while (h < n / 3)
        h = 3 * h + 1;
    while (h > 0)
    {
        for (int i = h; i < n; i++)
        {
            int y = ar[i];
            int j = i;

            // Сортировка вставками по текущему шагу h
            while (j >= h && ar[j - h] > y) {
                ar[j] = ar[j - h];
                j -= h;
            }
            ar[j] = y;
        }
        h /= 3; // Уменьшаем шаг
    }
}

int main() {
    std::ifstream in("03.in");
    std::ofstream out("03.out");
    int mas[3'000'000];
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
        in >> mas[i];
    sort_Shell(mas, n);

    for (int i = 0; i < n; i++)
    {
        out << mas[i] << " ";
    }

    return 0;
}