//
//  main.cpp
//  LuasSegitiga
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>

int main()
{

    float a,t,l;
    std::cout << "Aplikasi C++ | Menghitung Luas Segitiga\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Masukkan Nilai ALas : "; std::cin >> a;
    std::cout << "Masukkan Nilai Tinggi : "; std::cin >> t;
    l=a*t*0.5;
    std::cout << "Luas Segitiga adalah : " << l;
    return 0;
}

