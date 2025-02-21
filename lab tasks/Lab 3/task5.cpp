#include <iostream>
#include <string>

using namespace std;

class AudioPlayer {
private:
    string tracklist[10];
    string nowPlaying;
    int trackCount;

public:
    AudioPlayer() : trackCount(0), nowPlaying("No track playing") {}

    void insertTrack(string track) {
        if (trackCount < 10) {
            tracklist[trackCount++] = track;
            cout << "Inserted track: " << track << endl;
        } else {
            cout << "Tracklist is full! Cannot insert more tracks.\n";
        }
    }

    void deleteTrack(string track) {
        bool found = false;
        for (int i = 0; i < trackCount; i++) {
            if (tracklist[i] == track) {
                found = true;
                for (int j = i; j < trackCount - 1; j++) {
                    tracklist[j] = tracklist[j + 1];
                }
                trackCount--;
                cout << "Deleted track: " << track << endl;
                if (nowPlaying == track) {
                    nowPlaying = "No track playing";
                }
                break;
            }
        }
        if (!found) {
            cout << "Track \"" << track << "\" not found in tracklist.\n";
        }
    }

    void startTrack(string track) {
        bool found = false;
        for (int i = 0; i < trackCount; i++) {
            if (tracklist[i] == track) {
                nowPlaying = track;
                cout << "Now playing: " << track << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Track \"" << track << "\" is not in the tracklist.\n";
        }
    }

    void showTracklist() {
        cout << "\nTracklist:\n";
        if (trackCount == 0) {
            cout << "No tracks in the tracklist.\n";
        } else {
            for (int i = 0; i < trackCount; i++) {
                cout << i + 1 << ". " << tracklist[i] << endl;
            }
        }
    }

    void nowPlayingTrack() {
        cout << "\nNow Playing: " << nowPlaying << endl;
    }
};

int main() {
    AudioPlayer imransPlayer;

    imransPlayer.insertTrack("Kamariya");
    imransPlayer.insertTrack("Meri Saas ke teen bete");
    imransPlayer.insertTrack("Wildflower");

    imransPlayer.showTracklist();

    imransPlayer.startTrack("Kamariya");
    imransPlayer.nowPlayingTrack();

    imransPlayer.deleteTrack("Meri Saas ke teen bete");
    imransPlayer.showTracklist();

    imransPlayer.startTrack("Kamariya");

    return 0;
}

