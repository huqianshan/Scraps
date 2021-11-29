#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool file_exists(const string &filename)
{
    std::ifstream f(filename.c_str());
    return f.good();
}

long long get_file_size(const string &filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

int main(int argc, char *argv[])
{
}