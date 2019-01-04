#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //类unix系统中，对系统调用的封装接口
                    //如提供通用的文件、目录、程序、及进程操作的函数
#include <errno.h> //提供错误号error定义，用于错误处理
#include <sys/socket.h> //提供socket函数及数据结构
#include <sys/types.h> //数据类型定义
#include <netinet/in.h> //定义数据结构sockaddr_in
#include <arpa/inet.h> //提供IP地址转换函数


#define SEEV_PORT 9527

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}
int main(int argc, char *argv[])
{
    int lfd = 0,cfd = 0;  //套接字描述符
    /*其实为一个整数，如所熟悉的0、1、2对应的FILE*结构为stdin、stdout、stderr
         * 记录操作系统函数返回的一个整数作为描述符来标识套接字socket
         * 接着，再以此描述符作为传递参数，调用函数完成某种操作*/
    int ret,i;
    char buf[BUFSIZ],client_IP[1024];

    struct sockaddr_in serv_addr,clit_addr; //IPV4地址结构
    socklen_t clit_addr_len;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SEEV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //服务器端开始建立监听socket描述符，唯一标识一个socket
    //第一个参数protofamily协议域、二type指定socket类型、三protocol指定协议
    //返回socket描述字符位于协议族空间中，但无具体的地址
    //通过bind函数赋予地址，或connect/listen时随机分配

    lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1)
    {
        sys_err("socket error");
    }
    bind(lfd,(struct sockaddr* )&serv_addr,sizeof(serv_addr));

    listen(lfd,128);

    clit_addr_len = sizeof(clit_addr);
    cfd = accept(lfd,(struct sockaddr *)&clit_addr,&clit_addr_len);
    if(cfd == -1)
    {
        sys_err("accept error");
    }
    printf("client ip:%s port:%d\n",
           inet_ntop(AF_INET,&clit_addr.sin_addr.s_addr,client_IP,sizeof(client_IP)),
           ntohs(clit_addr.sin_port));

    while(1)
    {
        ret = read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,ret);

        for(i = 0;i < ret;i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(cfd,buf,ret);
    }

    close(lfd);
    close(cfd);
    return 0;
}
