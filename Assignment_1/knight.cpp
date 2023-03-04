#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

void readInputFile(string file_name, string &knightInfo, string &events, string &additionalData)
{
    ifstream myfile(file_name);
    string temp_str;
    int orderInfo = 0;
    while (!myfile.eof())
    {
        getline(myfile, temp_str);
        switch (orderInfo)
        {
        case 0:
            knightInfo = temp_str;
            break;
        case 1:
            events = temp_str;
            break;
        case 2:
            additionalData = temp_str;
            break;
        default:
            cout << "Data is not correct!\n";
        }
        orderInfo++;
    }
    myfile.close();
}

void processKnightInfo(string knightInfo, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown)
{
    int orderInfo = HP_Knight;
    int index = 0, length_info = 0;
    for (int i = 0; i <= knightInfo.length(); i++)
    {
        length_info++;
        if (knightInfo[i] == ' ' || knightInfo[i] == '\0')
        {
            switch (orderInfo)
            {
            case HP_Knight:
                HP = stoi(knightInfo.substr(index, length_info - 1));
                break;
            case LEVEL_Knight:
                level = stoi(knightInfo.substr(index, length_info - 1));
                break;
            case REMEDY_Knight:
                remedy = stoi(knightInfo.substr(index, length_info - 1));
                break;
            case MAIDENKISS_Knight:
                maidenkiss = stoi(knightInfo.substr(index, length_info - 1));
                break;
            case PHOENEXDOWN_Knight:
                phoenixdown = stoi(knightInfo.substr(index, length_info - 1));
                break;
            default:
                break;
            }
            orderInfo++;
            length_info = 0;
            index = i + 1;
        }
    }
}

int *convertEvents(string events, int &eventNums)
{
    eventNums = 0;
    for (int i = 0; i <= events.length(); i++)
    {
        if (events[i] == ' ' || events[i] == '\0')
            eventNums++;
    }
    int *arr = new int[eventNums];

    int i = 0;
    int first = 0, last = 0;
    while (true)
    {
        last = int(events.find(' ', first));
        if (last != -1)
        {
            arr[i++] = stoi(events.substr(first, last - first));
            first = last + 1;
        }
        else
        {
            arr[i] = stoi(events.substr(first));
            break;
        }
    }

    return arr;
}

void processAdditionalData(string additionalData, string &file_mush_ghost, string &file_asclepius_pack, string &file_merlin_pack)
{
    int orderInfo = 0;
    int index = 0, length_info = 0;
    for (int i = 0; i <= additionalData.length(); i++)
    {
        length_info++;
        if (additionalData[i] == ',' || additionalData[i] == '\0')
        {
            switch (orderInfo)
            {
            case MUSH_GHOST:
                file_mush_ghost = additionalData.substr(index, length_info - 1);
                break;
            case ASCLEPIUS_PACK:
                file_asclepius_pack = additionalData.substr(index, length_info - 1);
                break;
            case MERLIN_PACK:
                file_merlin_pack = additionalData.substr(index, length_info - 1);
                break;
            default:
                break;
            }
            orderInfo++;
            length_info = 0;
            index = i + 1;
        }
    }
}

int Fibonaci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return Fibonaci(n - 1) + Fibonaci(n - 2);
}

int decreaseNearestFibonaci(int value)
{
    int i = 0;
    while (true)
    {
        if (value < Fibonaci(i))
            break;
        i++;
    }
    return Fibonaci(i - 1);
}

int opponentLevel(int eventOrder)
{
    int b = eventOrder % 10;
    return eventOrder > 6 ? (b > 5 ? b : 5) : b;
}

