/*
 * MockStartPosition.h
 *
 *  Created on: 3 Oct 2014
 *      Author: marius.crisan
 */

#ifndef MOCKSTARTPOSITION_H_
#define MOCKSTARTPOSITION_H_

#include "StartPosition.h"
#include "gmock/gmock.h"

using ::testing::Return;

class MockStartPosition : public reversi::StartPosition
{
public:
	MOCK_METHOD1(Run, void(reversi::Board& b));
	MOCK_METHOD0(Foo, bool());

	void SetUp()
	{
		ON_CALL(*this, Foo()).WillByDefault(Return(true));
	}
};

#endif /* MOCKSTARTPOSITION_H_ */
