
static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapify(int* a, int len, int i) {
    int l = i*2+1;
    int r = i*2+2;
    
    if (l < len && a[l] > a[i]) {
        swap(&a[l], &a[i]);    
        heapify(a, len, l);    
    }

    if (r < len && a[r] > a[i]) {
        swap(&a[r], &a[i]);
        heapify(a, len, r);
    }
}

static void build(int* a, int len) {
    for (int i = len/2-1; i >= 0; i--) {
        heapify(a, len, i);
    }     
}

void heapsort(int* a, int len) {
    build(a, len);
    while (len > 0) {
        swap(&a[0], &a[--len]);
        heapify(a, len, 0);
    }   
}
