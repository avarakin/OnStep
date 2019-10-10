// MaxESP v1 specific pins validation

// SERIAL PORTS ------------------------------------------------------------------------------------------------------------
#if SERIAL_B_ESP_FLASHING == ON
  #error "Configuration (Config.h): SERIAL_B_ESP_FLASHING not supported on this PINMAP"
#endif

// USER FEEDBACK ----------------------------
#if LED_STATUS == ON
  #if Aux0 < 0
    #error "Configuration (Config.h): LED_STATUS enabled but Aux0 is already in use, choose one feature on Aux0"
  #else
    #undef Aux0
    #define Aux0 -2
  #endif
#endif

#if LED_STATUS2 == ON
  #if Aux8 < 0
    #error "Configuration (Config.h): LED_STATUS2 enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef Aux8
    #define Aux8 -2
  #endif
#endif

#if LED_RETICLE == ON
  #if Aux8 < 0
    #error "Configuration (Config.h): LED_RETICLE enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef Aux8
    #define Aux8 -2
  #endif
#endif

#if BUZZER == ON
  // dedicated pin
#endif

// TIME -------------------------------------
#if RTC == DS3231
  #error "Configuration (Config.h): I2C interface is not supported on this device."
#endif

#if PPS_SENSE == ON
  #if Aux0 < 0
    #error "Configuration (Config.h): PPS_SENSE enabled but Aux0 is already in use, choose one feature on Aux0"
  #else
    #undef Aux0
    #define Aux0 -2
  #endif
#endif

// SENSORS ----------------------------------
#if WEATHER == BME280
  #error "Configuration (Config.h): I2C interface is not supported on this device."
#endif

#if TELESCOPE_TEMPERATURE == DS1820
  #if Aux8 < 0
    #error "Configuration (Config.h): RTC DS1820 OneWire interface enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef Aux8
    #define Aux8 -2
  #endif
#endif

#if PEC_SENSE == ON || PEC_SENSE == ON_PULLUP || PEC_SENSE == ON_PULLDOWN
  // has dedicated pin
#endif

#if LIMIT_SENSE != OFF
  // has dedicated pin
#endif

#if HOME_SENSE != OFF
  #if Aux3 < 0
    #error "Configuration (Config.h): HOME_SENSE enabled but Aux3 is already in use, choose one feature on Aux3"
  #else
    #undef Aux3
    #define Aux3 -2
  #endif
  #if Aux4 < 0
    #error "Configuration (Config.h): HOME_SENSE enabled but Aux4 is already in use, choose one feature on Aux4"
  #else
    #undef Aux4
    #define Aux4 -2
  #endif
#endif

// MOTION CONTROL AXIS1/2 -----------------
#if AXIS1_DRIVER_STATUS != OFF
  #if Aux1 < 0
    #error "Configuration (Config.h): AXIS1_DRIVER_STATUS enabled but Aux1 is already in use, choose one feature on Aux1"
  #else
    #undef Aux1
    #define Aux1 -2
  #endif
#endif

#if AXIS2_DRIVER_STATUS != OFF
  // has dedicated pin, shared with AXIS1
#endif

// MOTION CONTROL FOCUSERS/ROTATOR --------
#if ROTATOR == ON && AXIS3_DRIVER_POWER_DOWN == ON
  // EN pin is dedicated
#endif

#if FOCUSER1 == ON && (AXIS4_DRIVER_POWER_DOWN == ON || AXIS4_DRIVER_DC_MODE != OFF)
  // EN pin is dedicated
#endif

#if FOCUSER2 == ON && AXIS5_DRIVER_POWER_DOWN == ON
  // there is no focuser2, this is trapped automatically later
#endif
