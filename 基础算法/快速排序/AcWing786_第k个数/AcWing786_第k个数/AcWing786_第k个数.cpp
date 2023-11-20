#include <iostream>
#include <vector>

int FindKth(std::vector<int> v, int k, int l, int r) {
    int i = l, j = r;
    int pivot = v[l];
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
    if (i + 1 == k) {
        return pivot;
    }
    if (i + 1 < k) {
        return FindKth(v, k, i + 1, r);
    }
    if (i + 1 > k) {
        return FindKth(v, k, l, i - 1);
    }
}

int main(int argc, char* argv[])
{
    int n = 0, k = 0;
    std::vector<int> v;
    scanf_s("%d %d", &n, &k);

    int v_in = 0;
    for (int i = 0 ; i < n; ++i) {
        scanf_s("%d", &v_in);
        v.emplace_back(v_in);
    }

    printf("%d", FindKth(v, k, 0, n - 1));
    
    return 0;
}
