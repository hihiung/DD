#include "DeviceDriver.h"
#include <stdexcept>
const int READ_REPETITION = 4;
const int VALUE_EMPTY_SPACE = 0xFF;

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int value_init = (int) m_hardware->read(address);
    for (int i = 0; i < READ_REPETITION; i++) {
        int value_fresh = (int) m_hardware->read(address);
        if (value_init != value_fresh)
            throw std::exception("값이 달라여");
    }

    return value_init;
}

void DeviceDriver::write(long address, int data)
{
    int curr_val = (int) m_hardware->read(address);

    if (curr_val != VALUE_EMPTY_SPACE)
        throw std::exception("값이 있어여");

    m_hardware->write(address, (unsigned char) data);
}