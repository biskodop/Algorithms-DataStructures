#include <iostream>
#include <time.h>

using namespace std;

void array_rand_num(int* tab, int tab_size, int min, int max);
void show_array(float *tab, int n);
void show_array_int(int *tab, int n);
void array_rand_num_2D(int **&tab, int n, int m, int min_val, int max_val);
void show_array_2D(int **tab, int n, int m);
void selection_sort(int* tab, int n);
void bubble_sort(int* tab, int n);
void wstaw_sort(int* tab, int n);
int main()
{
    int a;
    string menu = "Menu:\n"
                  "1. Selection sort\n"
                  "2. Bubble sort\n"
                  "3. Insertion sort\n"
    ;
    string input_text = "Enter n(array size): ";
    cout << menu << endl;
    cin >> a;
    while(!(a >= 1 and a <= 3)){
        cout << menu << endl;
        cin >> a;
    }
    switch(a){
    case 1:
        {
            int n;
            cout <<input_text<<endl;
            cin >> n;
            int tab[n];
            array_rand_num(tab, n, 1, 10);
            show_array_int(tab, n);
            selection_sort(tab,n);
            show_array_int(tab, n);
        }
    break;
    case 2:
        {
            int n;
            cout <<input_text<<endl;
            cin >> n;
            int tab[n];
            array_rand_num(tab, n, 1, 10);
            show_array_int(tab, n);
            bubble_sort(tab,n);
            show_array_int(tab, n);
        }
    break;
    case 3:
        {
            int n;
            cout <<input_text<<endl;
            cin >> n;
            int tab[n];
            array_rand_num(tab, n, 1, 10);
            show_array_int(tab, n);
            wstaw_sort(tab,n);
            show_array_int(tab, n);
        }
    break;
    }
    system("pause");
    return 0;
}
void show_array(float *tab, int n){
    for(int i = 0; i < n; i++){
        cout << tab[i] <<" ";
    }
    cout<<""<<endl;
}
void show_array_int(int *tab, int n){
    for(int i = 0; i < n; i++){
        cout << tab[i] <<" ";
    }
    cout<<""<<endl;
}
void show_array_2D(int *tab[], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << tab[i][j] <<" ";
        }
        cout<<""<<endl;
    }
    cout<<""<<endl;
}
void array_rand_num(int *tab, int tab_size, int min_val, int max_val){
    srand(time(NULL));
    for(int i = 0; i < tab_size; i++){
        tab[i] = min_val + rand()%(max_val - min_val + 1);
    }
}
void array_rand_num_2D(int **&tab, int n, int m, int min_val, int max_val){
    tab = new int*[n];
    for(int i=0;i<n;i++){
        tab[i] = new int[m];
    }
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tab[i][j] = min_val + rand()%(max_val - min_val + 1);
        }
    }
}
void selection_sort(int* tab, int n){
    for(int i = 0; i < n-1; i++)
    {
        int ind = i;
        for(int j = i+1; j < n; j++)
        {
            if (tab[j] < tab[ind])
            {
                ind = j;
            }
        }
        swap(tab[ind], tab[i]);
    }
}
void bubble_sort(int* tab, int n){
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if (tab[j] > tab[j+1])
            {
                swap(tab[j], tab[j+1]);
            }
        }
    }
}
void wstaw_sort(int* tab, int n){
    for(int i = n-2; i >= 0; i--)
    {
        int temp = tab[i];
        int j = i;
        while(j < n-1 && tab[j+1] < temp)
        {
            tab[j] = tab[j+1];
            j++;
        }
        tab[j] = temp;
    }
}