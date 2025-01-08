#include<stdio.h>

int main() {
    int n, frames, pages[100], frame[10], faults = 0, index = 0, found;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string (page numbers): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for(int i = 0; i < frames; i++) {
        frame[i] = -1;  
    }

    for(int i = 0; i < n; i++) {
        found = 0;

        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {  
                found = 1;
                break;
            }
        }

        if(!found) {  
            frame[index] = pages[i];  
            index = (index + 1) % frames;  
            faults++;
            printf("Page %d: Fault - Frames: ", pages[i]);
        } else {
            printf("Page %d: Hit   - Frames: ", pages[i]);
        }

        for(int j = 0; j < frames; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
