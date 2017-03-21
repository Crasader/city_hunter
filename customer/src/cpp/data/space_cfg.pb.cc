// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: space_cfg.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "space_cfg.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace cfg {

namespace {

const ::google::protobuf::Descriptor* Vec_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Vec_reflection_ = NULL;
const ::google::protobuf::Descriptor* SpaceCfg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SpaceCfg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_space_5fcfg_2eproto() {
  protobuf_AddDesc_space_5fcfg_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "space_cfg.proto");
  GOOGLE_CHECK(file != NULL);
  Vec_descriptor_ = file->message_type(0);
  static const int Vec_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vec, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vec, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vec, z_),
  };
  Vec_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Vec_descriptor_,
      Vec::default_instance_,
      Vec_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vec, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Vec, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Vec));
  SpaceCfg_descriptor_ = file->message_type(1);
  static const int SpaceCfg_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, space_ori_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, space_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, space_box_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, cell_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, cell_num_),
  };
  SpaceCfg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SpaceCfg_descriptor_,
      SpaceCfg::default_instance_,
      SpaceCfg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SpaceCfg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SpaceCfg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_space_5fcfg_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Vec_descriptor_, &Vec::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SpaceCfg_descriptor_, &SpaceCfg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_space_5fcfg_2eproto() {
  delete Vec::default_instance_;
  delete Vec_reflection_;
  delete SpaceCfg::default_instance_;
  delete SpaceCfg_reflection_;
}

void protobuf_AddDesc_space_5fcfg_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017space_cfg.proto\022\tgamer.cfg\"&\n\003Vec\022\t\n\001x"
    "\030\001 \002(\002\022\t\n\001y\030\002 \002(\002\022\t\n\001z\030\003 \001(\002\"\275\001\n\010SpaceCf"
    "g\022!\n\tspace_ori\030\001 \002(\0132\016.gamer.cfg.Vec\022\"\n\n"
    "space_size\030\002 \002(\0132\016.gamer.cfg.Vec\022%\n\rspac"
    "e_box_num\030\003 \002(\0132\016.gamer.cfg.Vec\022!\n\tcell_"
    "size\030\004 \002(\0132\016.gamer.cfg.Vec\022 \n\010cell_num\030\005"
    " \002(\0132\016.gamer.cfg.Vec", 260);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "space_cfg.proto", &protobuf_RegisterTypes);
  Vec::default_instance_ = new Vec();
  SpaceCfg::default_instance_ = new SpaceCfg();
  Vec::default_instance_->InitAsDefaultInstance();
  SpaceCfg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_space_5fcfg_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_space_5fcfg_2eproto {
  StaticDescriptorInitializer_space_5fcfg_2eproto() {
    protobuf_AddDesc_space_5fcfg_2eproto();
  }
} static_descriptor_initializer_space_5fcfg_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Vec::kXFieldNumber;
const int Vec::kYFieldNumber;
const int Vec::kZFieldNumber;
#endif  // !_MSC_VER

Vec::Vec()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.Vec)
}

void Vec::InitAsDefaultInstance() {
}

Vec::Vec(const Vec& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.Vec)
}

void Vec::SharedCtor() {
  _cached_size_ = 0;
  x_ = 0;
  y_ = 0;
  z_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Vec::~Vec() {
  // @@protoc_insertion_point(destructor:gamer.cfg.Vec)
  SharedDtor();
}

void Vec::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Vec::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Vec::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Vec_descriptor_;
}

const Vec& Vec::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_space_5fcfg_2eproto();
  return *default_instance_;
}

Vec* Vec::default_instance_ = NULL;

Vec* Vec::New() const {
  return new Vec;
}

void Vec::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Vec*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(x_, z_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Vec::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.Vec)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required float x = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_y;
        break;
      }

      // required float y = 2;
      case 2: {
        if (tag == 21) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_z;
        break;
      }

      // optional float z = 3;
      case 3: {
        if (tag == 29) {
         parse_z:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &z_)));
          set_has_z();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.cfg.Vec)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.Vec)
  return false;
#undef DO_
}

void Vec::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.Vec)
  // required float x = 1;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->x(), output);
  }

  // required float y = 2;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->y(), output);
  }

  // optional float z = 3;
  if (has_z()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->z(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.Vec)
}