bool isPrimeNumber(int number)
{
    for (int i = 2; i <= int(number / 2); i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int increaseNearestPrime(int value)
{
    int result = value;
    if (result % 2 == 0)
        result += 1;
    while (!isPrimeNumber(result))
    {
        result += 2;
    }

    return result;
}

int isMagic(string itemName)
{
    for (int i = 0; i < itemName.length(); i++)
    {
        itemName[i] = tolower(itemName[i]);
    }

    if (itemName.find("merlin") != std::string::npos)
        return 3;

    string temp_str = "merlin";
    for (int i = 0; i < temp_str.length(); i++)
    {
        if (itemName.find(temp_str[i]) == std::string::npos)
            return 0;
    }
    return 2;
}

int MERLINE_Items(string file_name)
{
    ifstream myfile(file_name);
    string temp_str;
    getline(myfile, temp_str);
    int addtionalHP = 0;
    int n9 = stoi(temp_str);
    for (int i = 0; i < n9; i++)
    {
        getline(myfile, temp_str);
        addtionalHP += isMagic(temp_str);
    }
    myfile.close();

    return addtionalHP;
}

void meetAsclepius(string file_name, int &remedy, int &maidenkiss, int &phoenixdown)
{
    ifstream myfile(file_name);
    string temp_str;
    getline(myfile, temp_str);
    int r1 = stoi(temp_str);
    getline(myfile, temp_str);
    int c1 = stoi(temp_str);

    for (int i = 0; i < r1; i++)
    {
        getline(myfile, temp_str);
        int j = 0, first = 0, last = 0, tookDrugs = 3;
        while (j < c1)
        {
            last = (int(temp_str.find(' ', first)) != -1) ? int(temp_str.find(' ', first)) : temp_str.length();
            if (stoi(temp_str.substr(first, last - first)) == 16)
            {
                remedy = (remedy == 99) ? 99 : remedy + 1;
                tookDrugs--;
            }
            else if (stoi(temp_str.substr(first, last - first)) == 17)
            {
                maidenkiss = (maidenkiss == 99) ? 99 : maidenkiss + 1;
                tookDrugs--;
            }
            else if (stoi(temp_str.substr(first, last - first)) == 18)
            {
                phoenixdown = (phoenixdown == 99) ? 99 : phoenixdown + 1;
                tookDrugs--;
            }

            if (tookDrugs == 0)
                break;
            first = last + 1;
            j++;
        }
    }
    myfile.close();
}

int getMax(string events, int length, bool firstly, int &index)
{
    int max = INT8_MIN, i = 0, first = 0, last = 0;
    index = -1;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;

        if (max < stoi(events.substr(first, last - first)) && firstly)
        {
            max = stoi(events.substr(first, last - first));
            index = i;
        }
        else if (max <= stoi(events.substr(first, last - first)) && !firstly)
        {
            max = stoi(events.substr(first, last - first));
            index = i;
        }
        first = last + 1;

        i++;
    }

    return max;
}

int getMin(string events, int length, bool firstly, int &index)
{
    int min = INT8_MAX, i = 0, first = 0, last = 0;
    index = -1;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;

        if (min > stoi(events.substr(first, last - first)) && firstly)
        {
            min = stoi(events.substr(first, last - first));
            index = i;
        }
        else if (min >= stoi(events.substr(first, last - first)) && !firstly)
        {
            min = stoi(events.substr(first, last - first));
            index = i;
        }
        first = last + 1;

        i++;
    }

    return min;
}

int isMountainPeak(string events, int length)
{
    int indexMaxNumber;
    int maxNumber = getMax(events, length, true, indexMaxNumber);
    int first = 0, last = 0, i = 0;
    int previous;
    if (indexMaxNumber == 0)
    {
        previous = INT8_MAX;
        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
            if (previous <= stoi(events.substr(first, last - first)))
                return -2 + -3;

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return maxNumber;
    }
    else if (indexMaxNumber == length - 1)
    {
        first = 0, last = 0, i = 0;
        previous = INT8_MIN;
        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
            if (i != 0 && i != (length - 1))
                if (previous >= stoi(events.substr(first, last - first)))
                    return -2 + -3;

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return length - 1 + maxNumber;
    }
    else
    {
        bool accending = true;

        first = 0, last = 0, i = 0;
        previous = INT8_MIN;

        while (i < length)
        {
            last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
            if (i != 0)
            {
                if (accending)
                {
                    if (previous >= stoi(events.substr(first, last - first)))
                        return -2 + -3;
                    if (i == indexMaxNumber)
                        accending = false;
                }
                else
                {
                    if (previous <= stoi(events.substr(first, last - first)))
                        return -2 + -3;
                }
            }

            previous = stoi(events.substr(first, last - first));
            first = last + 1;
            i++;
        }
        return maxNumber + indexMaxNumber;
    }
}

string convertNumbers(string events, int length)
{
    string changed_events = "";
    int first = 0, last = 0, i = 0;
    int temp_number;
    while (i < length)
    {
        last = (int(events.find(',', first)) != -1) ? int(events.find(',', first)) : length;
        temp_number = stoi(events.substr(first, last - first));
        if (temp_number < 0)
            temp_number = -temp_number;

        temp_number = (17 * temp_number + 9) % 257;
        changed_events += to_string(temp_number) + ',';

        first = last + 1;
        i++;
    }

    return changed_events.substr(0, changed_events.length() - 1);
}

