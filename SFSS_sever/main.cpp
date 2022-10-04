//
//  main.cpp
//  SFSS_sever
//
//  Created by G jh on 2022/10/4.
//

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<queue>
#pragma comment (lib,"ws2_32.lib")

const int SIZE = 101;
int to_int(const char *ss){
    int len = strlen(ss);
    int sum = 0;
    for(int i=0;i<len;i++){
        sum+=(ss[i]^48);
        sum=(sum<<3)+(sum<<1);
    }
    return sum;
}
int num_receive;
int num_sender;
sockaddr queue_receive[SIZE];
sockaddr queue_sender[SIZE];
int sender_load[SIZE];

void dynamic_balance(){
    //priority<int>load;
    
}
void customer(int state,const sockaddr *addr){
    if(state==0){
        queue_receive[++num_receive]=(*addr);
    }
    if(state==1){
        queue_sender[++num_sender]=(*addr);
    }
    
}
void state_jump(int state){
    if(state==0||state==1){
        
    }
    if(state==3){
        
    }
    
}
int main(int argc, const char * argv[]){
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in sever_Adder;
    std:: memset(&sever_Adder, 0, sizeof(sever_Adder));
    sever_Adder.sin_family = PF_INET;
    sever_Adder.sin_port = htons(8080);
    sever_Adder.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock, (sockaddr*)&sever_Adder, sizeof(sever_Adder));
    sockaddr rec;
    socklen_t rec_Size = sizeof(sockaddr);
    while(true){
        char buffer;
        int rec_state =recvfrom(sock,&buffer, 1, 0, &rec, &rec_Size);
        to_int(&buffer);
        
    }
}
//int main(int argc, const char * argv[]) {
//    int sock = socket(AF_INET, SOCK_DGRAM, 0);
//    sockaddr_in server_Addr;
//    std:: memset(&server_Addr, 0, sizeof(server_Addr));
//    server_Addr.sin_family = PF_INET;
//    server_Addr.sin_addr.s_addr = htonl(INADDR_ANY);
//    server_Addr.sin_port = htons(8080);
//    bind(sock, (sockaddr*)&server_Addr, sizeof(sockaddr));
//    sockaddr clint_Addr;
//    int clint_Size = sizeof(clint_Addr);
//    char buffer[SIZE];
//    while(true){
//        int str = recvfrom(sock, buffer, SIZE, 0, clint_Addr, clint_Size);
//        sendto(sock, buffer, str, 0, &clint_Addr, clint_Size);
//
//    }
//    return 0;
//}
