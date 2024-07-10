// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: testData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_testData_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_testData_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_testData_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_testData_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_testData_2eproto;
namespace tutorial {
class testData;
class testDataDefaultTypeInternal;
extern testDataDefaultTypeInternal _testData_default_instance_;
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template<> ::tutorial::testData* Arena::CreateMaybeMessage<::tutorial::testData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tutorial {

// ===================================================================

class testData PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.testData) */ {
 public:
  inline testData() : testData(nullptr) {};
  virtual ~testData();

  testData(const testData& from);
  testData(testData&& from) noexcept
    : testData() {
    *this = ::std::move(from);
  }

  inline testData& operator=(const testData& from) {
    CopyFrom(from);
    return *this;
  }
  inline testData& operator=(testData&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const testData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const testData* internal_default_instance() {
    return reinterpret_cast<const testData*>(
               &_testData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(testData& a, testData& b) {
    a.Swap(&b);
  }
  inline void Swap(testData* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(testData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline testData* New() const final {
    return CreateMaybeMessage<testData>(nullptr);
  }

  testData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<testData>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const testData& from);
  void MergeFrom(const testData& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(testData* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tutorial.testData";
  }
  protected:
  explicit testData(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_testData_2eproto);
    return ::descriptor_table_testData_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kKeysFieldNumber = 1,
  };
  // repeated string keys = 1;
  int keys_size() const;
  private:
  int _internal_keys_size() const;
  public:
  void clear_keys();
  const std::string& keys(int index) const;
  std::string* mutable_keys(int index);
  void set_keys(int index, const std::string& value);
  void set_keys(int index, std::string&& value);
  void set_keys(int index, const char* value);
  void set_keys(int index, const char* value, size_t size);
  std::string* add_keys();
  void add_keys(const std::string& value);
  void add_keys(std::string&& value);
  void add_keys(const char* value);
  void add_keys(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& keys() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_keys();
  private:
  const std::string& _internal_keys(int index) const;
  std::string* _internal_add_keys();
  public:

  // @@protoc_insertion_point(class_scope:tutorial.testData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> keys_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_testData_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// testData

// repeated string keys = 1;
inline int testData::_internal_keys_size() const {
  return keys_.size();
}
inline int testData::keys_size() const {
  return _internal_keys_size();
}
inline void testData::clear_keys() {
  keys_.Clear();
}
inline std::string* testData::add_keys() {
  // @@protoc_insertion_point(field_add_mutable:tutorial.testData.keys)
  return _internal_add_keys();
}
inline const std::string& testData::_internal_keys(int index) const {
  return keys_.Get(index);
}
inline const std::string& testData::keys(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.testData.keys)
  return _internal_keys(index);
}
inline std::string* testData::mutable_keys(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.testData.keys)
  return keys_.Mutable(index);
}
inline void testData::set_keys(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:tutorial.testData.keys)
  keys_.Mutable(index)->assign(value);
}
inline void testData::set_keys(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:tutorial.testData.keys)
  keys_.Mutable(index)->assign(std::move(value));
}
inline void testData::set_keys(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  keys_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:tutorial.testData.keys)
}
inline void testData::set_keys(int index, const char* value, size_t size) {
  keys_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:tutorial.testData.keys)
}
inline std::string* testData::_internal_add_keys() {
  return keys_.Add();
}
inline void testData::add_keys(const std::string& value) {
  keys_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:tutorial.testData.keys)
}
inline void testData::add_keys(std::string&& value) {
  keys_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:tutorial.testData.keys)
}
inline void testData::add_keys(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  keys_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:tutorial.testData.keys)
}
inline void testData::add_keys(const char* value, size_t size) {
  keys_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:tutorial.testData.keys)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
testData::keys() const {
  // @@protoc_insertion_point(field_list:tutorial.testData.keys)
  return keys_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
testData::mutable_keys() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.testData.keys)
  return &keys_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace tutorial

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_testData_2eproto
