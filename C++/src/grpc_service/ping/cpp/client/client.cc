// MIT License

// Copyright (c) 2020 Twinspica Authors

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "src/grpc_service/ping/cpp/client/client.hh"
#include <iostream>

namespace ping {

std::string ping_client::RuThere() {
    // request to be sent to the server
    Request request;

    // data structure to receive the response from the server
    Response reply;

    ClientContext context;
    Status status = stub_->RuThere(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
        return reply.message();
    }

    return "RPC failed: status code: " + std::to_string(status.error_code()) +
           ", msg: " + status.error_message();
}

} // namespace ping

int main(int argc, char **argv) {
    // (TODO) twinspica authors: need to use abesil flags for command line arguments to accept
    // address + port information
    std::string server_addr("localhost:5000");
    ping::ping_client client1(
        grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials()));

    std::string reply = client1.RuThere();
    std::cout << "Response received: " << reply << std::endl;
    return 0;
}
