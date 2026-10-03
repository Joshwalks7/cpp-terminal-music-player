#include "Playlist.h"
#include <iostream>

using namespace std;

Playlist::Playlist() : currentTrackIndex(0) {}

void Playlist::addTrack(const Track& track) {
    tracks.push_back(track);
}
void Playlist::nextTrack() {
    if (tracks.empty()) return;

    if(currentTrackIndex >= tracks.size() - 1) {
        currentTrackIndex = 0;
    }
    else{
        currentTrackIndex++;
    }
}
void Playlist::previousTrack() {
    if (tracks.empty()) return;

    if(currentTrackIndex == 0) {
        currentTrackIndex = tracks.size() - 1;
    }
    else {
        currentTrackIndex--;
    }
}
Track Playlist::getCurrentTrack() const {
    if(tracks.empty()){
        return Track("No Song Playing", "");
    }
    return tracks[currentTrackIndex];
}
vector<Track> Playlist::getAllTracks() const {
    return tracks;
}
void Playlist::saveToFile(const std::string& filename) const {
    ofstream outFile(filename);
    if(outFile.is_open()) {
        for (const auto& track: tracks) {
            outFile << track.getTitle() << "\n";
            outFile << track.getFilePath() << "\n";
        }
        outFile.close();
    }
}
void Playlist::loadFromFile(const std::string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        tracks.clear();
        string title, path;

        while (getline(inFile, title) && getline(inFile, path)) {
            tracks.push_back(Track(title, path));
        }
        inFile.close();
        currentTrackIndex = 0;
    }
}
void Playlist::removeTrack(int index) {
    if (index >= 0 && index < tracks.size()) {
        tracks.erase(tracks.begin() + index);
        cout << "Track removed successfully!" << endl;
    } else {
        cout << "Invalid track number." << endl;
    }
}

