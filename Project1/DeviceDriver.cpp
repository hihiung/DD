#include "DeviceDriver.h"
#include <stdexcept>
const int READ_REPETITION = 4;

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
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}