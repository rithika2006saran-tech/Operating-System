#include <stdio.h>

int main() {
    int n, frames, i, j, pageFaults = 0, pageHits = 0;
    
    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    int pages[n];

    printf("\nEnter the reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nEnter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];

    // Initialize frames with -1
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int index = 0;

    // FIFO Page Replacement
    for(i = 0; i < n; i++) {
        int found = 0;

        // Check for page hit
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                pageHits++;
                break;
            }
        }

        // Page Fault
        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
    }

    // Output
    printf("\n\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}