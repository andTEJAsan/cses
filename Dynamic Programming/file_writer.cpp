#include <fstream>

int main() {
    std::ofstream outFile("input.txt");
    
    if (outFile.is_open()) {
        outFile << "1000 1\n";
        for (size_t i = 0; i < 999; i++)
        {
            outFile << "1 ";
        }
        outFile<< "1\n";
        for (size_t i = 0; i < 999; i++)
        {
            outFile << "1 ";
        }
        outFile<< "1\n";
       
    } else {
        // Failed to open the file, handle the error
    }

    return 0;
}
