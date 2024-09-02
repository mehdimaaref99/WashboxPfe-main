#include "SaveMessageToFile.hpp"

SaveMessageToFileUseCase::SaveMessageToFileUseCase(FileService& fileService) 
    : fileService(fileService) {}

void SaveMessageToFileUseCase::execute(const std::string& filename, const std::string& message) {
    fileService.writeFile(filename, message);
}
