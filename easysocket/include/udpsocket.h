#ifndef FDR_UDPSOCKET_H
#define FDR_UDPSOCKET_H

#include <DllHelper.h>

#include <basesocket.h>
#include <string>
#include <functional>
#include <thread>

constexpr uint16_t BUFFER_SIZE = 0xFFFF;

class EASYSOCKET_API UDPSocket : public BaseSocket
{
public:
    std::function<void(std::string, std::string, std::uint16_t)> onMessageReceived;
    std::function<void(const char*, int, std::string, std::uint16_t)> onRawMessageReceived;

    explicit UDPSocket(FDR_ON_ERROR, int socketId = -1);

    void SendTo(std::string message, std::string host, uint16_t port, FDR_ON_ERROR);
    void SendTo(const char *bytes, size_t byteslength, std::string host, uint16_t port, FDR_ON_ERROR);

private:
    static void Receive(UDPSocket *udpSocket);
};

#endif