::google::protobuf::uint8* Vec::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.Vec)
  // required float x = 1;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->x(), target);
  }

  // required float y = 2;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->y(), target);
  }

  // optional float z = 3;
  if (has_z()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->z(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.Vec)
  return target;
}

int Vec::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required float x = 1;
    if (has_x()) {
      total_size += 1 + 4;
    }

    // required float y = 2;
    if (has_y()) {
      total_size += 1 + 4;
    }

    // optional float z = 3;
    if (has_z()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Vec::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Vec* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Vec*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Vec::MergeFrom(const Vec& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_z()) {
      set_z(from.z());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Vec::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Vec::CopyFrom(const Vec& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Vec::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Vec::Swap(Vec* other) {
  if (other != this) {
    std::swap(x_, other->x_);
    std::swap(y_, other->y_);
    std::swap(z_, other->z_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Vec::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Vec_descriptor_;
  metadata.reflection = Vec_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SpaceCfg::kSpaceOriFieldNumber;
const int SpaceCfg::kSpaceSizeFieldNumber;
const int SpaceCfg::kSpaceBoxNumFieldNumber;
const int SpaceCfg::kCellSizeFieldNumber;
const int SpaceCfg::kCellNumFieldNumber;
#endif  // !_MSC_VER

SpaceCfg::SpaceCfg()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.SpaceCfg)
}

void SpaceCfg::InitAsDefaultInstance() {
  space_ori_ = const_cast< ::gamer::cfg::Vec*>(&::gamer::cfg::Vec::default_instance());
  space_size_ = const_cast< ::gamer::cfg::Vec*>(&::gamer::cfg::Vec::default_instance());
  space_box_num_ = const_cast< ::gamer::cfg::Vec*>(&::gamer::cfg::Vec::default_instance());
  cell_size_ = const_cast< ::gamer::cfg::Vec*>(&::gamer::cfg::Vec::default_instance());
  cell_num_ = const_cast< ::gamer::cfg::Vec*>(&::gamer::cfg::Vec::default_instance());
}

SpaceCfg::SpaceCfg(const SpaceCfg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.SpaceCfg)
}

void SpaceCfg::SharedCtor() {
  _cached_size_ = 0;
  space_ori_ = NULL;
  space_size_ = NULL;
  space_box_num_ = NULL;
  cell_size_ = NULL;
  cell_num_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SpaceCfg::~SpaceCfg() {
  // @@protoc_insertion_point(destructor:gamer.cfg.SpaceCfg)
  SharedDtor();
}

void SpaceCfg::SharedDtor() {
  if (this != default_instance_) {
    delete space_ori_;
    delete space_size_;
    delete space_box_num_;
    delete cell_size_;
    delete cell_num_;
  }
}

void SpaceCfg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SpaceCfg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SpaceCfg_descriptor_;
}

const SpaceCfg& SpaceCfg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_space_5fcfg_2eproto();
  return *default_instance_;
}

SpaceCfg* SpaceCfg::default_instance_ = NULL;

SpaceCfg* SpaceCfg::New() const {
  return new SpaceCfg;
}

void SpaceCfg::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    if (has_space_ori()) {
      if (space_ori_ != NULL) space_ori_->::gamer::cfg::Vec::Clear();
    }
    if (has_space_size()) {
      if (space_size_ != NULL) space_size_->::gamer::cfg::Vec::Clear();
    }
    if (has_space_box_num()) {
      if (space_box_num_ != NULL) space_box_num_->::gamer::cfg::Vec::Clear();
    }
    if (has_cell_size()) {
      if (cell_size_ != NULL) cell_size_->::gamer::cfg::Vec::Clear();
    }
    if (has_cell_num()) {
      if (cell_num_ != NULL) cell_num_->::gamer::cfg::Vec::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SpaceCfg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.SpaceCfg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .gamer.cfg.Vec space_ori = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_space_ori()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_space_size;
        break;
      }

      // required .gamer.cfg.Vec space_size = 2;
      case 2: {
        if (tag == 18) {
         parse_space_size:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_space_size()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_space_box_num;
        break;
      }

      // required .gamer.cfg.Vec space_box_num = 3;
      case 3: {
        if (tag == 26) {
         parse_space_box_num:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_space_box_num()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_cell_size;
        break;
      }

      // required .gamer.cfg.Vec cell_size = 4;
      case 4: {
        if (tag == 34) {
         parse_cell_size:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_cell_size()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_cell_num;
        break;
      }

      // required .gamer.cfg.Vec cell_num = 5;
      case 5: {
        if (tag == 42) {
         parse_cell_num:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_cell_num()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.cfg.SpaceCfg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.SpaceCfg)
  return false;
#undef DO_
}

void SpaceCfg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.SpaceCfg)
  // required .gamer.cfg.Vec space_ori = 1;
  if (has_space_ori()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->space_ori(), output);
  }

  // required .gamer.cfg.Vec space_size = 2;
  if (has_space_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->space_size(), output);
  }

  // required .gamer.cfg.Vec space_box_num = 3;
  if (has_space_box_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->space_box_num(), output);
  }

  // required .gamer.cfg.Vec cell_size = 4;
  if (has_cell_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->cell_size(), output);
  }

  // required .gamer.cfg.Vec cell_num = 5;
  if (has_cell_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->cell_num(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.SpaceCfg)
}

