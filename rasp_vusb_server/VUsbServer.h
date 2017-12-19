#pragma once

#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

// On raspberry pi zero,
// sudo apt-get install g++-4.8 
#include <thread>

// https://wiki.openssl.org/index.php/Simple_TLS_Server
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "UsbEmulator.h"

using namespace std;

class VUsbServer
{
public:
    VUsbServer();
    ~VUsbServer();

    bool open();
    void startService();
    void dispose();

private:
    int _sock;
    sockaddr_in _server_addr;
    UsbEmulator _emulator;

    SSL_CTX *_sslContext;

    bool ReadData(SSL *ssl, char *buf, int len);
    void init_openssl();
    void cleanup_openssl();
    void free_sslctx();
};

