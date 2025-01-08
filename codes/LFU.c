#include <stdio.h>
#define MAX 100

int main() {
    int n, frames, page[MAX], freq[MAX], frame[MAX], time[MAX];
    int i, j, pos, found, fault = 0, min_freq, min_time;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string (page numbers): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    printf("\nPage Reference\tStatus\t\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                freq[j]++;
                time[j] = i;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    freq[j] = 1;
                    time[j] = i;
                    fault++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                pos = 0;
                min_freq = freq[0];
                min_time = time[0];

                for (j = 1; j < frames; j++) {
                    if (freq[j] < min_freq || (freq[j] == min_freq && time[j] < min_time)) {
                        min_freq = freq[j];
                        min_time = time[j];
                        pos = j;
                    }
                }

                frame[pos] = page[i];
                freq[pos] = 1;
                time[pos] = i;
                fault++;
            }
        }

        printf("%d\t\t", page[i]);
        if (!found) {
            printf("Fault\t\t");
        } else {
            printf("Hit\t\t");
        }

        for (j = 0; j < frames; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", fault);

    return 0;
}