int meetMushRoomType3(string events, int length)
{
    string changed_events = convertNumbers(events, length);

    int indexMax, indexMin;
    getMax(changed_events, length, true, indexMax);
    getMin(changed_events, length, true, indexMin);

    return indexMax + indexMin;
}

int event_2ndLargestNumber(string events, int length)
{
    string changed_events = convertNumbers(events, length);

    int index_MaxNumber;
    int maxNumber = getMax(changed_events, 3, true, index_MaxNumber);

    int result = INT8_MIN, i = 0, first = 0, last = 0;
    int index = -1;
    while (i < 3)
    {
        last = (int(changed_events.find(',', first)) != -1) ? int(changed_events.find(',', first)) : length;

        if (result < stoi(changed_events.substr(first, last - first)) && stoi(changed_events.substr(first, last - first)) < maxNumber)
        {
            result = stoi(changed_events.substr(first, last - first));
            index = i;
        }
        first = last + 1;
        i++;
    }

    if (index == -1)
        return -5 + -7;

    return index + result;
}

string getMushGostArrayInfo(string filename, int &length)
{
    ifstream myfile(filename);

    string temp_str;
    getline(myfile, temp_str);
    length = stoi(temp_str);

    getline(myfile, temp_str);
    myfile.close();

    return temp_str;
}

