#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <string>
#include <fstream>
#include "Track.h"

class Playlist {
    private:
        std::vector<Track> tracks;
        int currentTrackIndex;
    public:
        Playlist();
        void addTrack(const Track& track);
        Track getCurrentTrack() const;
        void nextTrack();
        void previousTrack();
        std::vector<Track> getAllTracks() const;
        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);
        void removeTrack(int index);
};

#endif