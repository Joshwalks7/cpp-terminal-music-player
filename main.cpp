#include <iostream>
#include <cstdlib>

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include "Playlist.h"
#include "Track.h"

using namespace std;

void playTrack(ma_engine& engine, ma_sound& sound, bool& isPlaying, const string& path) {
    if (isPlaying) {
        ma_sound_uninit(&sound);
        isPlaying = false;
    }
    if (ma_sound_init_from_file(&engine, path.c_str(), 0, NULL, NULL, &sound) == MA_SUCCESS) {
        ma_sound_start(&sound);
        isPlaying = true;
    } else {
        cout << "Failed to load track from path: " << path << endl;
    }
}

int main() {
    Playlist testPlaylist;
    string command = "";
    ma_engine engine;
    ma_result result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        cout << "Failed to initialize audio engine." << endl;
        return -1;
    }

    ma_sound currentSound;
    bool isPlaying = false;
    
    while (command != "0") {
        cout << "\nWhat would you like to do?\n1. Add Track\n2. View Playlist\n3. Play/Pause Track\n4. Skip Track\n5. Previous Track\n6. Remove Track\n7. Load Playlist from a File\n8. Save Playist to a File\n0. Exit\nChoice: ";
        cin >> command;

        if (command == "1") {
            cin.ignore();

            string title, path;
            cout << "What is the name of the track you are adding? ";
            getline(cin, title);
            cout << "\n";
            cout << "What is the file path? ";
            getline(cin, path);
            Track testTrack(title, path);
            testPlaylist.addTrack(testTrack);
        }
        else if (command == "2") {
            cout << "Current Playlist:" << endl;
            int count = 1;
            for (const auto& track : testPlaylist.getAllTracks()) {
                cout << count << ". " << track.getTitle() << endl;
                count++;
            }
        }
        else if (command == "3") {
            if (!isPlaying) {
                string path = testPlaylist.getCurrentTrack().getFilePath();
                playTrack(engine, currentSound, isPlaying, path);
            } else if (ma_sound_is_playing(&currentSound)) {
                ma_sound_stop(&currentSound); // Pauses at current position
                cout << "Paused." << endl;
            } else {
                ma_sound_start(&currentSound); // Resumes from current position
                cout << "Resumed playback." << endl;
            }
        }
        else if (command == "4") {
            testPlaylist.nextTrack();
            string path = testPlaylist.getCurrentTrack().getFilePath();
            playTrack(engine, currentSound, isPlaying, path);
            Track track = testPlaylist.getCurrentTrack();
            cout << "Now playing: \"" << track.getTitle() << "\" from " << track.getFilePath() << endl;
        }
        else if (command == "5") {
            testPlaylist.previousTrack();
            string path = testPlaylist.getCurrentTrack().getFilePath();
            playTrack(engine, currentSound, isPlaying, path);
            Track track = testPlaylist.getCurrentTrack();
            cout << "Now playing: \"" << track.getTitle() << "\" from " << track.getFilePath() << endl;
        }
        else if (command == "6") {
            if (testPlaylist.getAllTracks().empty()) {
                cout << "Playlist is empty." << endl;
            } else {
                int count = 1;
                for (const auto& track : testPlaylist.getAllTracks()) {
                    cout << count << ". " << track.getTitle() << endl;
                    count++;
                }

                int trackNum;
                cout << "Enter the number of the track to remove: ";
                cin >> trackNum;

                testPlaylist.removeTrack(trackNum - 1);
            }
        }
        else if (command == "7") {
            string loadFilename;
            cout << "What file would you like to load your playlist from? ";
            cin >> loadFilename;
            testPlaylist.loadFromFile(loadFilename);
        }
        else if (command == "8") {
            string saveFilename;
            cout << "What file would you like to save your playlist to? ";
            cin >> saveFilename;
            testPlaylist.saveToFile(saveFilename);
            cout << "Playlist saved to " << saveFilename << " successfully!\n";
        }
    }
    return 0;
}