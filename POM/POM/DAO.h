#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class DAO {
protected:
	string delimeter = " ";

public:

	virtual void open() = 0;
	virtual void close() = 0;
};
