
void mergesort(int* arr, int len) {
  if (len == 1) {
    return;
  } else {
    int halfes = len / 2;
    mergesort(arr, halfes);
    if ((len % 2) == 1) {
      mergesort(arr+halfes, halfes+1);
    } else {
      mergesort(arr+halfes, halfes);
    }
    int i = 0;
    int a = 0;
    int b = halfes;
    int tmp[len];
    while (i < len) {
      if ((a < halfes) && ((arr[a] < arr[b]) || b >= len)) {
        tmp[i++] = arr[a++]; 
      } else {
        tmp[i++] = arr[b++];
      }
    }
    i = 0;
    while (i < len) {
      arr[i] = tmp[i];
      i++;
    }
  }
}
