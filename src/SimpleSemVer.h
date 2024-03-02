#pragma once

#include <Arduino.h>

class Version {
  public:
    Version();
    Version(uint8_t major, uint8_t minor, uint8_t patch, const char* extension = nullptr);
    Version(const char* other);
    ~Version();

    String toString() const;
    long   toInt() const;
    operator String() const;
    Version& operator=(const char* other);

    bool operator==(const Version& other) const;
    bool operator!=(const Version& other) const;
    bool operator<(const Version& other) const;
    bool operator>(const Version& other) const;
    bool operator<=(const Version& other) const;
    bool operator>=(const Version& other) const;

    void major(uint8_t major);
    void minor(uint8_t minor);
    void patch(uint8_t patch);
    void extension(const String& extension);

    uint8_t major() const;
    uint8_t minor() const;
    uint8_t patch() const;
    String  extension() const;

    static Version version();

  protected:
    void fromString(const char* other);
    void parseExtension(const char* extension);

  protected:
    uint8_t _major;
    uint8_t _minor;
    uint8_t _patch;
    String  _extension;
};