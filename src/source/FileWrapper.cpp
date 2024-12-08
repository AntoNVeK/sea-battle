#include "../headers/FileWrapper.h"

FileWrapper::FileWrapper(const std::string& filename) : filename(filename) {}


void FileWrapper::read(json &jsn)
{
    
    std::ifstream input_file(filename);
    if(!input_file.is_open())
    {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        throw std::runtime_error("Couldn't open file for reading.");
    }

    input_file >> jsn;
    input_file.close();
}

void FileWrapper::write(const json &jsn)
{
    std::ofstream output_file(filename);
    if(!output_file.is_open())
    {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        throw std::runtime_error("Couldn't open file for writing.");
    }

    output_file << jsn.dump(4);
    output_file.close();
}


std::string FileWrapper::sha256(const std::string &str)
{
    CryptoPP::SHA256 hash;
    CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];

    hash.CalculateDigest(digest, (const CryptoPP::byte*)str.c_str(), str.length());

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach(new CryptoPP::StringSink(output));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return output;
}

FileWrapper::~FileWrapper() {}