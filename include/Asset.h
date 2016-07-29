#ifndef ASSET_H
#define ASSET_H

#include <string>

class Asset {

private:

public:

	Asset() {};
	virtual ~Asset() {};

	virtual std::string getFilepath() const = 0;

};

#endif

