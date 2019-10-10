/* Calculates the LU-decomposition of a NxN matrix A 
 * into a "lower-triangle" matrix L and an "upper-triangle" matrix U.
 * This allows for efficient solving of linear equation systems,
 * especially when the matrix is always the same but
 * the values we solve for are different.
 */

void decompose(float* a, float* l, float* u, int n) {
  for (int i = 0; i < n*n; i++) {
    l[i] = u[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    l[i*n+i] = 1;
  }

  for (int i = 0; i < n; i++) { // row index
    for (int j = 0; j < i; j++) { // column index
      l[i*n+j] = a[i*n+j];
      
      for (int k = 0; k < j; k++) {
        l[i*n+j] -= l[i*n+k]*u[k*n+j];
      }
      for (int k = j+1; k < n; k++) {
        l[i*n+j] -= l[i*n+k]*u[k*n+j];
      } 
      
      l[i*n+j] /= u[j*n+j];
    }

    for (int j = i; j < n; j++) { // column index
      u[i*n+j] = a[i*n+j];

      for (int k = 0; k < i; k++) {
        u[i*n+j] -= l[i*n+k]*u[k*n+j];
      }
      for (int k = i+1; k < n; k++) {
        u[i*n+j] -= l[i*n+k]*u[k*n+j];
      }
    }
  }
}
