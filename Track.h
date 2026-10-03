#ifndef TRACK_H
#define TRACK_H

#include <string>

class Track {
    private:
        std::string title;
        std::string filePath;
    public:
        // constructor and getters
        Track(std::string trackTitle, std::string path);

        std::string getTitle() const;
        std::string getFilePath() const;
};

#endif