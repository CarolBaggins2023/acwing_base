#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &v, int l, int r) {
    if (l >= r) {
        return;
    }

    int i = l, j = r, idx = v[l];
    while (i < j) {
        while (i < j && v[j] >= idx) {
            --j;
        }
        if (i < j) {
            v[i++] = v[j];
        }
        while (i < j && v[i] <= idx) {
            ++i;
        }
        if (i < j) {
            v[j--] = v[i];
        }
    }

    v[i] = idx;
    quick_sort(v, l, i - 1);
    quick_sort(v, i + 1, r);
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::vector<int> v;
    scanf_s("%d", &n);
    int j;
    for (int i = 0; i < n; ++i) {
        scanf_s("%d", &j);
        v.emplace_back(j);
    }

    quick_sort(v, 0, n - 1);

    for (int i : v) {
        printf("%d ", i);
    }
    
    return 0;
}
