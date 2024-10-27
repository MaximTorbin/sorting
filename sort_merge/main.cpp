#include <iostream>
#include <fstream>
#include <algorithm>


#pragma comment(linker, "/STACK:16777216")
using namespace std;

int sorted_arr[3'000'000];
void sort_merge(int a,int b,int* ar)
{
    if(a>=b)
        return;
    int m=(a+b)/2;
    sort_merge(a,m,ar);
    sort_merge(m+1,b,ar);
    int i=a,j=m+1;
    for (int k = a; k <= b; k++)
    {
        if (i > m)
        {
            sorted_arr[k] = ar[j];
            j++;
        }
        else if (j > b)
        {
            sorted_arr[k] = ar[i];
            i++;
        }
        else if (ar[i] <= ar[j])
        {
            sorted_arr[k] = ar[i];
            i++;
        }
        else
        {
            sorted_arr[k] = ar[j];
            j++;
        }
    }
    for(int i=a;i<=b;i++)
    {
        ar[i]=sorted_arr[i];
    }
}
int main()
{
	std::ifstream in("05.in");
    std::ofstream out("05.out");

    int mas[3'000'000];
    int n;
    in >> n;
    for(int i=0;i<n;i++)
        in >> mas[i];
    sort_merge(0,n,mas);

    for(int i=0;i<n;i++)
    {
        out << sorted_arr[i] << " ";
    }
}