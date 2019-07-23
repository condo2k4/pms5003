#pragma once

#include <Arduino.h>
#include <pmsSerial.h>

class PmsHardwareSerial : public IPmsSerial {
private:
  HardwareSerial* serial_;
public:

  PmsHardwareSerial(HardwareSerial* serial): serial_(serial) {
  }

  void setTimeout(const unsigned long int timeout) override {
    serial_->setTimeout(timeout);
  }

  size_t available() override {
    return serial_->available();
  }

  bool begin(const uint32_t baudRate) override {
    serial_->begin(baudRate);
    return true;
  }

  void end() override {
    serial_->end();
  }

  void flushInput() override {
    //do nothing
  }

  uint8_t peek() override {
    return serial_->peek();
  }

  uint8_t read() override {
    return serial_->read();
  }

  size_t read(uint8_t *buffer, const size_t length) override {
    return serial_->readBytes(buffer, length);
  }

  size_t write(const uint8_t *buffer, const size_t size) override {
    return serial_->write(buffer, size);
  }
};
