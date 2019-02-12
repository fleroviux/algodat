
static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapify(int* arr, int len, int i) {
    int l = i*2+1;
    int r = i*2+2;
    
    if (l < len && arr[l] > arr[i]) {
        swap(&arr[l], &arr[i]);    
        heapify(arr, len, l);    
    }

    if (r < len && arr[r] > arr[i]) {
        swap(&arr[r], &arr[i]);
        heapify(arr, len, r);
    }
}

static void build(int* arr, int len) {
    for (int i = len/2-1; i >= 0; i--) {
        heapify(arr, len, i);
    }     
}

void heapsort(int* arr, int len) {
    build(arr, len);
    while (len > 0) {
        swap(&arr[0], &arr[--len]);
        heapify(arr, len, 0);
    }   
}
