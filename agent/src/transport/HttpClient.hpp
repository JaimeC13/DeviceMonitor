#ifndef HTTP_CLIENT_HPP
#define HTTP_CLIENT_HPP

#include <string>


class HttpClient {

    public:
    bool post(const std::string& url, const std::string& data);
};

#endif 