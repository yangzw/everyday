###gdb
1. 在编译源文件时要加入-g选项 g++ test.c -o out -g
2. gdb out 进入调试; l 显示源码; b n_line/func_name 设置断点(行号/函数名); p something 打印; $1 = .. 可以自行设置变量;
3. 具体看[酷壳博客](http://coolshell.cn/articles/3643.html)
