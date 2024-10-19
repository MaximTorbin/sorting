#include <iostream>
#include <fstream>
#include <algorithm>

// Увеличение размера стека (автоматической памяти),
// чтобы влезло 3 млн интов, 16777216 - размер стека в байтах.
#pragma comment(linker, "/STACK:16777216")
using namespace std;
void sort_a(int* ar,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (ar[i]>ar[j])
                swap(ar[i],ar[j]);
        }
    }
}
int main()
{
	std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int mas[3'000'000];
    int n;
    in >> n;
    for(int i=0;i<n;i++)
        in >> mas[i];

    sort_a(mas, n);

    for(int i=0;i<n;i++)
        out << mas[i] << " ";
}