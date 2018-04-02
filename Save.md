## 备忘 ##
* 用命令查看gcc、g++编译器的预定义宏变量
gcc -dM -E - < /dev/null
g++ -dM -E - < /dev/null
* 可以自己定义宏变量，通过在编译命令后面添加参数
g++ -o xxx -D USERD main.cpp
