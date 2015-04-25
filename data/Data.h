#pragma once
#ifndef MESSMER_CPPUTILS_DATA_DATA_H_
#define MESSMER_CPPUTILS_DATA_DATA_H_

#include <cstdlib>
#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>
#include "../macros.h"
#include <memory>

namespace cpputils {

class Data {
public:
  explicit Data(size_t size);
  virtual ~Data();

  Data(Data &&rhs); // move constructor
  //TODO Test move assignment (and if not tested yet, also move constructor)
  Data &operator=(Data &&rhs); // move assignment

  Data copy() const;

  void *data();
  const void *data() const;

  size_t size() const;

  Data &FillWithZeroes();

  void StoreToFile(const boost::filesystem::path &filepath) const;
  static boost::optional<Data> LoadFromFile(const boost::filesystem::path &filepath);

private:
  size_t _size;
  void *_data;

  static size_t _getStreamSize(std::istream &stream);
  void _readFromStream(std::istream &stream);

  DISALLOW_COPY_AND_ASSIGN(Data);
};

//TODO Test operator== and operator!=
bool operator==(const Data &lhs, const Data &rhs);
bool operator!=(const Data &lhs, const Data &rhs);

}

#endif
