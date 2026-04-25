#pragma once
#include <SFML/Audio.hpp>
#include <string>

class AudioManager {
    sf::Music backgroundMusic;

public:
    // Load and immediately start looping playback
    bool start(const std::string& filename);
};
