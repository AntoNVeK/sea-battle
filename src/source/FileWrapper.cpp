#include "../headers/FileWrapper.h"

FileWrapper::FileWrapper(const std::string& filename) : filename(filename) {}


void FileWrapper::read(json &jsn)
{
    
    std::ifstream input_file(filename);
    if(!input_file.is_open())
    {
        throw std::runtime_error("Couldn't open file for reading.");
    }

    std::string hash;
    std::getline(input_file, hash);
    std::string data;
    std::getline(input_file, data);

    input_file.close();

    if(sha256(data) != hash)
    {
        throw std::runtime_error("Seems like file was damaged.");
    }

    jsn = json::parse(data);
}

void FileWrapper::write(const json &jsn)
{
    std::string data = jsn.dump();
    std::string hash = sha256(data);

    std::ofstream output_file(filename);
    if(!output_file.is_open())
    {
        throw std::runtime_error("Couldn't open file for writing.");
    }

    output_file << hash << std::endl << data;
    output_file.close();
}

uint32_t FileWrapper::rightRotate(uint32_t value, uint32_t count) {
    return (value >> count) | (value << (32 - count));
}

std::string FileWrapper::sha256(const std::string &str)
{
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    std::vector<uint8_t> message(str.begin(), str.end());

    // Дополнение сообщения
    uint64_t originalLength = message.size() * 8;
    message.push_back(0x80);
    while ((message.size() * 8 + 64) % 512 != 0) {
        message.push_back(0x00);
    }

    // Добавление длины сообщения
    for (int i = 0; i < 8; ++i) {
        message.push_back((originalLength >> (56 - i * 8)) & 0xFF);
    }

    // Обработка сообщения блоками по 512 бит
    for (size_t i = 0; i < message.size(); i += 64) {
        uint32_t w[64];
        for (int j = 0; j < 16; ++j) {
            w[j] = (message[i + j * 4] << 24) | (message[i + j * 4 + 1] << 16) |
                   (message[i + j * 4 + 2] << 8) | (message[i + j * 4 + 3]);
        }
        for (int j = 16; j < 64; ++j) {
            uint32_t s0 = rightRotate(w[j - 15], 7) ^ rightRotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = rightRotate(w[j - 2], 17) ^ rightRotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;
        uint32_t f = h5;
        uint32_t g = h6;
        uint32_t h = h7;

        for (int j = 0; j < 64; ++j) {
            uint32_t S1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h + S1 + ch + K[j] + w[j];
            uint32_t S0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // Формирование результата
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << h0
       << std::hex << std::setw(8) << std::setfill('0') << h1
       << std::hex << std::setw(8) << std::setfill('0') << h2
       << std::hex << std::setw(8) << std::setfill('0') << h3
       << std::hex << std::setw(8) << std::setfill('0') << h4
       << std::hex << std::setw(8) << std::setfill('0') << h5
       << std::hex << std::setw(8) << std::setfill('0') << h6
       << std::hex << std::setw(8) << std::setfill('0') << h7;

    return ss.str();
}

FileWrapper::~FileWrapper() {}