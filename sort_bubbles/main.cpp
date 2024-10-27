#include <iostream>
#include <fstream>
#include <algorithm>


#pragma comment(linker, "/STACK:16777216")
using namespace std;
void sort_bubbles(int* ar,int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        if (ar[i]>ar[i-1])
            continue;
        j=i-1;
        while ((j>=0) &&(ar[j]>ar[j+1]))
        {
            swap(ar[j],ar[j+1]);
            j--;
        }
    }
}
int main()
{
	std::ifstream in("02.in");
    std::ofstream out("02.out");

    int mas[3'000'000];
    int n;
    in >> n;
    for(int i=0;i<n;i++)
        in >> mas[i];

    sort_bubbles(mas, n);

    for(int i=0;i<n;i++)
    {
        out << mas[i] << " ";
        cout << mas[i] << " ";
    }
}