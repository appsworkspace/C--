//
//  main.cpp
//  BilanganGanjilGenapIF
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    int a=0, i=1,b=0;
    std::string gengan="";
    std::cout << "Masukkan Nilai : "; std::cin >> a;
    while(i<=a){
        
        b=i%2;
        
        if(b==0){
            gengan="Genap";
        }else{
            gengan="Ganjil";
        }
       std::cout << i << "(" << gengan << ")\n";
        i++;
    }
    
    return 0;
}

