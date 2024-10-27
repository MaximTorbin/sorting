#include <iostream>
#include <fstream>
#include <algorithm>

// Увеличение размера стека (автоматической памяти),
// чтобы влезло 3 млн интов, 16777216 - размер стека в байтах.
#pragma comment(linker, "/STACK:16777216")
using namespace std;
void sort_count(int* ar,int n)
{
    int max_value = *max_element(ar, ar + n);
    int* ar_counter = new int[max_value + 1]();
    for(int i=0;i<n;i++)
    {
        ar_counter[ar[i]]+=1;
    }
    int k=0;
    for (int i=0;i<=max_value;i++)
    {
        for(int j=0;j<ar_counter[i];j++)
        {
            ar[k]=i;
            k++;
        }
    }
    delete[] ar_counter;
}
int main()
{
	std::ifstream in("03.in");
    std::ofstream out("03.out");

    int mas[3'000'000];
    int n;
    in >> n;
    for(int i=0;i<n;i++)
        in >> mas[i];

    sort_count(mas, n);

    for(int i=0;i<n;i++)
    {
        out << mas[i] << " ";
        cout<<mas[i]<<" ";
    }
}