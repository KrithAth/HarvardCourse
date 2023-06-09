#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.00);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];

        }

    }
    return;
}




int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float counter = 0;
    int sum = 0;

    /** Start from 1 row before it and end at 1 row after it- total of 3rows */
    for (int k = i - 1; k < (i + 2); k++)
    {
        /** Start from 1 block before it and end at 1 block after it- total of 3blocks */
        for (int l = j - 1; l < (j + 2); l ++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                sum += image[k][l].rgbtRed;
            }
            else if (color_position == 1)
            {
                sum += image[k][l].rgbtGreen;
            }
            else
            {
                sum += image[k][l].rgbtBlue;
            }
            counter++;

        }
    }
    return round(sum / counter);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 2);
        }
    }
    return;
}


int getSobelFilter(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float sumX = 0;
    float sumY = 0;

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    /** Start from 1 row before it and end at 1 row after it- total of 3rows */
    for (int k = i - 1, x = 0; k < (i + 2); k++, x++)
    {
        /** Start from 1 block before it and end at 1 block after it- total of 3blocks */
        for (int l = j - 1, y = 0; l < (j + 2); l++, y++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                sumX += image[k][l].rgbtRed * gx[x][y];
                sumY += image[k][l].rgbtRed * gy[x][y];
            }
            else if (color_position == 1)
            {
                sumX += image[k][l].rgbtGreen * gx[x][y];
                sumY += image[k][l].rgbtGreen * gy[x][y];
            }
            else
            {
                sumX += image[k][l].rgbtBlue * gx[x][y];
                sumY += image[k][l].rgbtBlue * gy[x][y];
            }

        }
    }

    int result = round(sqrt((sumX * sumX) + (sumY * sumY)));

    return result < 255 ? result : 255;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getSobelFilter(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getSobelFilter(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getSobelFilter(i, j, height, width, copy, 2);
        }
    }
    return;
}












/*
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0 , 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redx = 0;
            int bluex = 0;
            int greenx = 0;
            int redy = 0;
            int bluey = 0;
            int greeny = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (i - 1 + x < 0 || i - 1 + x > (height - 1) || j -1 + y > (width - 1) || j - 1 + y < 0)
                    {
                        continue;
                    }

                    //calculation for each colour
                    redx = redx + (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);
                    bluex = bluex + (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);
                    greenx = greenx + (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);

                    redy = redy + (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                    bluey = bluey + (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                    greeny = greeny + (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                }
            }

            int red = round(sqrt((redx * redx) + (redy * redy)));
            int green = round(sqrt((greenx * greenx) + (greeny * greeny)));
            int blue = round(sqrt((bluex * bluex) + (bluey * bluey)));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtBlue = blue;
            temp[i][j].rgbtGreen = green;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
*/