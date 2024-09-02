#ifndef ESP32_FILE_SERVICE_HPP
#define ESP32_FILE_SERVICE_HPP


#include "../../domain/Services/FileService.hpp"
#include <FS.h>
#include <SPIFFS.h>
#include <string>

class ESP32FileService : public FileService {
public:
    ESP32FileService(); 
    void writeFile(const std::string& path, const std::string& message) override;
    std::string readFile(const std::string& path) override; // Ensure this matches the base class method
};

#endif // ESP32_FILE_SERVICE_HPP 
