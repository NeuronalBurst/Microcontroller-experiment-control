#include "mbed.h"
#include "mbed_rpc.h"

/**
 *  This example program has been updated to use the RPC implementation in the new mbed libraries.
 *  This example demonstrates using RPC over serial
 */

//Use the RPC enabled wrapped class  - see RpcClasses.h for more info
RpcDigitalOut myled(LED4,"myled");

Serial pc(USBTX, USBRX);
int main() {
    //The mbed RPC classes are now wrapped to create an RPC enabled version - see RpcClasses.h so don't add to base class
    
    // receive commands, and send back the responses
    char buf[256], outbuf[256];
    while(1) {
        pc.gets(buf, 256);
        //Call the static call method on the RPC class
        RPC::call(buf, outbuf); 
        pc.printf("%s\n", outbuf);
    }
}
