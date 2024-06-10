#pragma once

/**
 * @file ButtonModule.hpp
 * @brief Defines the ButtonModule class
 * @details Header file declaring the ButtonModule class which implements the ButtonModuleInterface for
 * handling button events.
 */

#include <iot_button.h>

#include "ButtonModuleInterface.hpp"

/**
 * @class ButtonModule
 * @brief Implements the ButtonModuleInterface for handling button events.
 * @details This class provides concrete implementations for handling single press, double press, and long
 * press events using callback functions.
 */
class ButtonModule : public ButtonModuleInterface {
 public:
  ButtonModule(int8_t button_pin = -1, uint8_t active_level = 1, uint16_t long_press_time_ms = 2000,
               uint16_t short_press_time_ms = 100);

  /**
   * @brief Destructor for the ButtonModule class.
   */
  virtual ~ButtonModule();

  /**
   * @brief Register a callback for single press events.
   * @param cb The callback function to be called on a single press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  void onSinglePress(CallBackFunction cb, AnyType *cb_parameter = nullptr) override;

  /**
   * @brief Register a callback for double press events.
   * @param cb The callback function to be called on a double press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  void onDoublePress(CallBackFunction cb, AnyType *cb_parameter = nullptr) override;

  /**
   * @brief Register a callback for long press events.
   * @param cb The callback function to be called on a long press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  void onLongPress(CallBackFunction cb, AnyType *cb_parameter = nullptr) override;

 private:
  CallBackFunction m_single_press_cb;   /**< Callback function for single press events */
  CallBackFunction m_double_press_cb;   /**< Callback function for double press events */
  CallBackFunction m_long_press_cb;     /**< Callback function for long press events */
  AnyType *m_single_press_cb_parameter; /**< Parameter for single press callback function */
  AnyType *m_double_press_cb_parameter; /**< Parameter for double press callback function */
  AnyType *m_long_press_cb_parameter;   /**< Parameter for long press callback function */
  button_handle_t m_button_handle;      /**< Handle for the button */
};
