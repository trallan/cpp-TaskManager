#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void readFile(const std::string& filename)
{
    std::string text;
    std::ifstream file(filename);


    // Check if file has ".json" extension
    if (filename.size() < 5 || filename.substr(filename.size() - 5) != ".json")
    {
        std::cerr << "Error: Only .json files are accepted.\n";
        return;
    }

    // Check if the file is opened
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'.\n";
        return;
    }

    while (getline (file, text))
    {
        if (text.find("\"id\"") != std::string::npos ||
            text.find("\"task\"") != std::string::npos ||
            text.find("\"desc\"") != std::string::npos)
        {
            std::cout << text << std::endl;
        }
    }

    file.close();
};


int main(int argc, char* argv[]) {

    std::string filename = argv[1];
    readFile(filename);

    return 0;
}