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

#include "src/grpc_service/ping/cpp/server/server.hh"

#include <chrono>
#include <cstdio>
#include <iostream>
#include <signal.h>
#include <thread>

namespace ping {
// Logic and data behind the server's behavior.
class ping_service_impl final : public Ping::Service {
    Status RuThere(ServerContext *context, const Request *request,
                   Response *reply) override {
        if (context != nullptr) {
            std::cout << "received request from: " << context->peer()
                      << std::endl;
        }

        reply->set_message("Yes...Ping Server is listening!");
        return Status::OK;
    }
};

} // namespace ping

volatile sig_atomic_t terminate = false;
void handle_interrupt(int a) {
    if (a == SIGINT) {
        terminate = true;
    }
}

int main(int argc, char **argv) {
    std::string server_address("localhost:5000");
    ping::ping_service_impl service;

    grpc::EnableDefaultHealthCheckService(true);

    grpc::ServerBuilder builder;

    // listen on the given address with no SSL
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    // register "service" as the instance through which we'll communicate with
    // clients. in this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);

    // finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Ping Server listening on " << server_address << "\n"
              << std::endl;

    // server the application
    server->Wait();

    return 0;
}