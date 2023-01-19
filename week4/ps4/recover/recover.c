#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
BYTE buffer[512];
int BLOCK_SIZE = 512;
int jpg_count = 0;
char jpg_id[8];
FILE *write = NULL;

int main(int argc, char *argv[])
{
    // Only accept 1 argument
    if (argc != 2)
    {
        printf("Only accepts exactly ONE argument\n");
        return 1;
    }
    // Open memory card
    FILE *file = fopen(argv[1], "r");

    // Only accept readable files
    if (file == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    // Repeat until end of card:
    // Read 512 Bytes into a buffer
    while (BLOCK_SIZE == (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file)))
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If first JPEG
            if (jpg_count == 0)
            {
                // Make new JPEG file
                sprintf(jpg_id, "%03i.jpg", jpg_count);

                // Open a new file to write into
                write = fopen(jpg_id, "w");

                // Start writing new file
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, write);

                // Add to counter for new JPEG checked
                jpg_count++;
            }
            // Else
            else
            {
                // Close file and open a new file
                fclose(write);

                // Make new JPEG file
                sprintf(jpg_id, "%03i.jpg", jpg_count);

                // Open a new file to write into
                write = fopen(jpg_id, "w");

                // Start writing new file
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, write);

                // Add to counter for new JPEG checked
                jpg_count++;
            }
        }

        // Else if already found JPEG
        else if (jpg_count > 0)
        {
            // Keep writing the file
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, write);
        }
    }

    // Close any remaining files
    fclose(write);
    fclose(file);
    return 0;
}