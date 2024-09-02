#ifndef FILESERVICE_HPP
#define FILESERVICE_HPP

#include <string>

class FileService {
public:
    FileService();
    virtual ~FileService() = default;

    virtual void writeFile(const std::string& path, const std::string& message) = 0;
    virtual std::string readFile(const std::string& path) = 0;  // Changed to std::string
};

#endif // FILESERVICE_HPP
