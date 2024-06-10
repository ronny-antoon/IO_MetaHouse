#pragma once

/**
 * @file RelayModuleInterface.hpp
 * @brief Defines the RelayModuleInterface class
 * @details Header file declaring the abstract interface for relay modules
 * @authoRonny Antoon
 * @copyright MetaHouse LTD.
 */

/**
 * @class RelayModuleInterface
 * @brief Abstract interface for relay modules.
 * @details This class provides a standard interface for controlling relay power states.
 */
class RelayModuleInterface {
 public:
  /**
   * @brief Virtual destructor for the interface.
   */
  virtual ~RelayModuleInterface() = default;

  /**
   * @brief Set the power state of the relay.
   * @param state Boolean value indicating the desired power state (true for on, false for off).
   */
  virtual void setPower(bool state) = 0;

  /**
   * @brief Check if the relay is currently on.
   * @return true if the relay is on, false otherwise.
   */
  virtual bool isOn() = 0;
};
