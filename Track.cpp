#include "Track.h"

using namespace std;

Track::Track(string trackTitle, string path) : title(trackTitle), filePath(path) {}

string Track::getTitle() const {
    return title;
}

string Track::getFilePath() const {
    return filePath;
}