/*
 C++ Big Integer Library
 (see ChangeLog for version)
 
 http://mattmccutchen.net/bigint/
 
 Written and maintained by Matt McCutchen <matt@mattmccutchen.net>
 
 Legal
 -----
 I, Matt McCutchen, the sole author of the original Big Integer Library, waive my
 copyright to it, placing it in the public domain.  The library comes with
 absolutely no warranty.
 
 */

#include "BigIntegerUtils.hh"
#include "BigUnsignedInABase.hh"

// ---------------------------------


std::string bigUnsignedToString(const BigUnsigned &x) {
	return std::string(BigUnsignedInABase(x, 10));
}

BigUnsigned stringToBigUnsigned(const std::string &s) {
	return BigUnsigned(BigUnsignedInABase(s, 10));
}

// ---------------------------------


std::string bigUnsignedToStringBase62(const BigUnsigned &x) {
	return std::string(BigUnsignedInABase(x, 62));
}

BigUnsigned stringToBigUnsignedBase62(const std::string &s) {
	return BigUnsigned(BigUnsignedInABase(s, 62));
}

// ---------------------------------


std::string bigUnsignedToStringBase16(const BigUnsigned &x) {
	return std::string(BigUnsignedInABase(x, 16));
}

BigUnsigned stringToBigUnsignedBase16(const std::string &s) {
	return BigUnsigned(BigUnsignedInABase(s, 16));
}


// ---------------------------------

std::string bigIntegerToString(const BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
	? (std::string("-") + bigUnsignedToString(x.getMagnitude()))
	: (bigUnsignedToString(x.getMagnitude()));
}

BigInteger stringToBigInteger(const std::string &s) {
	// Recognize a sign followed by a BigUnsigned.
	return (s[0] == '-') ? BigInteger(stringToBigUnsigned(s.substr(1, s.length() - 1)), BigInteger::negative)
	: (s[0] == '+') ? BigInteger(stringToBigUnsigned(s.substr(1, s.length() - 1)))
	: BigInteger(stringToBigUnsigned(s));
}


// ---------------------------------

std::string bigIntegerToStringBase62(const BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
	? (std::string("-") + bigUnsignedToStringBase62(x.getMagnitude()))
	: (bigUnsignedToStringBase62(x.getMagnitude()));
}

BigInteger stringToBigIntegerBase62(const std::string &s) {
	// Recognize a sign followed by a BigUnsigned.
	return (s[0] == '-') ? BigInteger(stringToBigUnsignedBase62(s.substr(1, s.length() - 1)), BigInteger::negative)
	: (s[0] == '+') ? BigInteger(stringToBigUnsignedBase62(s.substr(1, s.length() - 1)))
	: BigInteger(stringToBigUnsignedBase62(s));
}


// ---------------------------------

std::string bigIntegerToStringBase16(const BigInteger &x)  {
	return (x.getSign() == BigInteger::negative)
	? (std::string("-") + bigUnsignedToStringBase16(x.getMagnitude()))
	: (bigUnsignedToStringBase16(x.getMagnitude()));
}

BigInteger stringToBigIntegerBase16(const std::string &s) {
	// Recognize a sign followed by a BigUnsigned.
	return (s[0] == '-') ? BigInteger(stringToBigUnsignedBase16(s.substr(1, s.length() - 1)), BigInteger::negative)
	: (s[0] == '+') ? BigInteger(stringToBigUnsignedBase16(s.substr(1, s.length() - 1)))
	: BigInteger(stringToBigUnsignedBase16(s));
}


// ---------------------------------


std::ostream &operator <<(std::ostream &os, const BigUnsigned &x) {
	BigUnsignedInABase::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	} else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	} else
		throw "std::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
	std::string s = std::string(BigUnsignedInABase(x, base));
	os << s;
	return os;
}

std::ostream &operator <<(std::ostream &os, const BigInteger &x) {
	if (x.getSign() == BigInteger::negative)
		os << '-';
	os << x.getMagnitude();
	return os;
}
