#include "ESP32FileService.hpp"
#include "SPIFFS.h"

ESP32FileService::ESP32FileService() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
    }
}

void ESP32FileService::writeFile(const std::string& path, const std::string& message) {
    File file = SPIFFS.open(path.c_str(), FILE_APPEND); // Convert std::string to const char*
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.println(message.c_str()); // Convert std::string to const char*
    file.close();
}

std::string ESP32FileService::readFile(const std::string& path) {
    File file = SPIFFS.open(path.c_str(), FILE_READ); // Convert std::string to const char*
    if (!file) {
        Serial.println("Failed to open file for reading");
        return "";
    }
    std::string fileContent;
    while (file.available()) {
        fileContent += char(file.read());
    }
    file.close();
    return fileContent;
}
