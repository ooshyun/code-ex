#include <iostream>
#include <string>
#include <cstdint>
#include <stdexcept>

// Check for filesystem support
#if __has_include(<filesystem>) && __cplusplus >= 201703L
    #include <filesystem>
    #if __cpp_lib_filesystem >= 201703L
        #define HAS_STD_FILESYSTEM 1
        namespace fs = std::filesystem;
    #endif
#elif __has_include(<experimental/filesystem>) && __cplusplus >= 201402L
    #include <experimental/filesystem>
    #if __cpp_lib_experimental_filesystem >= 201406L
        #define HAS_STD_FILESYSTEM 1
        namespace fs = std::experimental::filesystem;
    #endif
#endif

#ifndef HAS_STD_FILESYSTEM
    #ifdef _WIN32
        #include <windows.h>
    #else
        #include <unistd.h>
        #include <limits.h>
    #endif
#endif

#ifndef _WIN32
    #include <sys/statvfs.h>
#endif

std::string getCurrentPath() {
#ifdef HAS_STD_FILESYSTEM
#if __has_include(<filesystem>) && __cplusplus >= 201703L
    std::cout << "Using std::filesystem" << std::endl;
#elif __has_include(<experimental/filesystem>) && __cplusplus >= 201402L
    std::cout << "Using std::experimental::filesystem" << std::endl;
#endif
    return fs::current_path().string();
#else
#ifdef _WIN32 // TODO: not tested
    char buffer[MAX_PATH];
    DWORD length = GetCurrentDirectoryA(sizeof(buffer), buffer);
    if (length == 0) {
        throw std::runtime_error("Failed to get current directory");
    }
    return std::string(buffer);
#else
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) == nullptr) {
        throw std::runtime_error("Failed to get current directory");
    }
    return std::string(buffer);
#endif
#endif
}

uint64_t getFreeSpace(const std::string& path) {
#ifdef _WIN32 // TODO: not tested
    ULARGE_INTEGER freeBytes;
    if (GetDiskFreeSpaceExA(path.c_str(), &freeBytes, NULL, NULL) != 0) {
        return freeBytes.QuadPart;
    }
#else
    struct statvfs stat;
    if (statvfs(path.c_str(), &stat) == 0) {
        return static_cast<uint64_t>(stat.f_bsize) * stat.f_bfree;
    }
#endif
    return 0; // Return 0 if there's an error
}

std::string formatSize(uint64_t size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    double formattedSize = static_cast<double>(size);

    while (formattedSize >= 1024 && unitIndex < 4) {
        formattedSize /= 1024;
        unitIndex++;
    }

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f %s", formattedSize, units[unitIndex]);
    return std::string(buffer);
}

void test_remain_storage(void) {
    std::string path = getCurrentPath();
    uint64_t freeSpace = getFreeSpace(path);
    
    if (freeSpace > 0) {
        std::cout << "Free space in " << path << ": " << formatSize(freeSpace) << std::endl;
    } else {
        std::cout << "Error getting free space for " << path << std::endl;
    }
}