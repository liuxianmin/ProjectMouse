//
//  mouseDBFile.cpp
//  Mouse
//
//  Created by Xianmin Liu on 2019/12/7.
//  Copyright © 2019年 Xianmin Liu. All rights reserved.
//

#include "mouseDBFile.hpp"

#include <fcntl.h>
#include <unistd.h>


namespace mouse {
namespace filesys{
    
    DBFile::DBFile(const char* name, PageID in_num_pages, int in_page_size)
    {
        /// Check whether in_num_pages or in_page_size smaller than 0
        if (in_num_pages < 0 || in_page_size < 0)
        {
            std::cout << "Error_Mouse_Filesys: page number and size can not be smaller than 0!" << std::endl;
            return;
        }
        /// Create the file; fail if it's already there; open it in read/write mode.
        fd = open( name, O_RDWR | O_CREAT, 0666 );

        num_pages = in_num_pages;
        page_size = in_page_size;
        
        if ( fd < 0 ) {
            std::cout << "Error_Mouse_Filesys: error in open file." << std::endl;
            return;
        }
    }
    
    DBFile::~DBFile()
    {
        close(fd);
        fd = -1;
    }
    
    void DBFile::db_read_page(PageID pageno, PagePtr pageptr)
    {
        if ( pageno < 0 || pageno >= num_pages ){
            std::cout << "Error_Mouse_Filesys: no such page: pageno=" << pageno << ", #page=" <<num_pages << std::endl;
            return;
        }
        
        // Seek to the correct page
        lseek( fd, pageno*page_size, SEEK_SET );
        
        // Read the appropriate number of bytes.
        read(fd, pageptr, page_size);
    }
    
    void DBFile::db_write_page(PageID pageno, PagePtr pageptr)
    {
        if ( pageno < 0 || pageno >= num_pages ){
            std::cout << "Error_Mouse_Filesys: no such page: pageno=" << pageno << ", #page=" <<num_pages << std::endl;
            return;
        }
        
        // Seek to the correct page
        lseek( fd, pageno*page_size, SEEK_SET );
        
        // Write the appropriate number of bytes.
        write( fd, pageptr, page_size );
    }
    
    
    void DBFile::read_page(PageID pageno, Page* pageptr)
    {
        db_read_page(pageno, pageptr);
    }
    
    void DBFile::write_page(PageID pageno, Page* pageptr)
    {
        db_write_page(pageno, pageptr);
    }
    
} // namespace filesys
} // namespace mouse
