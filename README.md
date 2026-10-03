# C++ Terminal Music Player

Who needs Spotify when you can easily play audio files from the terminal? This program lets you load audio files into a Track object, save it in a Playlist, and start/pause/skip/reverse songs. Data is persistent when the user chooses to save it to a file.

## Instructions for Build and Use

Steps to build and/or run the software:

1. Ensure `g++` (MinGW / GCC) and VS Code are installed and accessible in your system's PATH.
2. Open a terminal inside the project directory (`sprint1`).
3. Compile the source files using g++:
   `g++ main.cpp Track.cpp Playlist.cpp -o sprint1`
4. Run the generated executable:
   * Windows: `.\sprint1.exe`
   * Linux/macOS: `./sprint1`

Instructions for using the software:

1. Use option `1` to manually add tracks (Title and File Path) or option `7` to load an existing saved playlist file.
2. Select option `3` to start or pause audio playback.
3. Use option `4` (Skip) or option `5` (Previous) to navigate through your loaded tracks.
4. View playlist with option `2` and remove tracks with option `6`
4. Select option `8` before exiting to save your updated playlist to a `.txt` file for future sessions.

## Development Environment

To recreate the development environment, you need the following software and/or libraries with the specified versions:

* **Compiler:** `g++` (MinGW-w64 / GCC version supporting C++11 or higher)
* **IDE/Editor:** Visual Studio Code with the C/C++ extension
* **Audio Engine Library:** `miniaudio.h` (Single-header C library by David Reid)

## Useful Websites to Learn More

I found these websites useful in developing this software:

* [Caleb Curry Youtube Channel](https://www.youtube.com/watch?v=0NwsayeOsd4)
* [w3schools Tutorials](https://www.w3schools.com/cpp/)
* [Pixabay Royalty Free Music](https://pixabay.com/)

## Future Work

The following items I plan to fix, improve, and/or add to this project in the future:

* [ ] Ability to shuffle playlist
* [ ] Freedom to have multiple playlist loaded at one time
* [ ] Ability for songs to auto-play the next in queue upon completion
* [ ] Stat recording/analysis for track frequency