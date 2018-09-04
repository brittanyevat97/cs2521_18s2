#include <stdio.h>

typedef struct ... Item;
int less(Item, Item);

// runLength is the length of each sorted sequence in inFile
// outFile will contain sorted sequences of length 2*runLength
void fileMerge(char *inFile, char *outFile, int runLength, int N) {

    FILE *inf1 = fopen(inFile, "r");
    FILE *inf2 = fopen(inFile, "r");
    FILE *outf = fopen(outFile, "w");

    // offset into the file is in bytes
    long in1 = 0; // indicates offset for inf1
    long in2 = runLength*sizeof(Item); // indicates offset for inf2
    long end1, end2; // to indicate end of current sorted sequences
    Item it1, it2;

    while (in1 < N*sizeof(Item)) {
        end1 = in1 + runLength*sizeof(Item);
        end2 = in2 + runLength*sizeof(Item);

        // seek to the offset we want in inf1 and inf2
        // and read one Item from this offset
        fseek(inf1, in1, SEEK_SET);
        fread(&it1, sizeof(Item), 1, inf1);
        fseek(inf2, in2, SEEK_SET);
        fread(&it2, sizeof(Item), 1, inf2);
        // note that fread advances the file offsets of inf1 and inf2
        // (but not in1 and in2, which we are using to manually keep
        // track of the file offsets)

        // the merging process
        while (in1 < end1 && in2 < end2) {
            if (less(it1, it2)) {
                // write item to output file
                fwrite(&it1, sizeof(Item), 1, outf);
                // and read next item from inf1
                fread(&it1, sizeof(Item), 1, inf1);
                in1 += sizeof(Item);
            } else {
                fwrite(&it2, sizeof(Item), 1, outf);
                fread(&it2, sizeof(Item), 1, inf2);
                in2 += sizeof(Item);
            }
        }
        while (in1 < end1) {
            fwrite(&it1, sizeof(Item), 1, outf);
            fread(&it1, sizeof(Item), 1, inf1);
            in1 += sizeof(Item);
        }
        while (in2 < end2) {
            fwrite(&it2, sizeof(Item), 1, outf);
            fread(&it2, sizeof(Item), 1, inf2);
            in2 += sizeof(Item);
        }
        // set our variables keeping track of the offsets to
        // the beginning of the next pair of sorted sequences
        in1 += runLength*sizeof(Item);
        in2 += runLength*sizeof(Item);
    }
    fclose(inf1);
    fclose(inf2);
    fclose(outf);
}
