#include "../libs/color.h"

string parseColor(Color color)
{
    switch (color)
    {
    case Default:
        return "[0m";
    case Black:
        return "[30m";
    case Red:
        return "[31m";
    case Green:
        return "[32m";
    default:
        fprintf(stderr, "Couldn't parse Color Code!\n");
        exit(EXT_ERR_COLOR_INVALID);
    }
}