#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

void Count(char* s, const char* find, int* a)
{
    int c;
    char* t, * k;
    for (int i = 0; i < strlen(find); i++)
    {
        c = 0;
        t = s;
        k = strchr(t, find[i]);
        while (k != NULL)
        {
            c++;
            t = k + 1;
            k = strchr(t, find[i]);
        }
        a[i] += c;
    }
}

int main()
{
    char str[100];
    char find[] = "BASIC";
    int* a = new int[strlen(find)]();

    ifstream fin("t.txt");
    while (fin.getline(str, 100))
    {
        Count(str, find, a);
    }

    for (int i = 0; i < strlen(find); i++)
    {
        cout << "Symbol " << find[i] << " occurs " << a[i] << " times" << endl;
    }

    delete[] a;

}