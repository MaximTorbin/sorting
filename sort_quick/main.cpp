
#include <iostream>
#include <fstream>
#include <algorithm>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

void sort_quick(int* ar, int L, int R) {
    if (L >=R)
        return;

    int m = ar[(L + R) / 2];
    int i = L;
    int j = R;

    while (i <= j) {
        while (ar[i] < m)
            i++;
        while (ar[j] > m)
            j--;
        if (i <= j) {
            swap(ar[i], ar[j]);
            i++; 
            j--; 
        }
    }

    sort_quick(ar, L, j);
    sort_quick(ar, i, R);
}

int main() {
    std::ifstream in("03.in");
    std::ofstream out("03.out");
    int n;
    in >> n;

    int mas[3'000'000];

    for (int i = 0; i < n; i++) {
        in >> mas[i];
    }

    sort_quick(mas, 0, n - 1);

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}