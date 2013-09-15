//
//  main.cpp
//  LuasLingkaran
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    // inisialisasi variable
    float r,l;
    
    cout << "Program C++ | Menghitung Luas Lingkaran\n";
    cout << "---------------------------------------\n";
    
    // Input variabel
    cout << "Masukkan Nilai Jari-Jari : ";
    cin >> r;
    
    
    //proses
    l=r*r*3.14;
    
    
    // Output Variabel
    cout << "Luas Lingkaran Adalah : " << l;
    
    return 0;
}

