#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>

using namespace std;

#define  IS_OK 1
#define  IS_ERROR 0

class Properties {
private:
    string path;
protected:
public:
    Properties();
    Properties(const char* path);
    virtual ~Properties();
    //���ļ�
    bool open(const char* path);
    //ʵ���ļ����ص�map��
    bool load();
    void print();
    void close();
    vector<string> read(const char* k);
    bool write(const char* k, const char* v);
    void trim_first(string& s);
    void trim_end(string& s);
    void trim(string& s);
};