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

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "src/grpc_service/ping/proto/ping_service.pb.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
//using PingService::Request;
//using PingService::Response;
//using PingService::Ping;


namespace ping {
class ping_client {
// public:
//   GreeterClient(std::shared_ptr<Channel> channel)
//       : stub_(Greeter::NewStub(channel)) {}

//   // Assembles the client's payload, sends it and presents the response back
//   // from the server.
//   std::string SayHello(const std::string& user) {
//     // Data we are sending to the server.
//     HelloRequest request;
//     request.set_name(user);

//     // Container for the data we expect from the server.
//     HelloReply reply;

//     // Context for the client. It could be used to convey extra information to
//     // the server and/or tweak certain RPC behaviors.
//     ClientContext context;

//     // The actual RPC.
//     Status status = stub_->SayHello(&context, request, &reply);

//     // Act upon its status.
//     if (status.ok()) {
//       return reply.message();
//     } else {
//       std::cout << status.error_code() << ": " << status.error_message()
//                 << std::endl;
//       return "RPC failed";
//     }
//   }

//  private:
//   std::unique_ptr<Greeter::Stub> stub_;
};

}

int main(int argc, char** argv) {
//   // Instantiate the client. It requires a channel, out of which the actual RPCs
//   // are created. This channel models a connection to an endpoint specified by
//   // the argument "--target=" which is the only expected argument.
//   // We indicate that the channel isn't authenticated (use of
//   // InsecureChannelCredentials()).
//   std::string target_str;
//   std::string arg_str("--target");
//   if (argc > 1) {
//     std::string arg_val = argv[1];
//     size_t start_pos = arg_val.find(arg_str);
//     if (start_pos != std::string::npos) {
//       start_pos += arg_str.size();
//       if (arg_val[start_pos] == '=') {
//         target_str = arg_val.substr(start_pos + 1);
//       } else {
//         std::cout << "The only correct argument syntax is --target=" << std::endl;
//         return 0;
//       }
//     } else {
//       std::cout << "The only acceptable argument is --target=" << std::endl;
//       return 0;
//     }
//   } else {
//     target_str = "localhost:50051";
//   }
//   GreeterClient greeter(grpc::CreateChannel(
//       target_str, grpc::InsecureChannelCredentials()));
//   std::string user("world");
//   std::string reply = greeter.SayHello(user);
//   std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
