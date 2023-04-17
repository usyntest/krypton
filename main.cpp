//
// Created by uday on 16/4/23.
//
#include <iostream>

using std::cout, std::string, std::endl;

struct URL {
    string url;
    string scheme;
    string domain;
    string path;
};

URL* create_url(string url) {
    URL* new_url = new URL();
    new_url->url = url;

    int found = url.find("http://");
    if (found != 0) {
        new_url->scheme = "invalid";
        // TODO
    }
    new_url->scheme = "http";
    new_url->domain = url.substr(7, url.length());
    int second_slash = new_url->domain.find('/');
    if (second_slash != -1) {
        new_url->path = new_url->domain.substr(second_slash, new_url->url.length());
        new_url->domain = new_url->domain.substr(0, second_slash);
    }

    return new_url;
}

int main() {
    URL* url1 = create_url("http://usyntest.co/home");
    cout << url1->url << endl;
    cout << url1->scheme << endl;
    cout << url1->domain << endl;
    cout << url1->path << endl;

    return 0;
}
