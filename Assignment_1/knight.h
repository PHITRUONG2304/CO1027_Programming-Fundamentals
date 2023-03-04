#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

const int MAX_SMALL = 3 + 1;
const int MAX_FROG = 3 + 1;
const float baseDamage[5] = {1, 1.5, 4.5, 7.5, 9.5};

enum KnightInfo
{
    HP_Knight,
    LEVEL_Knight,
    REMEDY_Knight,
    MAIDENKISS_Knight,
    PHOENEXDOWN_Knight
};
enum Opponents
{
    MadBear,
    Bandit,
    LordLupin,
    Elf,
    Troll
};
enum additionalFiles
{
    MUSH_GHOST,
    ASCLEPIUS_PACK,
    MERLIN_PACK
};

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue);

// implement
void readInputFile(string file_name, string &knightInfo, string &events, string &additionalData);


// Knight infomation
void processKnightInfo(string knightInfo, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown);
// convert Events from string to array of integer type
// The array of events that the hero will experience
int *convertEvents(string events, int &eventNums);
// get 3 additional filenames
void processAdditionalData(string additionalData, string &file_mush_ghost, string &file_asclepius_pack, string &file_merlin_pack);

// The component's level when the knight encounter
int opponentLevel(int eventOrder);

// Functions related to the event that the knight meets MERLINE
// Function to be called when the knight encounters MERLINE
int MERLINE_Items(string file_name);
// Check if the item is enchanted
int isMagic(string itemName);

// Functions related to the event that the knight meets Asclepius
// Function to be called when the knight encounters Asclepius
void meetAsclepius(string file_name, int &remedy, int &maidenkiss, int &phoenixdown);

string getMushGostArrayInfo(string filename, int &length);

int pickUpMushGhost(char typeMushRoom, string events, int length);
// Get fibonaci with input is a number
int Fibonaci(int n);
// Descrease to the nearest fibonacci
int decreaseNearestFibonaci(int value);
// Check if the number is prime number
bool isPrimeNumber(int number);
// Increase to the nearest Prime number
int increaseNearestPrime(int value);
// get index of the first/final max number in array
int getMax(string events, int length, bool firstly, int &index);
// get index of the first/final min number in array
int getMin(string events, int length, bool firstly, int &index);
// Check if the array has a mountain shape.
int isMountainPeak(string events, int length);
// convert numbers in array as required
string convertNumbers(string events, int length);
// Function to be called when the knight encounters a type 3 mushroom
int meetMushRoomType3(string events, int length);
// get index of the first 2nd largest number in array
int event_2ndLargestNumber(string events, int length);

#endif // __KNIGHT_H__