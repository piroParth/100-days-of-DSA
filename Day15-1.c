#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int sum = 0;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
