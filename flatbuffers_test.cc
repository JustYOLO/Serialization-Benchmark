#include <fstream>
#include <iostream>
#include <vector>
#include "flatbuffers/flatbuffers.h"
#include "person_generated.h"

// Function to serialize data and save to file
size_t serializeToFile(const std::string& filename, const std::string& name, short age) {
    flatbuffers::FlatBufferBuilder builder;

    auto nameOffset = builder.CreateString(name);
    auto person = MyGame::CreatePerson(builder, nameOffset, age);
    builder.Finish(person);

    uint8_t *buf = builder.GetBufferPointer();
    size_t size = builder.GetSize();

    std::ofstream file(filename, std::ios::binary);

    file.write(reinterpret_cast<char*>(buf), size);
    file.close();

    std::cout << "Data serialized and saved to file. Size: " << size << " bytes" << std::endl;
    return size;
}

// Function to read from file and deserialize data
bool deserializeFromFile(const std::string& filename, int fileSize) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return false;
    }

    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);

    auto person = MyGame::GetPerson(buffer.data());

    std::cout << "Deserialized data:" << std::endl;
    std::cout << "Name: " << person->name()->c_str() << std::endl;
    std::cout << "Age: " << person->age() << std::endl;

    return true;
}

int main() {
    const std::string filename = "person.bin";

    // Serialize and save to file
    size_t size = serializeToFile(filename, "Alice", 30);

    // Read from file and deserialize
    if (!deserializeFromFile(filename, size)) {
        return 1;
    }

    return 0;
}