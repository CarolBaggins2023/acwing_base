#include <iostream>
#include <vector>

const int N = 1000010;

int v[N];

void QuickSort(int v[], int l, int r) {
    if (l >= r) {
        return;
    }
    
    int i = l, j = r, pivot = v[l];
    while (i < j) {
        while (i < j && v[j] >= pivot) {
            --j;
        }
        if (i < j) {
            v[i] = v[j];
        }
        while (i < j && v[i] <= pivot) {
            ++i;
        }
        if (i < j) {
            v[j] = v[i];
        }
    }
    v[i] = pivot;
    QuickSort(v, l, i - 1);
    QuickSort(v, i + 1, r);
}

int main(int argc, char* argv[])
{
    int n = 0;
    scanf_s("%d", &n);
    for (int i = 0 ; i < n; ++i) {
        scanf_s("%d", &v[i]);
    }
    QuickSort(v, 0, n - 1);
    for (int i = 0 ; i < n; ++i) {
        printf("%d ", v[i]);
    }
    
    return 0;
}
