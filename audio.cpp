#include "audio.h"

bool AudioManager::start(const std::string& filename) {
    if (!backgroundMusic.openFromFile(filename)) {
        return false; // failed to load
    }
    backgroundMusic.setLoop(true);   // continuous playback
    backgroundMusic.play();          // start immediately
    return true;
}
