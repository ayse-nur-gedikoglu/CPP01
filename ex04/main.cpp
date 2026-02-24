#include <iostream>
#include <fstream> //dosya islemleri icin
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <from> <to>" << std::endl;
        return 1;
    }
    std::string file = argv[1];
    std::string from = argv[2]; //bu stringin yerine to konacak
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
    while (std::getline(src, line)) //nereden okuyacak, nereye yazacak
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
//3 parametre alacak
//./file_replace <file> <string1> <string2>
//string1 yerine string2 koyacak
//`std::string` sınıfının tüm üye fonksiyonlarına izin verilir, `replace` fonksiyonu hariç.

//eğer ofstream olan bir dosya adına calıstırılırsa üstüne yazar.
//std::getline dosyadan (veya herhangi bir stream'den) 
//bir satır okur ve onu bir string'e atar.

//find aradıgı seyi bulmazsa npos döner. bulubamadı deme
//find(aranan, baslangıc pozisyonu)
