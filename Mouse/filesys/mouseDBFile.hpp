//
//  mouseDBFile.hpp
//  Mouse
//
//  Created by Xianmin Liu on 2019/12/7.
//  Copyright © 2019年 Xianmin Liu. All rights reserved.
//

#ifndef mouseDBFile_hpp
#define mouseDBFile_hpp

#include "common/commons.h"
#include <iostream>


namespace mouse {
namespace filesys{
class DBFile
{
public:
    DBFile(const char* name, PageID num_pages, int page_size);
    virtual ~DBFile();
    
    void db_write_page(PageID pageno, PagePtr pageptr);
    void db_read_page(PageID pageno, PagePtr pageptr);
    
    void write_page(PageID pageno, Page* pageptr);
    void read_page(PageID pageno, Page* pageptr);
private:
    /// posix file handle
    int fd; //the handle of file
    PageID num_pages = 0;
    int page_size = 0;
    
};
} // namespace filesys
} // namespace mouse

#endif /* mouseDBFile_hpp */