::google::protobuf::uint8* SpaceCfg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.SpaceCfg)
  // required .gamer.cfg.Vec space_ori = 1;
  if (has_space_ori()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->space_ori(), target);
  }

  // required .gamer.cfg.Vec space_size = 2;
  if (has_space_size()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->space_size(), target);
  }

  // required .gamer.cfg.Vec space_box_num = 3;
  if (has_space_box_num()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->space_box_num(), target);
  }

  // required .gamer.cfg.Vec cell_size = 4;
  if (has_cell_size()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->cell_size(), target);
  }

  // required .gamer.cfg.Vec cell_num = 5;
  if (has_cell_num()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->cell_num(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.SpaceCfg)
  return target;
}

int SpaceCfg::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .gamer.cfg.Vec space_ori = 1;
    if (has_space_ori()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->space_ori());
    }

    // required .gamer.cfg.Vec space_size = 2;
    if (has_space_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->space_size());
    }

    // required .gamer.cfg.Vec space_box_num = 3;
    if (has_space_box_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->space_box_num());
    }

    // required .gamer.cfg.Vec cell_size = 4;
    if (has_cell_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->cell_size());
    }

    // required .gamer.cfg.Vec cell_num = 5;
    if (has_cell_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->cell_num());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SpaceCfg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SpaceCfg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SpaceCfg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SpaceCfg::MergeFrom(const SpaceCfg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_space_ori()) {
      mutable_space_ori()->::gamer::cfg::Vec::MergeFrom(from.space_ori());
    }
    if (from.has_space_size()) {
      mutable_space_size()->::gamer::cfg::Vec::MergeFrom(from.space_size());
    }
    if (from.has_space_box_num()) {
      mutable_space_box_num()->::gamer::cfg::Vec::MergeFrom(from.space_box_num());
    }
    if (from.has_cell_size()) {
      mutable_cell_size()->::gamer::cfg::Vec::MergeFrom(from.cell_size());
    }
    if (from.has_cell_num()) {
      mutable_cell_num()->::gamer::cfg::Vec::MergeFrom(from.cell_num());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SpaceCfg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SpaceCfg::CopyFrom(const SpaceCfg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SpaceCfg::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  if (has_space_ori()) {
    if (!this->space_ori().IsInitialized()) return false;
  }
  if (has_space_size()) {
    if (!this->space_size().IsInitialized()) return false;
  }
  if (has_space_box_num()) {
    if (!this->space_box_num().IsInitialized()) return false;
  }
  if (has_cell_size()) {
    if (!this->cell_size().IsInitialized()) return false;
  }
  if (has_cell_num()) {
    if (!this->cell_num().IsInitialized()) return false;
  }
  return true;
}

void SpaceCfg::Swap(SpaceCfg* other) {
  if (other != this) {
    std::swap(space_ori_, other->space_ori_);
    std::swap(space_size_, other->space_size_);
    std::swap(space_box_num_, other->space_box_num_);
    std::swap(cell_size_, other->cell_size_);
    std::swap(cell_num_, other->cell_num_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SpaceCfg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SpaceCfg_descriptor_;
  metadata.reflection = SpaceCfg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace cfg
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
