#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int rollDice()
{
    int result = std::rand() % 6 + 1;
    cout << "dice roll: " << result << endl;
    return result;
}

int main()
{

    int troup_att, troup_def;
    int LostTotalAtt = 0;
    int LostTotalDef = 0;

    cout << "troup attack amount:";
    cin >> troup_att;

    while (true)
    {

        int dice[3];

        int maxAtt1, maxAtt2, maxDef1, maxDef2;

        cout << "Troups attacing: " << troup_att << endl;
        cin.clear();
        cout << "troup defense amount:";
        cin >> troup_def;

        cout << "Troups defending: " << troup_def << endl;
        cin.clear();

        int troupAttOld = troup_att;
        int troupDefOld = troup_def;

        std::srand(std::time(0));

        while (troup_att >= 3 && troup_def >= 1)
        {

            dice[0] = 0;
            dice[1] = 0;
            dice[2] = 0;

            dice[0] = rollDice();
            dice[1] = rollDice();
            dice[2] = rollDice();

            int n = sizeof(dice) / sizeof(dice[0]); // Calculate the size of the array

            std::sort(dice, dice + n);

            maxAtt2 = dice[1];
            maxAtt1 = dice[2];

            if (troup_def >= 2 && maxAtt2 <= 3)
            {

                if (maxAtt2 <= 3)
                {

                    dice[0] = 0;
                    dice[1] = 0;
                    dice[2] = 0;

                    dice[1] = rollDice();
                    dice[2] = rollDice();

                    n = sizeof(dice) / sizeof(dice[0]);
                    sort(dice, dice + n);

                    maxDef1 = dice[2];
                    maxDef2 = dice[1];

                    if (maxDef1 >= maxAtt1)
                    {
                        troup_att--;
                        cout << "defense wins 2 dice: " << maxDef1 << " vs  attack: " << maxAtt1 << endl;
                    }
                    else if (maxDef1 < maxAtt1)
                    {
                        troup_def--;
                        cout << "attack wins 2 dice: " << maxAtt1 << " vs  attack: " << maxDef1 << endl;
                    }

                    if (maxDef2 >= maxAtt2)
                    {
                        troup_att--;
                        cout << "defense wins 2 dice 2nd dice: " << maxDef2 << " vs  attack: " << maxAtt2 << endl;
                    }
                    else if (maxDef2 < maxAtt2)
                    {
                        troup_def--;
                        cout << "attack wins 2 dice 2nd dice: " << maxAtt2 << " vs  attack: " << maxDef2 << endl;
                    }
                }
            }
            else
            {

                maxDef1 = rollDice();

                if (maxDef1 >= maxAtt1)
                {
                    troup_att--;
                    cout << "defense wins 1 dice: " << maxDef1 << " vs  attack: " << maxAtt1 << endl;
                }
                else
                {
                    troup_def--;
                    cout << "attack wins 1 dice: " << maxAtt1 << " vs  attack: " << maxDef1 << endl;
                }
            }

            cout << endl;

            cout << "att troups:" << troup_att << "\ndef troups:" << troup_def << endl;
            cout << endl;
            // sleep(0.25);
        }
        cout << "\033[2J\033[1;1H";
        cout << "##########################################\n"
             << endl;

        cout << "Attacking remaining: " << troup_att << endl;
        cout << "Defending remaining: " << troup_def << "\n\n\n"
             << endl;

        cout << "Attacing units lost: " << troupAttOld - troup_att << endl;
        cout << "Defending units lost: " << troupDefOld - troup_def << endl;
        cout << endl;

        LostTotalAtt = LostTotalAtt + troupAttOld - troup_att;
        LostTotalDef = LostTotalDef + troupDefOld - troup_def;

        cout << "Total troups lost: Att: " << LostTotalAtt << " Def: " << LostTotalDef << endl;

        cout << "#########################################\n\n\n"
             << endl;

        string tmp;
        cin.clear();
        cout << "troup attack amount: ";
        cin >> troup_att;
    }

    return 0;
}
