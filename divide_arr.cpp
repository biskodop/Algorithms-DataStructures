#include <iostream>
#include <time.h>

int PolishFlag(int* x, int n,int gr);
void FrenchFlag(int* x, int n,int gr1,int gr2, int &ind1,int &ind2);
void array_rand_num(int* tab, int tab_size, int min, int max);
void show_array_int(int* tab, int n);
// int Median(int* tab, int n);

using namespace std;

int main()
{
    int n, a;
    cout << "Wpisz rozmiar tablicy: "<< endl;
    cin >> n;
    int tab[n];
    array_rand_num(tab, n, 1, 10);
    show_array_int(tab, n);
    string menu = "Menu:\n"
                  "1. 2 subarrays\n"
                  "2. 3 subarrays\n"
    ;
    cout << menu << endl;
    cin >> a;
    switch(a){
        case 1:
            {
                int gr, x;
                cout << "Set border: " << endl;
                cin >> gr;
                x = PolishFlag(tab, n, gr);
                cout << "First subset"<<endl;
                for(int i = 0; i < x; i++)
                {
                    cout << tab[i] <<" ";
                }
                cout <<"\nSecond subset"<<endl;
                for(int i = x; i < n; i++)
                {
                    cout << tab[i] <<" ";
                }
                break;

            }
        case 2:
            {
                int gr1, gr2, ind1, ind2;
                cout << "Set border 1: " << endl;
                cin >> gr1;
                cout << "Set border 2: " << endl;
                cin >> gr2;
                FrenchFlag(tab, n, gr1, gr2, ind1, ind2);
                cout<<"Index1:"<< ind1 <<endl;
                cout<<"Index2:"<< ind2 <<endl;
                cout << "First subset"<<endl;
                for(int i = 0; i <= ind1; i++)
                {
                    cout << tab[i] <<" ";
                }
                cout << "\nSecond subset"<<endl;
                for(int i = ind1 + 1; i < ind2; i++)
                {
                    cout << tab[i] <<" ";
                }
                cout << "\nThird subset"<<endl;
                for(int i = ind2; i < n; i++)
                {
                    cout << tab[i] <<" ";
                }
                break;
            }

    }
    return 0;
}
int PolishFlag(int* x, int n,int gr)
{
    //Divide array into two subsets and return index "i" as a border
    int i = 0, j = n-1;
    while(i < j){
        while(i < j && x[i] <= gr){
            i++;
        }
        while(i < j && x[j] > gr){
            j--;
        }
        if(i < j){
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if(x[i]<= gr){
        return i++;
    }
    else{
        return i;
    }

}

void FrenchFlag(int* x, int n, int gr1, int gr2, int &ind1,int &ind2)
{
    //Divide array into three subsets, ind1 and ind2 are borders
    int i = -1, j = 0, k = n;
    while(j < k)
    {
        if(x[j] < gr1)
        {
            i++;
            swap(x[i], x[j]);
            j++;
            cout<<"Swap"<<endl;
        }
        else if(x[j] > gr2)
        {
            k--;
            swap(x[k], x[j]);
        }
        else
        {
            j++;
        }
    }
    ind1 = i;
    ind2 = k;

}

void array_rand_num(int *tab, int tab_size, int min_val, int max_val)
{
    srand(time(NULL));
    for(int i = 0; i < tab_size; i++){
        tab[i] = min_val + rand()%(max_val - min_val + 1);
    }
}

void show_array_int(int *tab, int n)
{
    for(int i = 0; i < n; i++){
        cout << tab[i] <<" ";
    }
    cout<<""<<endl;
}
// int Median(int* tab, int n)
// {
//     int left = 0;
//     int right = n - 1;
//     int border = 0;
//     while(border != n/2)
//     {
//         border = left + PolishFlag(tab + left, right - left, tab[right]);
//         swap(tab[border], tab[right]);
//         if(border < n/2)
//         {
//             left = border + 1;
//         }
//         else
//         {
//             right = border - 1;
//         }
//     }
// }
