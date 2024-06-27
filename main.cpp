#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void s(int*, int);
void m(int*, int);
void q(int*, int);
void i(int*, int);
int* g(int);
void c(int*, int*, int*, int, int, int);
void r(int*);

void s(int* a, int n) {
    if (n <= 10) {
        m(a, n);
    } else {
        q(a, n);
    }
}

void m(int* a, int n) {
    if (n <= 1) return;

    int* l = g(n / 2);
    int* r = g(n - n / 2);
    c(l, r, a, n / 2, n - n / 2, n);
    m(l, n / 2);
    m(r, n - n / 2);
    c(l, r, a, n / 2, n - n / 2, n);
    delete[] l;
    delete[] r;
}

// Quick sort function
void q(int* a, int n) {
    if (n <= 1) return;

    int p = a[n / 2];
    int* l = g(n);
    int* r = g(n);
    int* m = g(n);

    int ls = 0, rs = 0, ms = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < p) {
            l[ls++] = a[i];
        } else if (a[i] > p) {
            r[rs++] = a[i];
        } else {
            m[ms++] = a[i];
        }
    }

    q(l, ls);
    q(r, rs);
    c(l, m, a, ls, ms, n);
    c(l, r, a, ls, rs, n);

    delete[] l;
    delete[] r;
    delete[] m;
}

void i(int* a, int n) {
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = k;
    }
}

int* g(int n) {
    return new int[n];
}

void c(int* l, int* r, int* a, int ls, int rs, int n) {
    int i = 0, j = 0, k = 0;

    while (i < ls && j < rs) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            ++i;
        } else {
            a[k] = r[j];
            ++j;
        }
        ++k;
    }

    while (i < ls) {
        a[k] = l[i];
        ++i;
        ++k;
    }

    while (j < rs) {
        a[k] = r[j];
        ++j;
        ++k;
    }
}

void r(int* a) {
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i) {
        a[i] = rand() % 101;
    }
}

int main() {
    int a[100];

    r(a);
  
    s(a, 100);

    std::cout << "Output: ";
    for (int i = 0; i < 100; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
