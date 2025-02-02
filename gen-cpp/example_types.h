/**
 * Autogenerated by Thrift Compiler (0.20.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef example_TYPES_H
#define example_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace example {

class MyStruct;

typedef struct _MyStruct__isset {
  _MyStruct__isset() : id(false), value(false), name(false) {}
  bool id :1;
  bool value :1;
  bool name :1;
} _MyStruct__isset;

class MyStruct : public virtual ::apache::thrift::TBase {
 public:

  MyStruct(const MyStruct&);
  MyStruct& operator=(const MyStruct&);
  MyStruct() noexcept
           : id(0),
             value(0),
             name() {
  }

  virtual ~MyStruct() noexcept;
  int32_t id;
  double value;
  std::string name;

  _MyStruct__isset __isset;

  void __set_id(const int32_t val);

  void __set_value(const double val);

  void __set_name(const std::string& val);

  bool operator == (const MyStruct & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(value == rhs.value))
      return false;
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const MyStruct &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyStruct & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(MyStruct &a, MyStruct &b);

std::ostream& operator<<(std::ostream& out, const MyStruct& obj);

} // namespace

#endif
