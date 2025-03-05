#include <iostream>

using namespace std;

class Level {
    string name;
    int difficulty;

public:
    Level(string name, int difficulty) : name(name), difficulty(difficulty) {}

    void display() {
        cout << "-------------------------" << endl;
        cout << "Level: " << name << endl;
        cout << "Difficulty: " << difficulty << "/10" << endl;
    }
};

class VideoGame {
    string title;
    string genre;
    Level** levels;  
    int numLevels;
    int capacity;

public:
    VideoGame(string title, string genre, int capacity) : title(title), genre(genre), numLevels(0), capacity(capacity) {
        levels = new Level*[capacity]; 
    }

    ~VideoGame() {
        for (int i = 0; i < numLevels; i++) {
            delete levels[i];  
        }
        delete[] levels; 
        cout << "Game '" << title << "' is deleted, all levels removed!" << endl;
    }

    void addLevel(string name, int difficulty) {
        if (numLevels < capacity) {
            levels[numLevels] = new Level(name, difficulty);
            numLevels++;
        } else {
            cout << "Cannot add more levels! Maximum capacity reached." << endl;
        }
    }

    void display() {
        cout << "=========================" << endl;
        cout << "Game Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Levels: " << numLevels << endl;
        cout << "=========================" << endl;

        if (numLevels == 0) {
            cout << "No levels added yet!" << endl;
        } else {
            for (int i = 0; i < numLevels; i++) {
                levels[i]->display();
            }
        }
    }
};

int main() {
    VideoGame game("Legend of Code", "Adventure", 5);

    game.addLevel("Forest of Debugging", 3);
    game.addLevel("Desert of Bugs", 5);
    game.addLevel("Final Boss: Segmentation Fault", 9);

    game.display();

    return 0; 
	}


