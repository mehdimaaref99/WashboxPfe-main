#include "FileService.hpp"
#include "SPIFFS.h"

FileService::FileService() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
    }
}

void FileService::writeFile(const std::string& path, const std::string& message) {
    File file = SPIFFS.open(path.c_str(), FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.println(message.c_str());
    file.close();
}

std::string FileService::readFile(const std::string& path) {
    File file = SPIFFS.open(path.c_str(), FILE_READ);
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
