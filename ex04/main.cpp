#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <from> <to>" << std::endl;
        return 1;
    }
    std::string file = argv[1];
    std::string from = argv[2];
    std::string to = argv[3];
    if (from.empty())
    {
        std::cerr << "Error: search string cannot be empty." << std::endl;
        return 2;
    }
    std::ifstream src(file.c_str()); //okuma
    if (!src)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 3;
    }
    std::ofstream dest(file + ".replace"); //oluşturma ve yazma
    if (!dest)
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return 4;
    }
    size_t pos;
    std::string line;
    while (std::getline(src, line))
    {
        pos = 0;
        while ((pos = line.find(from, pos)) != std::string::npos)
        {
            line.erase(pos, from.length());
            line.insert(pos, to);
            pos += to.length();
        }
        dest << line << '\n';
    }
    src.close();
    dest.close();
    return 0;
}
