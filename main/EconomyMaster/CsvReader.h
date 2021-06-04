#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
#pragma once

class CsvReader
	/*****
	CSV文件读取器，会读取CSV逗号分隔表文件。
	先按行读取，将每行内容分配到一个新的动态数组中，优点是读取每行的内容有着较高的效率，按列有较高的插入效率。
	*****/
{
private:
	set<vector<string>> Reader;
public:
	set<vector<string>> getReader() { return this->Reader; }

	CsvReader(string path);
	~CsvReader();
};

