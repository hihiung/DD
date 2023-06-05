#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/FlashMemoryDevice.h"
#include "../Project1/DeviceDriver.cpp"
#include <stdexcept>

using namespace testing;

TEST(TestCaseName, TestName) {
	EXPECT_THAT(1, Eq(1));
}

class HwMock : public FlashMemoryDevice 
{
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
	
};


TEST(DeviceDriverTest, Read_0)
{
	HwMock flash_mock;
	EXPECT_CALL(flash_mock, read(_)).Times(5);

	DeviceDriver dd(&flash_mock);
	long temp = dd.read(0x00);
}

TEST(DeviceDriverTest, Read_FAIL)
{
	HwMock flash_mock;
	EXPECT_CALL(flash_mock, read(0x00))
		.WillOnce(Return(2))
		.WillRepeatedly(Return(3));

	DeviceDriver dd(&flash_mock);
	EXPECT_THROW(dd.read(0x00), std::exception);
}

TEST(DeviceDriverTest, Read_SUCCESS)
{
	HwMock flash_mock;
	EXPECT_CALL(flash_mock, read(0x00))
		.WillRepeatedly(Return(3));

	DeviceDriver dd(&flash_mock);
	EXPECT_THAT(dd.read(0x00), Eq(3));
}