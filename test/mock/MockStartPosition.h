/*
 * MockStartPosition.h
 *
 *  Created on: Oct 2, 2014
 *      Author: Marius
 */

#ifndef MOCKSTARTPOSITION_H_
#define MOCKSTARTPOSITION_H_

#include "StartPosition.h"
#include "gmock/gmock.h"

class MockStartPosition : public reversi::StartPosition
{
public:
	MOCK_METHOD1(Run, void(reversi::Board& b));
};

#endif /* MOCKSTARTPOSITION_H_ */
