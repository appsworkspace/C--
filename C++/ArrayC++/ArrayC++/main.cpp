//
//  main.cpp
//  ArrayC++
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    // array     0   1   2   3   4
    int angka[]={12, 23, 45, 67, 56};
    
    for (int i=0; i<5; i++) {
        cout << "Array [" << i << "] = " << angka[i] << "\n";
    }
    
    return 0;
}

