
#include <iostream>
#include <fstream>
#include <algorithm>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

void heap(int* ar, int i, int n)
{
   int max=i;

    int child=2*i+1;
    if (child<n &&ar[child]>ar[max])
        max=child;
    child++;
    if (child<n &&ar[child]>ar[max])
        max=child;
    if (max!=i)
    {
        swap(ar[max],ar[i]);
        heap(ar,max,n);
    }
}
void sort_heap(int* ar,int n)
{
    for(int i=n/2 -1;i>=0;i--)
        heap(ar,i,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(ar[0],ar[i]);
        heap(ar,0,i);
    }
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

    sort_heap(mas, n);

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}