#pragma once

/**
 * @file ButtonModuleInterface.hpp
 * @brief Defines the ButtonModuleInterface class
 * @details Header file declaring the abstract interface for button modules
 * @author Ronny Antoon
 * @copyright MetaHouse LTD.
 */

/**
 * @typedef CallBackFunction
 * @brief Defines a type for callback functions used in the ButtonModuleInterface.
 * @param void* Pointer to any type of parameter passed to the callback function.
 */
using CallBackFunction = void (*)(void *);

/**
 * @typedef AnyType
 * @brief Defines a type for a generic pointer used in callback functions.
 */
using AnyType = void;

/**
 * @class ButtonModuleInterface
 * @brief Abstract interface for button modules.
 * @details This class provides a standard interface for handling button events like single press, double
 * press, and long press.
 */
class ButtonModuleInterface {
 public:
  /**
   * @brief Virtual destructor for the interface.
   */
  virtual ~ButtonModuleInterface() = default;

  /**
   * @brief Register a callback for single press events.
   * @param cb The callback function to be called on a single press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  virtual void onSinglePress(CallBackFunction cb, AnyType *cb_parameter = nullptr) = 0;

  /**
   * @brief Register a callback for double press events.
   * @param cb The callback function to be called on a double press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  virtual void onDoublePress(CallBackFunction cb, AnyType *cb_parameter = nullptr) = 0;

  /**
   * @brief Register a callback for long press events.
   * @param cb The callback function to be called on a long press.
   * @param cb_parameter A pointer to any type of parameter to be passed to the callback function (optional).
   */
  virtual void onLongPress(CallBackFunction cb, AnyType *cb_parameter = nullptr) = 0;
};
