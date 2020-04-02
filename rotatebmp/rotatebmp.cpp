#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define skip(width) (4-(((width*3*8))>>3)&3)
int main(int argc, char** argv) {
    if (argc != 3)
    {
        cerr << "Input error ! \n";
        return 0;
    }

    ifstream fin;
    fin.open(argv[1],ios::in|ios::binary);
    ofstream fout;
    fout.open(argv[2],ios::out|ios::binary);
    if (!fin.is_open() || !fout.is_open())
    {
        cerr << "Open file error ! \n";
        fin.close();
        fout.close();
        return 0;
    }
    
    int bfOffBits;
    int biWidth;
    int biHeight;

    for (int i = 0; i < 10; i++)
    {
        fout.put(fin.get());
    }

    fin.read((char*)(&bfOffBits), sizeof(int));
    fout.write((char*)(&bfOffBits), sizeof(int));

    // cerr << bfOffBits << endl;

    for (int i = 0; i < 4; i++)
    {
        fout.put(fin.get());
    }
    
    fin.read((char *)(&biWidth), sizeof(int));
    fin.read((char *)(&biHeight), sizeof(int));
    fout.write((char *)(&biHeight), sizeof(int));
    fout.write((char *)(&biWidth), sizeof(int));

    for (int i = 0; i < 28; i++)
    {
        fout.put(fin.get());
    }

    // cerr << biWidth << endl << biHeight << endl ;

    for (int i = 0; i < bfOffBits - 54; i++)
    {
        fout.put(fin.get());
    }

cerr << skip(biHeight) << endl;

    char figure[1200][1700][3];

    for (int i = 0; i < biHeight; i++)
    {
        for (int j = 0; j < biWidth; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                figure[i][j][k] = fin.get();
            }
        }
        for (int k = 0; k < skip(biWidth); k++)
        {
            fin.get();
        }
    }
    for (int j = biWidth - 1; j >= 0; j--)
    {
        for (int i = 0; i < biHeight; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                fout.put(figure[i][j][k]);
            }
        }
        for (int k = 0; k < skip(biHeight); k++)
        {
            fout.put('\0');
        }
    }

    fin.close();
    fout.close();
    return 0;
}