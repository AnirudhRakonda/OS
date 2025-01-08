#include<stdio.h>
int main() {
    int n, frames, pages[100], frame[10], recent[10], faults = 0, found, pos;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string (page numbers): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;  
    }
    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {  
                found = 1;
                recent[j] = i;  
                break;
            }
        }
        if (!found) {  
            if (i < frames) {  
                frame[i] = pages[i];
                recent[i] = i;
            } else {  
                pos = 0;
                for (int j = 1; j < frames; j++) {
                    if (recent[j] < recent[pos]) {
                        pos = j;
                    }
                }
                frame[pos] = pages[i];
                recent[pos] = i;
            }
            faults++;
            printf("Page %d: Fault - Frames: ", pages[i]);
        } else {
            printf("Page %d: Hit   - Frames: ", pages[i]);
        }
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}

