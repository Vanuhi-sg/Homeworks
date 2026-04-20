#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

const int MAX = 48061;
int countHelp = 0;

struct City {
    string name;
    int population;
    bool used = false;
};

City cities[MAX];
int cityCount = 0;

string trim(string s) {
    while (!s.empty() && isspace(s.front())) s.erase(s.begin());
    while (!s.empty() && isspace(s.back())) s.pop_back();
    return s;
}

string toLowerCase(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

bool cityExists(string name) {
    name = toLowerCase(name);
    for (int i = 0; i < cityCount; i++) {
        if (toLowerCase(cities[i].name) == name) return true;
    }
    return false;
}

bool isUsed(string name) {
    name = toLowerCase(name);
    for (int i = 0; i < cityCount; i++) {
        if (toLowerCase(cities[i].name) == name) {
            return cities[i].used;
        }
    }
    return false;
}

void markUsed(string name) {
    name = toLowerCase(name);
    for (int i = 0; i < cityCount; i++) {
        if (toLowerCase(cities[i].name) == name) {
            cities[i].used = true;
            return;
        }
    }
}

char getFirstLetter(string name) {
    for (char c : name) {
        if (isalpha(c)) return tolower(c);
    }
    return '?';
}

char getLastLetter(string name) {
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isalpha(name[i])) return tolower(name[i]);
    }
    return '?';
}

void loadCSV(string filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return;
    }

    getline(file, line);

    while (getline(file, line) && cityCount < MAX) {
        stringstream ss(line);
        string id, city, lat, lng, country, iso2, iso3, population;

        getline(ss, id, ',');
        getline(ss, city, ',');
        getline(ss, lat, ',');
        getline(ss, lng, ',');
        getline(ss, country, ',');
        getline(ss, iso2, ',');
        getline(ss, iso3, ',');
        getline(ss, population, ',');

        city = trim(city);
        population = trim(population);

        if (city.empty() || population.empty()) continue;

        cities[cityCount].name = city;

        try {
            cities[cityCount].population = stoi(population);
        } catch (...) {
            cities[cityCount].population = 0;
        }

        cityCount++;
    }

    cout << "Loaded cities: " << cityCount << endl;
}

City getBestCity(char lastLetter) {
    int bestIndex = -1;
    int maxPop = -1;

    for (int i = 0; i < cityCount; i++) {
        char first = getFirstLetter(cities[i].name);

        if (first == lastLetter && !cities[i].used) {
            if (cities[i].population > maxPop) {
                maxPop = cities[i].population;
                bestIndex = i;
            }
        }
    }

    if (bestIndex == -1) return {"", 0};

    cities[bestIndex].used = true;
    return cities[bestIndex];
}

City peekBestCity(char lastLetter) {
    int bestIndex = -1;
    int maxPop = -1;

    for (int i = 0; i < cityCount; i++) {
        char first = getFirstLetter(cities[i].name);

        if (first == lastLetter && !cities[i].used) {
            if (cities[i].population > maxPop) {
                maxPop = cities[i].population;
                bestIndex = i;
            }
        }
    }

    if (bestIndex == -1) return {"", 0};

    return cities[bestIndex];
}

void help(char lastLetter){
    if (countHelp >= 5) {
        cout << "No more helps available.\n";
        return;
    }

    City suggestion = peekBestCity(lastLetter);
    countHelp++;

    cout << "Help (" << countHelp << "/5): ";

    if (suggestion.name == "") {
        cout << "No suggestions available\n";
    } else {
        cout << suggestion.name << endl;
    }
}

int main() {
    loadCSV("worldcities.csv");

    string userCity;
    char last = '\0';

    while (true) {
        cout << "\nEnter city: ";
        getline(cin, userCity);

        userCity = trim(userCity);
        string command = toLowerCase(userCity);

        if (command == "i give up") {
            if (countHelp < 5) {
                cout << "You still have helps left! Use 'help'.\n";
                continue;
            } else {
                cout << "Bot wins! Better luck next time.\n";
                break;
            }
        }

        if (command == "help") {
            if (last == '\0') {
                cout << "No previous city to base suggestion on\n";
            } else {
                help(last);
            }
            continue;
        }

        if (userCity.empty()) continue;

        if (!cityExists(userCity)) {
            cout << "City not found in database!\n";
            continue;
        }

        if (isUsed(userCity)) {
            cout << "City already used!\n";
            continue;
        }

        char lastChar = getLastLetter(userCity);

        if (lastChar == '?') {
            cout << "Invalid input\n";
            continue;
        }

        markUsed(userCity);
        last = lastChar;

        City botCity = getBestCity(last);

        if (botCity.name == "") {
            cout << "No city found. You win!\n";
            break;
        }

        cout << "Bot: " << botCity.name << endl;

        last = getLastLetter(botCity.name);
    }

    return 0;
}