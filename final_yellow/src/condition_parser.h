/*
 * condition_parser.h
 *
 *  Created on: 6 ���. 2022 �.
 *      Author: SeltikeS
 */

#pragma once

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;


shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();



