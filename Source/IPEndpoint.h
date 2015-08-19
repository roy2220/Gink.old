#pragma once


#include <netinet/in.h>

#include <cstdint>


struct IPEndpoint
{
    inline explicit IPEndpoint(const sockaddr_in &);

    inline void set(const sockaddr_in &);

    std::uint32_t address;
    std::uint16_t portNumber;
};


IPEndpoint::IPEndpoint(const sockaddr_in &name)
    : address(ntohl(name.sin_addr.s_addr)), portNumber(ntohs(name.sin_port))
{
}


void
IPEndpoint::set(const sockaddr_in &name)
{
    address = ntohl(name.sin_addr.s_addr);
    portNumber = ntohs(name.sin_port);
}
