//============================================================================
// Name        : MassOfBlocks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

static uint64_t r = 0;

class Block {
public:
	Block(unsigned int w, unsigned int h, unsigned int d) {
		_w = w;
		_h = h;
		_d = d;

		_r = r;

		_m = _w * _h * _d * _r;
	}

	uint64_t GetM() {
		return _m;
	}

private:
	uint64_t _w, _h, _d;

	uint64_t _r;

	uint64_t _m;
};

int main() {

	unsigned int n;
	cin >> n >> r;

	uint64_t sum = 0;

	for(uint64_t i = 0; i < n; ++i) {
		uint64_t w, h, d;
		cin >> w >> h >> d;

		Block b(w, h, d);
		sum += b.GetM();
	}

	cout << sum << endl;

	return 0;
}
