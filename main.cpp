#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

void printDice(int dice[], int size) {
    for (int i = 0; i < size; i++) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

bool isYamb(int dice[], int size) {
    int firstDice = dice[0];
    for (int i = 1; i < size; i++) {
        if (dice[i] != firstDice) {
            return false;
        }
    }
    return true;
}

bool isStraight(int dice[], int size) {
    int minDice = dice[0];
    int maxDice = dice[0];
    for (int i = 1; i < size; i++) {
        if (dice[i] < minDice) {
            minDice = dice[i];
        }
        if (dice[i] > maxDice) {
            maxDice = dice[i];
        }
    }
    return (maxDice - minDice == 4);
}

bool isFullHouse(int dice[], int size) {
    bool threeOfAKind = false;
    bool twoOfAKind = false;
    int count[6] = { 0 };
    for (int i = 0; i < size; i++) {
        count[dice[i] - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (count[i] == 3) {
            threeOfAKind = true;
        }
        else if (count[i] == 2) {
            twoOfAKind = true;
        }
    }
    return (threeOfAKind && twoOfAKind);
}

int sumDice(int dice[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += dice[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int dice[5];
    int score = 0;
    int potvrda = 0;
    bool yamb = false;
    bool straight = false;
    bool fullHouse = false;
    while (potvrda == 0) {
        for (int i = 0; i < 5; i++) {
            dice[i] = rollDice();
        }
        printDice(dice, 5);
        yamb = isYamb(dice, 5);
        straight = isStraight(dice, 5);
        fullHouse = isFullHouse(dice, 5);
        if (yamb) {
            cout << "Yamb!" << endl;
            score += 100;
        }
        else if (straight) {
            cout << "Straight!" << endl;
            score += 50;
        }
        else if (fullHouse) {
            cout << "Full house!" << endl;
            score += 30;
        }
        else {
            int sum = sumDice(dice, 5);
            cout << "Sum: " << sum << endl;
            score += sum;
        }
        cout << "Zelis da nastavis?" << endl;
        cout << "Current Score:" << score << endl;
        cin >> potvrda;
    }
    cout << "Final score: " << score << endl;
    return 0;
}
