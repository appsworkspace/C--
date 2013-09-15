//
//  main.cpp
//  LuasPersegiPanjang
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    float p,l,L;
    
    std::cout << "Aplikasi C++ | Menghitung Luas Persegi Panjang\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "Masukkan Nilai Panjang : "; std::cin >> p;
    std::cout << "Masukkan Nilai Lebar   : "; std::cin >> l;
    L=p*l;
    std::cout << "Luas Persegi Panjang adalah : " << L;
    return 0;
}

