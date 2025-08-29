#include <iostream>
#include <filesystem>
#include <map>
#include <vector>
#include <string>

namespace fs = std::filesystem;

std::map<std::string, std::string> extensionMap = {
    {".jpg", "Images"}, {".png", "Images"}, {".jpeg", "Images"}, {".gif", "Images"},
    {".mp4", "Videos"}, {".mkv", "Videos"}, {".avi", "Videos"},
    {".mp3", "Music"},  {".wav", "Music"},
    {".pdf", "Documents"}, {".docx", "Documents"}, {".txt", "Documents"},
    {".zip", "Archives"}, {".rar", "Archives"}
};

void organize(const fs::path& folder) {
    if (!fs::exists(folder) || !fs::is_directory(folder)) {
        std::cerr << "Folder tidak ditemukan!\n";
        return;
    }

    for (auto& entry : fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string();
            std::string targetDir = "Others";

            if (extensionMap.find(ext) != extensionMap.end()) {
                targetDir = extensionMap[ext];
            }

            fs::path newDir = folder / targetDir;
            fs::create_directories(newDir);

            fs::path newPath = newDir / entry.path().filename();
            try {
                fs::rename(entry.path(), newPath);
                std::cout << "✅ " << entry.path().filename().string()
                          << " → " << targetDir << "\n";
            } catch (fs::filesystem_error& e) {
                std::cerr << " Error memindahkan " 
                          << entry.path().filename().string() 
                          << ": " << e.what() << "\n";
            }
        }
    }
}

int main() {
    std::string folderPath;
    std::cout << " Masukkan path folder yang ingin diorganize: ";
    std::getline(std::cin, folderPath);

    organize(folderPath);

    std::cout << "Selesai!\n";
    return 0;
}
