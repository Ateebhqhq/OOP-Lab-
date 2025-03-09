#include <iostream>
using namespace std;

class Level {
    string levelName;
public:
    Level(string name) : levelName(name) {}
    void display() 
    { cout << "Level: " << levelName << endl; }
};

class VideoGame {
    string title, genre;
    Level* levels[10];
    int levelCount;
public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}

    ~VideoGame() { for (int i = 0; i < levelCount; i++) delete levels[i]; }
    void addLevel(string name) 
    { 
        if (levelCount < 10) 
        levels[levelCount++] = new Level(name); 
    }

    void display() {
        cout << "Game: " << title << genre << endl;
        for (int i = 0; i < levelCount; i++) levels[i]->display();
    }
};

int main() {
    VideoGame game("GTA 6", "TPS");
    game.addLevel("911");
    game.addLevel("Follow the damn train CJ");
    game.display();
    return 0;
}
