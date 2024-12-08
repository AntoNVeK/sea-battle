#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

using json = nlohmann::json;

class FileWrapper {
private:
    std::string filename;
    
public:
    FileWrapper(const std::string& filename);

    void write(const json& j);

    void read(json& j);

    ~FileWrapper();

private:
    std::string sha256(const std::string &str);
};

#endif