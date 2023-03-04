#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void findFirst(char *str)
{
    char * pch;
    pch = strtok(str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
}

int findRepetition(char str_1[], char str_2[])
{
    int count = 0;
    bool found = true;
    for(int i=0; i <= strlen(str_1); i++)
    {
        if(str_1[i] == ' ' || str_1[i] == '\0')
        {
            for(int j = 0; j < strlen(str_2); j++)
            {
                // cout << str_1[i - strlen(str_2) + j] << " " << str_2[j] << endl;
                if(str_1[i - strlen(str_2) + j] != str_2[j])
                {
                    found = false;
                    break;
                }
            }
            // cout << endl;
            if(found) count++;
        }

        found = true;
    }
    // cout << count << endl;
    return count;
}

void printFirstRepeatedWord(char str[]) {
    // TODO
    bool repeat = false;

    char* str_copy = new char[strlen(str) + 1];
    strcpy(str_copy, str);

    char *pch = strtok(str_copy, " ");
    while (pch != NULL)
    {
        if(findRepetition(str, pch) > 1)
        {
            repeat = true;
            break;
        }
        pch = strtok (NULL, " ");
    }
    
    if(repeat)
    {
        cout << pch;
    }
    else 
        cout << "No Repetition";
        
    delete[] str_copy;
}    

int main()
{
    char x[] = "a b c";
    printFirstRepeatedWord(x);
    return 0;
}