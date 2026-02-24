#include <iostream>
#include <fstream> //dosya islemleri icin
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile("s1"); //okuma
    if (!infile)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 2;
    }
    std::ofstream outfile("s2"); //oluşturma ve yazma
    if (!outfile)
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return 3;
    }


    
}
//3 parametre alacak
//./file_replace <filename> <s1> <s2>
//s1 yerine s2 koyacak
//`std::string` sınıfının tüm üye fonksiyonlarına izin verilir, `replace` fonksiyonu hariç.