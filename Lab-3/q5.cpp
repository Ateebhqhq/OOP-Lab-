#include <iostream>
using namespace std;

class musicPlayer {
    private:
        string playlist[10];
        string currentSong;


    public:
        void addSong(string song) {
        for (int i = 0; i < 10; i++)
        {

            if(playlist[i] == "") {
                playlist[i] = song;
                return;
            }
        }
        }

        void removeSong(string song) {
            for (int i = 0; i < 10; i++)
        {

            if(playlist[i] == song) {
                playlist[i] = "";
                return;
            }
        }
        }

        void playSong(string song) {
            for (int i = 0; i < 10; i++)
        {

            if(playlist[i] == song) {
                cout << playlist[i] << " is being played" << endl;
                return;
            }
        }
        }

        void displayPlaylist() {
            cout << "The playlist is: " << endl;
            for (int i = 0; i < 10; i++)
        {
            
            cout << "--" << playlist[i] << "--" << endl;
            
            }
        }
        };
        

int main() {
    musicPlayer p1;
    p1.addSong("sanakhudu maarika naa maahum");
    p1.addSong("Jihad Nasheed");
    p1.addSong("Kun anta");
    p1.addSong("Beauty of existence");
    p1.addSong("Way of the tears");
    p1.addSong("Jundullah");
    p1.removeSong("Way of the tears");
    p1.playSong("Kun anta");
    p1.displayPlaylist();
}