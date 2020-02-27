// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Declare numerator value x and denominator value y
    int x = 0;
    int y = 0;

    // Loop through fraction to get x and y values
    for (int i = 0, n = strlen(fraction); i < n; i++)
    {
        if (i < 1)
        {
            x = atoi(&fraction[i]);
        }
        else if (i > 1)
        {
            y = atoi(&fraction[i]);
        }
    }

    // Declare int value for output
    int z = 0;

    // Test which number of eighth notes z will be
    switch (y)
    {
        case 1:
            z = 8 * x;
            break;
        case 2:
            z = 4 * x;
            break;
        case 4:
            z = 2 * x;
            break;
        case 8:
            z = x;
            break;
    }

    return z;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Declare int for key_num and float for octave
    int key_num = 0;
    float octave;

    // Separate note into variables key and octave
    for (int i = 0, len = strlen(note); i < len; i++)
    {
        // Test whether key is an accidental or not
        if (len == 3 && i < 2)
        {
            key_num = key_num + note[i];
        }
        else if (len == 3 && i == 2)
        {
            octave = atof(&note[i]);
        }
        else if (len == 2 && i == 0)
        {
            key_num = key_num + note[i];
        }
        else if (len == 2 && i == 1)
        {
            octave = atof(&note[i]);
        }
    }

    // Get frequency at any A based on what octave is. Store as float in
    // freq_a.
    octave--;
    float freq_a = 55 * pow(2, octave);

    // Declare float n for number of places from A
    float n = 0;

    // Determine number of semitones key_num is from A
    switch (key_num)
    {
        case 65:
            n = 0;
            break;
        case 66:
            n = 2;
            break;
        case 67:
            n = -9;
            break;
        case 68:
            n = -7;
            break;
        case 69:
            n = -5;
            break;
        case 70:
            n = -4;
            break;
        case 71:
            n = -2;
            break;
        case 100:
            n = 1;
            break;
        case 102:
            n = -8;
            break;
        case 103:
            n = -6;
            break;
        case 105:
            n = -3;
            break;
        case 106:
            n = -1;
            break;
        case 163:
            n = -1;
            break;
        case 164:
            n = 1;
            break;
        case 166:
            n = -8;
            break;
        case 167:
            n = -6;
            break;
        case 169:
            n = -3;
            break;
    }

    // Find frequency, rounding it and storing it in
    // int f.
    int f = round(pow(2, n / 12) * freq_a);

    // return f
    return f;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // check if s = "", which denotes a rest. If it is,
    // return 0. Otherwise return 1.
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
