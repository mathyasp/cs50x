#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through the rows
    for (int i = 0; i < height; i++)
    {
        // Loop through the columns
        for (int j = 0; j < width; j++)
        {
            // Convert to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // Find the average of the pixel color values
            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through the rows
    for (int i = 0; i < height; i++)
    {
        // Loop through the columns
        for (int j = 0; j < width; j++)
        {
            // Convert to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // Calculate the sepia value for each color
            int sepiaRed = round((.393 * Red) + (.769 * Green) + (.189 * Blue));
            int sepiaGreen = round((.349 * Red) + (.686 * Green) + (.168 * Blue));
            int sepiaBlue = round((.272 * Red) + (.534 * Green) + (.131 * Blue));

            // Adjust for values over 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Add updated pixel values to image
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through the rows
    for (int i = 0; i < height; i++)
    {
        // Loop through the columns
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of the image. Loop through the rows
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set a counter, make 2 arrays for the row coordinates and the column coordinates
            int count = 0;
            int rowCoords[] = {i - 1, i, i + 1};
            int colCoords[] = {j - 1, j, j + 1};
            // Set float values for each color and set equal to 0
            float totalRed = 0, totalGreen = 0, totalBlue = 0;

            // Loop through the neighboring pixels
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    // Set ints for Row and Column that are equal to the coordinates at the given pixel
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    // Check if pixel location is valid (not on an edge)
                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        // Set pixel value equal to the current location
                        RGBTRIPLE pixel = image[curRow][curCol];

                        // Assign the value to each color as a total and count each cycle
                        totalRed += pixel.rgbtRed;
                        totalGreen += pixel.rgbtGreen;
                        totalBlue += pixel.rgbtBlue;
                        count++;
                    }
                }
            }
            // Determing color values by dividing the total value by the count value
            temp[i][j].rgbtRed = round(totalRed / count);
            temp[i][j].rgbtGreen = round(totalGreen / count);
            temp[i][j].rgbtBlue = round(totalBlue / count);
        }
    }
    // Assign each calculated(blurred) pixel values to the new image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}