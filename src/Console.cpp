#include "../libs/console.h"

void printMessage(string msg, Color color, int newLine)
{
    if(!color)
    {
        cerr << "\033" << parseColor(Red) << "error: printMessage: Except Color Code Arg.\033" << parseColor(Default) << endl;
    }
    if(newLine == 1)
    {
        cout << "\033" << parseColor(color) << msg << "\033" << parseColor(Default) << endl;
    }
    cout << "\033" << parseColor(color) << msg << "\033" << parseColor(Default);
}