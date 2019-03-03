#include <bits/stdc++.h>
using namespace std;
// random algorithm, identify A * A = B
// (A * (A * C)) = B * C => O(n^2)
#define MAXN 1024
int A[MAXN][MAXN], B[MAXN][MAXN];
int C[MAXN], D[MAXN], E[MAXN], F[MAXN];
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &A[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &B[i][j]);
        for (int i = 0; i < n; i++)
            C[i] = rand() + 1; //Generamos nuestras variables aleatorias
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = 0; j < n; j++){
            	//Buscamos C * A y C* B para el teoreama de (A * (A * C))= B * C donde A*A =B
            	x += C[j] * A[i][j], y += C[j] * B[i][j];
            }

            D[i] = x, E[i] = y; // Guardamos nuestra variables
        }
        int ok = 1;
        for (int i = 0; i < n && ok; i++) {
            int x = 0;
            for (int j = 0; j < n; j++){
            	// D= C * A al multiplicarlo seria (A * (A*C))
            	x += D[j] * A[i][j];
            }
            F[i] = x;
            //Comparacion Si F = (A * (A*C)) es igual a B * C , F= B * C
            ok &= F[i] == E[i];
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}