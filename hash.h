#ifndef HASH_H
#define HASH_H

#include <string>
#include <cstdint>
#include <cstring>

const uint8_t BIT_SIZE = 8;
typedef uint8_t byte_t;

class Hash {
    protected:
        char* result;
        byte_t* inputData;
        uint64_t inputSize;
        Hash();
        void setResult(char*);
    public:
        void setInput(char*);
        //virtual void encode() const = 0;
        char * getResult() { return result; }
};

// rotate right
#define ror(X, n) ( (x >> n) | (x << (32-n)) )
// shift right
#define shr(X, n) ( X >> n )

class Sha256 : public Hash {
    private:
        static const uint8_t SHA256_SIZE = 64;
        static const uint32_t k[];
        uint32_t hashValue[8];
        uint64_t digest = 0;
        uint32_t w[64];
        unsigned get_last_n_bits(unsigned u, int n);
    public:
        Sha256(std::string);
        Hash * encode();
        void init();
        static void selfTest();
};

#endif
