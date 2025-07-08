#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;

    Song(string t, string a) : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* currentSong;

public:
    Playlist() : head(nullptr), tail(nullptr), currentSong(nullptr) {}

    void addSong(const string& title, const string& artist) {
        Song* newSong = new Song(title, artist);
        if (head == nullptr) {
            head = tail = currentSong = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added: " << title << " by " << artist << endl;
    }

    void displayPlaylist() const {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* temp = head;
        cout << "--- Current Playlist ---" << endl;
        while (temp != nullptr) {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist;
            if (temp == currentSong) {
                cout << " (Currently Playing)";
            }
            cout << endl;
            temp = temp->next;
        }
        cout << "------------------------" << endl;
    }

    void playNext() {
        if (currentSong == nullptr) {
            cout << "Playlist is empty. Cannot play next." << endl;
            return;
        }
        if (currentSong->next != nullptr) {
            currentSong = currentSong->next;
            cout << "Now playing: " << currentSong->title << " by " << currentSong->artist << endl;
        } else {
            cout << "End of playlist. No next song." << endl;
        }
    }

    void playPrevious(int steps = 1) {
        if (currentSong == nullptr) {
            cout << "Playlist is empty. Cannot play previous." << endl;
            return;
        }
        while (steps-- > 0 && currentSong->prev != nullptr) {
            currentSong = currentSong->prev;
        }
        cout << "Now playing: " << currentSong->title << " by " << currentSong->artist << endl;
    }

    
    void playCurrent() const {
        if (currentSong) {
            cout << "Now playing: " << currentSong->title << " by " << currentSong->artist << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    ~Playlist() {
        Song* temp = head;
        while (temp != nullptr) {
            Song* nextSong = temp->next;
            delete temp;
            temp = nextSong;
        }
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Bohemian Rhapsody", "Queen");
    myPlaylist.addSong("Stairway to Heaven", "Led Zeppelin");
    myPlaylist.addSong("Hotel California", "Eagles");
    myPlaylist.addSong("Imagine", "John Lennon");
    myPlaylist.addSong("Sweet Child O' Mine", "Guns N' Roses");

    myPlaylist.displayPlaylist();

    myPlaylist.playNext();           
    myPlaylist.playNext();          
    myPlaylist.playPrevious(2);      
    myPlaylist.playNext();           
    myPlaylist.playPrevious();       

    myPlaylist.displayPlaylist();

    return 0;
}