int pickUpMushGhost(char typeMushRoom, string events, int length)
{
    int result = 0;
    int indexMax, indexMin;
    switch (typeMushRoom)
    {
    case '1':
        getMax(events, length, false, indexMax);
        getMin(events, length, false, indexMin);
        result = indexMax + indexMin;
        break;

    case '2':
        result = isMountainPeak(events, length);
        break;

    case '3':
        result = meetMushRoomType3(events, length);
        break;

    case '4':
        result = event_2ndLargestNumber(events, length);
        break;

    default:
        break;
    }
    return result;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    // implement
    string knightInfo, events, additionalData;
    // read file txt
    readInputFile(file_input, knightInfo, events, additionalData);

    // convert Knight information
    processKnightInfo(knightInfo, HP, level, remedy, maidenkiss, phoenixdown);
    // convert additional files
    string file_mush_ghost, file_asclepius_pack, file_merlin_pack;
    processAdditionalData(additionalData, file_mush_ghost, file_asclepius_pack, file_merlin_pack);
    // convert events
    int eventNums = 0;
    int *arr_events = convertEvents(events, eventNums);

    // Initial
    // Initial start
    bool arthur = (HP == 999) ? true : false;
    bool lancelot = isPrimeNumber(HP);
    bool isMetMerlin = false;
    bool isMetAsclepius = false;

    const int MAX_HP = HP;

    rescue = -1;
    int small = 0;

    int frog = 0;
    int old_level;

    int s1 = 0;
    // opponent level
    int levelO = -1;

    for (int i = 0; i < eventNums; i++)
    {
        switch (arr_events[i])
        {
        case 0: // Bowser surrendered
            rescue = 1;
            break;

        case 1: // MadBear
            levelO = opponentLevel(i + 1);
            if (level > levelO || arthur || lancelot)
            {
                level = (level == 10) ? level : level + 1;
            }
            else if (level < levelO)
            {
                HP = HP - baseDamage[MadBear] * levelO * 10;
            }
            break;

        case 2: // Bandit
            levelO = opponentLevel(i + 1);
            if (level > levelO || arthur || lancelot)
            {
                level = (level == 10) ? level : level + 1;
            }
            else if (level < levelO)
            {
                HP = HP - baseDamage[Bandit] * levelO * 10;
            }
            break;

        case 3: // LordLupin
            levelO = opponentLevel(i + 1);
            if (level > levelO || arthur || lancelot)
            {
                level = (level == 10) ? level : level + 1;
            }
            else if (level < levelO)
            {
                HP = HP - baseDamage[LordLupin] * levelO * 10;
            }
            break;

        case 4: // Elf
            levelO = opponentLevel(i + 1);
            if (level > levelO || arthur || lancelot)
            {
                level = (level == 10) ? level : level + 1;
            }
            else if (level < levelO)
            {
                HP = HP - baseDamage[Elf] * levelO * 10;
            }
            break;

        case 5: // Troll
            levelO = opponentLevel(i + 1);
            if (level > levelO || arthur || lancelot)
            {
                level = (level == 10) ? level : level + 1;
            }
            else if (level < levelO)
            {
                HP = HP - baseDamage[Troll] * levelO * 10;
            }
            break;

        case 6: // Shaman
            if (small == 0 || frog == 0)
            {
                levelO = opponentLevel(i + 1);
                if (level > levelO || arthur || lancelot)
                {
                    level = (level + 2 > 10) ? 10 : level + 2;
                }
                else if (level < levelO)
                {

                    if (remedy > 0)
                    {
                        remedy--;
                    }
                    else
                    {
                        small = MAX_SMALL;
                        HP = (HP < 5) ? 1 : int(HP / 5);
                    }
                }
            }
            break;

        case 7: // Siren Vajsh
            if (small == 0 || frog == 0)
            {
                levelO = opponentLevel(i + 1);
                if (level > levelO || arthur || lancelot)
                {
                    level = (level + 2 > 10) ? 10 : level + 2;
                }
                else if (level < levelO)
                {
                    if (maidenkiss > 0)
                    {
                        maidenkiss--;
                    }
                    else
                    {
                        frog = MAX_FROG;
                        old_level = level;
                        level = 1;
                    }
                }
            }
            break;

        case 11: // Mush Mario
            s1 = 0;
            for (int i = 0; i < ((level + phoenixdown) % 5 + 1) * 3; i++)
            {
                s1 += 99 - 2 * i;
            }

            HP = increaseNearestPrime(HP + s1 % 100);
            if (HP > MAX_HP)
                HP = MAX_HP;

            break;

        case 12: // Fibonacci MushFibo
            if (HP > 1)
                HP = decreaseNearestFibonaci(HP);
            break;

        case 15: // Remedy
            if (small > 0)
            {
                small = 0;
                HP = (HP * 5 > MAX_HP) ? MAX_HP : HP * 5;
            }
            else
                remedy = (remedy == 99) ? remedy : remedy + 1;
            break;

        case 16: // MaidenKiss
            if (frog > 0)
            {
                frog = 0;
                level = old_level;
            }
            else
                maidenkiss = (maidenkiss == 99) ? maidenkiss : maidenkiss + 1;
            break;

        case 17: // PhoenixDown
            phoenixdown = (phoenixdown == 99) ? phoenixdown : phoenixdown + 1;
            break;

        case 18: // Meet Merlin
            if (!isMetMerlin)
            {
                HP += MERLINE_Items(file_merlin_pack);
                if (HP > MAX_HP)
                    HP = MAX_HP;
                isMetMerlin = true;
            }
            break;

        case 19: // Meet Asclepius
            if (!isMetAsclepius)
            {
                isMetAsclepius = true;
                meetAsclepius(file_asclepius_pack, remedy, maidenkiss, phoenixdown);

                if (small > 0)
                {
                    small = 0;
                    HP = (HP * 5 > MAX_HP) ? MAX_HP : HP * 5;
                    remedy--;
                }
                if (frog > 0)
                {
                    frog = 0;
                    level = old_level;
                    maidenkiss--;
                }
            }
            break;

        case 99: // Meet Bowser
            if (arthur)
                level = 10;
            else if (lancelot && level >= 8)
                level = 10;
            else if (level == 10)
                level = 10;
            else
                rescue = 0;
            break;

        default:
            if (to_string(arr_events[i]).substr(0, 2) == "13")
            {
                int number_events;
                string temp_events = getMushGostArrayInfo(file_mush_ghost, number_events);
                for (int j = 2; j < to_string(arr_events[i]).length(); j++)
                {
                    HP -= pickUpMushGhost(to_string(arr_events[i])[j], temp_events, number_events);
                    if (HP < 0)
                    {
                        if (phoenixdown > 0)
                        {
                            phoenixdown -= 1;
                            HP = MAX_HP;
                            // ????????????
                            if (small > 0)
                                small = 0;
                            // ????????????
                        }
                        else
                            break;
                    }
                }
            }
            break;
        }

        if (rescue != -1)
            break;

        if (HP < 0)
        {
            if (phoenixdown > 0)
            {
                phoenixdown -= 1;
                HP = MAX_HP;
                if (small > 0)
                    small = 0;
                if (frog > 0)
                {
                    frog = 0;
                    level = old_level;
                }
            }
            else
            {
                rescue = 0;
                break;
            }
        }

        if (small > 0)
        {
            small--;
            if (small == 0)
                HP = (HP * 5 > MAX_HP) ? MAX_HP : HP * 5;
        }
        if (frog > 0)
        {
            frog--;
            if (frog == 0)
                level = old_level;
        }

        if (i == eventNums - 1)
            break;

        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }

    if (rescue == -1)
        rescue = 1;

    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    delete[] arr_events;
}