
#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"
#include "../../Application/Server/Message/message.hpp"
#include "TcpNetworking/simpletcpendpoint.hpp"
#include "../../Application/Server/decoder.h"

extern void __attach(void);
extern void __attachInterfaces(void);
extern void __attachGenerics(void);
extern void __attachAssets(void);
extern void __attachQImage(void);
extern void __attachWavefront(void);

int main ( int argc, char** argv ) {
    /*
    __attach();
    __attachInterfaces();
    __attachGenerics();
    __attachAssets();*/
    __attachQImage();
    __attachWavefront();

    FileDescriptor file ( argv[1]);
    SharedResourceList ress = ResourceHolder::Load(file);
    std::cout << "** Resource loaded" << std::endl;
    SharedResourcePtr ptr = ress [0];
    ByteBuffer message = ResourceHolder::ToBuffer(ptr);
    std::cout << "** Resource converted" << std::endl;

    //unsigned char* test = "machaine";
    //ByteBuffer stringtest = new ByteBuffer(test, 8);
    SimpleTcpEndPoint::Options options;
    options.serverIP = "localhost";
    options.connectionPort = 3000;
    SimpleTcpEndPoint client ( options );

    StringMessage wopa;
    char back_wopa[10];
    strcpy(back_wopa, "aapowupowa");
    wopa.setLen(10);
    wopa.setstr(back_wopa);

    if ( client.open() == false ) exit ( -1 );
    client.send(*(wopa.toByteBuffer())); std::cout << "Sent : " << message.getLength() << " bytes" << std::endl;
    ByteBuffer msg;

    ReceiveMessage rec_msg;
    StringMessage str_msg;

    client.receive(msg); std::cout << "Recv : " << msg.getLength() << " bytes" << std::endl;
    decode<ReceiveMessage>(msg, rec_msg);
    decode<StringMessage>(*(rec_msg.toByteBuffer()), str_msg);
    char * str = str_msg.getStr();

    std::cout<< "recu : ";
    for(int i = 0; i < str_msg.getLen(); i++) {
        std::cout<< str[i];
    }
    std::cout << " \n ";
    client.close ();
    return 0;
}
