#include "SimpleSemVer.h"

Version::Version()
    : _major(0)
    , _minor(0)
    , _patch(0)
    , _extension("") {
}

Version::Version(uint8_t major, uint8_t minor, uint8_t patch, const char* extension)
    : _major(major)
    , _minor(minor)
    , _patch(patch)
    , _extension(_extension) {
}

Version::Version(const char* other) {
    fromString(other);
}

Version::~Version(){};

String Version::toString() const {
    char version[33]{0};
    snprintf(version, sizeof(version), "%d.%d.%d", _major, _minor, _patch);

    String result(version);

    bool hasExtension = _extension.length() > 0;

    if (hasExtension) result += _extension;

    return result;
}

uint8_t Version::major() const {
    return _major;
}

uint8_t Version::minor() const {
    return _minor;
}

uint8_t Version::patch() const {
    return _patch;
}

void Version::major(uint8_t major) {
    _major = major;
}

void Version::minor(uint8_t minor) {
    _minor = minor;
}

void Version::patch(uint8_t patch) {
    _patch = patch;
}

void Version::extension(const String& extension) {
    _extension = extension;
}

String Version::extension() const {
    return _extension;
}

Version::operator String() const {
    return toString();
}

Version& Version::operator=(const char* other) {
    fromString(other);
    return *this;
}

bool Version::operator==(const Version& other) const {
    if (toInt() != other.toInt()) return false;
    if (_extension.compareTo(other._extension) != 0) return false;
    return true;
};

bool Version::operator!=(const Version& other) const {
    return !(operator==(other));
};

bool Version::operator<(const Version& other) const {
    if (toInt() < other.toInt()) return true;
    if (toInt() > other.toInt()) return false;
    return _extension.compareTo(other._extension) < 0;
};

bool Version::operator>(const Version& other) const {
    return other.operator<(*this);
};

bool Version::operator<=(const Version& other) const {
    return !(other.operator<(*this));
};

bool Version::operator>=(const Version& other) const {
    return !(operator<(other));
};

void Version::fromString(const char* other) {
    char extension[256];
    int  count = sscanf(other, "%d.%d.%d%s", &_major, &_minor, &_patch, &extension);

    bool hasExtension = count == 4;
    if (hasExtension) _extension = String(extension);
}

long Version::toInt() const {
    return (_major * 1000000) + (_minor * 1000) + _patch;
}

Version Version::version() { return Version("0.0.1-rc1"); }
