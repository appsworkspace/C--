//
//  main.cpp
//  NilaiGenap
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    
    int a=100, b=0;
    for (int i=1; i<=a; i++) {
        
        b=i%2; // cek apakah i habis dibagi dua
        
        if(b!=0){ // jika b tidak sama dengan 0 maka tampilakan i
            std::cout << i << "\n";
        }
    }
    
    return 0;
}