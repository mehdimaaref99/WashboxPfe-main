#ifndef SAVE_MESSAGE_TO_FILE
#define SAVE_MESSAGE_TO_FILE

#include <string>
#include "../domain/Services/FileService.hpp"

class SaveMessageToFileUseCase {
public:
    SaveMessageToFileUseCase(FileService& fileService);

    void execute(const std::string& filename, const std::string& message);

private:
    FileService& fileService;
};

#endif
