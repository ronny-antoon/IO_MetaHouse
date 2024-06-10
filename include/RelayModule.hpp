#pragma once

/**
 * @file RelayModule.hpp
 * @brief Defines the RelayModule class
 * @details Header file declaring the RelayModule class which implements the RelayModuleInterface for
 * controlling relay power states.
 */

#include <driver/gpio.h>

#include "RelayModuleInterface.hpp"

/**
 * @class RelayModule
 * @brief Implements the RelayModuleInterface for controlling relay power states.
 * @details This class provides concrete implementations for setting the power state of the relay and
 * checking if the relay is currently on.
 */
class RelayModule : public RelayModuleInterface {
 public:
  /**
   * @brief Constructs a new RelayModule object.
   * @param relay_pin The GPIO pin number connected to the relay.
   * @param active_level The active level for the relay (1 for active high, 0 for active low).
   * @param initial_state The initial state of the relay (1 for on, 0 for off).
   */
  RelayModule(int8_t relay_pin = -1, int8_t active_level = 1, int8_t initial_state = -1);

  /**
   * @brief Destructor for the RelayModule class.
   */
  virtual ~RelayModule() = default;

  /**
   * @brief Set the power state of the relay.
   * @param state Boolean value indicating the desired power state (true for on, false for off).
   */
  void setPower(bool state) override;

  /**
   * @brief Check if the relay is currently on.
   * @return true if the relay is on, false otherwise.
   */
  bool isOn() override;

 private:
  gpio_num_t m_relay_pin; /**< GPIO pin number for the relay */
  int8_t m_active_level;  /**< Active level for the relay */
};
