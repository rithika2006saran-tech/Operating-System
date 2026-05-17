#include <stdio.h>

int main() {
    int n, frames, i, j;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    int pages[n];

    printf("\nEnter the reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nEnter number of frames: ");
    scanf("%d", &frames);

    int frame[frames], recent[frames];
    int pageFaults = 0, pageHits = 0, time = 0;

    // Initialize frames
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        recent[i] = -1;
    }

    // LRU Page Replacement
    for(i = 0; i < n; i++) {
        int found = 0;

        // Check for page hit
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                pageHits++;
                recent[j] = time++;
                break;
            }
        }

        // Page Fault
        if(!found) {
            int lruIndex = 0;

            // Find empty frame first
            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    lruIndex = j;
                    break;
                }

                // Find least recently used page
                if(recent[j] < recent[lruIndex]) {
                    lruIndex = j;
                }
            }

            frame[lruIndex] = pages[i];
            recent[lruIndex] = time++;

            pageFaults++;
        }
    }

    // Output
    printf("\n\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}