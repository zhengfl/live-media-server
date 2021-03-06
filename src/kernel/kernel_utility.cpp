#include "kernel_utility.hpp"
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "DRegExp.hpp"

DString get_peer_ip(int fd)
{
    DString ip;

    // discovery client information
    sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    if (getpeername(fd, (sockaddr*)&addr, &addrlen) == -1) {
        return ip;
    }

    // ip v4 or v6
    char buf[INET6_ADDRSTRLEN];
    memset(buf, 0, sizeof(buf));

    if ((inet_ntop(addr.sin_family, &addr.sin_addr, buf, sizeof(buf))) == NULL) {
        return ip;
    }

    ip = buf;

    return ip;
}

bool check_ip(const DString &str)
{
    DRegExp reg("^(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])$");

    return reg.execMatch(str);
}
