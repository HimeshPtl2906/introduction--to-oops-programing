#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Playlist {
public:
    string name;

    Playlist() {
        name = "My Favourites";
        cout << "Welcome! Your playlist \"" << name << "\" has been created." << endl;
    }


    ~Playlist() {
        ofstream outFile("autosave.txt");
        if (outFile.is_open()) {
            outFile << "Playlist auto-saved: " << name << endl;
            outFile.close();
            cout << "Auto-saving \"" << name << "\" to autosave.txt..." << endl;
        } else {
            cout << "Error: Could not open file for auto-save." << endl;
        }
    }
};

int main() {
    {
        Playlist myPlaylist; 
        cout << "Playlist Name: " << myPlaylist.name << endl;
        cout << "Enjoy your music!" << endl;
    } 

    cout << "Program finished. Check autosave.txt for saved data." << endl;

    return 0;
}