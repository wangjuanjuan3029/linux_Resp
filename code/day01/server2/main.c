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

#define MAXLINE 255 //最大接受字节数

/*一切皆socket*/
/*socket套接字概念介绍*/
/*Unix/Linux基本哲学：“一切皆文件”
 * Socket就是该模式的实现，是一种特殊的文件
 * 一些socket函数就是对其进行操作,如读写，打开，关闭
 * socket为应用层与TCP/IP协议族通信的中间软件抽象层，是一组接口
 * 让socket去组织数据，以符合指定的协议*/


int main(int argc,char** argv)
{
    int lis_fd,con_fd; //套接字描述符
    /*其实为一个整数，如所熟悉的0、1、2对应的FILE*结构为stdin、stdout、stderr
     * 记录操作系统函数返回的一个整数作为描述符来标识套接字socket
     * 接着，再以此描述符作为传递参数，调用函数完成某种操作*/

    struct sockaddr_in serv_addr,clit_addr; //IPV4地址结构
    socklen_t clit_len;
    char buf[MAXLINE]={0}; //缓冲区
    int i,n,port;

    if(argc<3){
        printf("please fill the parameter\n");
        return 1;
    }
    //服务器端开始建立监听socket描述符，唯一标识一个socket
    //第一个参数protofamily协议域、二type指定socket类型、三protocol指定协议
    //返回socket描述字符位于协议族空间中，但无具体的地址
    //通过bind函数赋予地址，或connect/listen时随机分配
    if(-1 == (lis_fd=socket(AF_INET,SOCK_STREAM,0))){
        perror("socket error\n");
        exit(1);
    }
    //初始化
    bzero(&serv_addr,sizeof(serv_addr));
    //memset(&serv_addr,0,sizeof(serv_addr));

    //服务器填充sockaddr结构
    serv_addr.sin_family=AF_INET; //设置地址类型 IPV4
    //serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); //设置IP地址，让系统自动获取本机IP地址
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    port=atoi(argv[2]);
    serv_addr.sin_port=htons(port); //设置默认端口号

    //函数bind将服务器的本地地址和套接字绑定
    if(-1==bind(lis_fd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr))){
        perror("bind error\n");
        exit(1);
    }
    //listen函数提醒内核，此套接字可接受客户端请求，开始监听
    if(listen(lis_fd,10)==-1){ //第二个参数为socket可排队的最大连接数
        perror("listen error\n");
        exit(1);
    }

    printf("========waiting for client's request===========\n");

    /*处理客户端请求，通过accept函数获得与一个客户端的连接*/
    clit_len=sizeof(struct sockaddr_in);
    //accept返回的是已连接socket套接字描述符，不同于之前的监听描述符，且默认阻塞进程
    if(-1==(con_fd=accept(lis_fd,(struct sockaddr*)&clit_addr,&clit_len))){
        perror("accept error\n");
        exit(1);
    }
    printf("connect from %s:%u...!\n",inet_ntoa(clit_addr.sin_addr),ntohs(clit_addr.sin_port));

    while(1){
        //接受客户端发送来的数据
        memset(buf,0,MAXLINE);
        if((n=recv(con_fd,buf,MAXLINE,0))==0){
            sleep(1); //linux的sleep默认睡1秒
            continue;
        }

        buf[n]=0;
        printf("recv msg from client: %s\n",buf);
        if(0 == strncmp(buf,"quit",4)){
            break;
        }
        if(0 == strncmp(buf,"send",4)){
            memset(buf,0,MAXLINE);
            scanf("%s",&buf);
            send(con_fd,buf,strlen(buf),0);
        }
    }
    close(con_fd);
    close(lis_fd);
    exit(0);
}
