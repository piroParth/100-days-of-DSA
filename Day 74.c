#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    // Input names
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char winner[LEN];
    int maxVotes = 0;

    for(int i = 0; i < n; i++) {
        int count = 1;

        // Count frequency of names[i]
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        // Update winner
        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes) {
            // Lexicographically smaller
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}