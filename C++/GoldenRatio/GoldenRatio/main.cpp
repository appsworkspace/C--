//
//  main.cpp
//  GoldenRatio
//
//  Created by Rumahproject.com on 9/14/13.
//  Copyright (c) 2013 Rumahproject.com. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{

    int a=0, b=1, c=0, n=20;
    
    for(int i=1; i<=n; i++){
        cout << a << ", " << b << ", " << c << "\n";
        c=a+b;
        b=a;
        a=c;
    }
    
    return 0;
}

