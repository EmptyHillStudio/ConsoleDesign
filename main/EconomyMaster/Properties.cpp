#pragma once
#include "Properties.h"

static vector<string> vLine;
static multimap<string, string> msKV;
static bool mulremark = false;//多行注释开关

Properties::Properties() {};
Properties::Properties(const char* path) {
    this->open(path);
}
Properties::~Properties() {};

bool Properties::open(const char* path) {
    if (nullptr == path)
    {
        return IS_ERROR;
    }
    this->path = path;
    ifstream ifs;
    ifs.open(path, ios::in);
    if (!ifs)
    {
        return IS_ERROR;//打开文件失败
    }
    string sLine;
    while (!ifs.eof()) {
        sLine = "";
        getline(ifs, sLine);
        if (mulremark)//已打开多行注释开关 需判断该行有没有关闭开关
        {
            if (sLine.find("*/") != string::npos) {
                mulremark = false;
            }
            continue;//无论开关是否关闭 继续读下一行数据
        }
        else
        {
            string::size_type pos = sLine.find("/*");string sSubLine;
            if (pos != string::npos)//改行有多行注释开关  需打开
            {
                string::size_type epos = sLine.rfind("*/");
                mulremark = epos == string::npos || epos < pos ? true : false;
                sSubLine = sLine.substr(0, pos);
            }
            else {
                sSubLine = sLine;
            }
            trim(sSubLine);
            if (sSubLine.length() <= 0) continue;
            if (sSubLine[0] == '#')continue;
            if (sSubLine[0] == '[')continue;
            if (sSubLine.length() > 2 && sSubLine[0] == '/' && sSubLine[1] == '/')continue;
            if (sSubLine.length() > 4 && sSubLine[0] == '<' && sSubLine[1] == '!')continue;
            vLine.push_back(sSubLine);
        }
    }
    if (ifs.is_open())
    {
        ifs.close();
    }
    return IS_OK;
}
//实现文件加载到map中
bool Properties::load() {
    string key, value;string sSubStr;
    for (int i = 0;i < vLine.size();i++)
    {
        string::size_type pos = vLine.at(i).find_first_of("=");
        if (pos == string::npos)
        {
            continue;
        }
        key = vLine.at(i).substr(0, pos);
        value = vLine.at(i).substr(pos + 1, vLine.at(i).size() - pos);
        msKV.insert(make_pair(key, value));
    }
    return IS_OK;
}

void Properties::print() {
    multimap<string, string>::iterator  itr = msKV.begin();
    cout << "################################################################################" << endl;
    for (;itr != msKV.end();itr++)
    {
        cout << "key:" << itr->first.c_str() << ";value:" << itr->second.c_str() << endl;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

vector<string> Properties::read(const char* k) {
    vector<string> vVauleCol;
    if (msKV.size() > 0)
    {
        multimap<string, string>::size_type  cnt = msKV.count(k);
        multimap<string, string>::iterator  iter = msKV.find(k);
        for (;cnt > 0; cnt--, iter++)
        {
            vVauleCol.push_back(iter->second);
        }
    }
    return vVauleCol;
}

/*
*aim:将key=value追加到文本末尾，更新multimap映射插入
*/
bool Properties::write(const char* k, const char* v) {
    if (nullptr == k || nullptr == v)
    {
        return IS_ERROR; //校验入参
    }
    ofstream ofs;
    ofs.open(this->path.c_str(), ios::app);
    if (!ofs)
    {
        return IS_ERROR;//打开文件失败
    }
    char sStr[1024] = {};
    sprintf_s(sStr, "%s=%s", k, v);
    ofs << endl << sStr;
    msKV.insert(make_pair(k, v));
    if (ofs.is_open())
    {
        ofs.close();
    }
    return IS_OK;
}

/*
*aim:防止多次造作脏数据干扰
*/
void Properties::close() {
    vLine.erase(vLine.begin(), vLine.end());
    msKV.erase(msKV.begin(), msKV.end());
}

void Properties::trim_first(string& s) {
    if (!s.empty())
        s.erase(0, s.find_first_not_of(" "));
}
void Properties::trim_end(string& s) {
    if (!s.empty())
        s.erase(s.find_last_not_of(" ") + 1);
}
void Properties::trim(string& s)
{
    int index = 0;
    if (!s.empty())
    {
        while ((index = s.find(' ', index)) != string::npos)
        {
            s.erase(index, 1);
        }
    }
}