//
//  main.cpp
//  Mouse
//
//  Created by Xianmin Liu on 2019/12/7.
//  Copyright © 2019年 Xianmin Liu. All rights reserved.
//

#include <iostream>
#include <string>

#include <unistd.h>
#include "filesys/mouseDBFile.hpp"

void testDBFile(const char * s)
{
    mouse::filesys::DBFile db = mouse::filesys::DBFile(s, 4, 4096);
    char * p=(char *)malloc(4096);
    memset(p, 1, 4096);
    
    db.db_write_page(0, p);
    
}

int main(int argc, const char * argv[]) {
    std::cout << "Parameter Size: " << argc << std::endl;
    for (int i=0 ;i<argc;i++)
        std::cout << "Parameter " << i<<": "<< argv[i] << std::endl;
    std::cout << "Hello!\n";
    if (argc > 1)
    {
        std::string filename = argv[1];
        filename+="1.txt";
        testDBFile(filename.c_str());
    }

    
    char * p=(char *)malloc(4096);
    memset(p, 0, 4096);
    std::cout << "Current path: " << getcwd(p,4096) << std::endl;
    std::cout << "World!\n";
    return 0;
}
