## 备忘 ##
* 用命令查看gcc、g++编译器的预定义宏变量
gcc -dM -E - < /dev/null
g++ -dM -E - < /dev/null
* 可以自己定义宏变量，通过在编译命令后面添加参数
g++ -o xxx -D USERD main.cpp


## 用VIM查看二进制文件 ##
* vim -b xx
* :%!xxd
* :%!xxd -r 
* 如果想正常退出，不想编辑，两次u取消操作，然后退出