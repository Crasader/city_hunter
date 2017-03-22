// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: space_cfg.proto

#ifndef PROTOBUF_space_5fcfg_2eproto__INCLUDED
#define PROTOBUF_space_5fcfg_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace cfg {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_space_5fcfg_2eproto();
void protobuf_AssignDesc_space_5fcfg_2eproto();
void protobuf_ShutdownFile_space_5fcfg_2eproto();

class Vec;
class SpaceCfg;

// ===================================================================

class Vec : public ::google::protobuf::Message {
 public:
  Vec();
  virtual ~Vec();

  Vec(const Vec& from);

  inline Vec& operator=(const Vec& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Vec& default_instance();

  void Swap(Vec* other);

  // implements Message ----------------------------------------------

  Vec* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vec& from);
  void MergeFrom(const Vec& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // optional float z = 3;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 3;
  inline float z() const;
  inline void set_z(float value);

  // @@protoc_insertion_point(class_scope:gamer.cfg.Vec)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  float x_;
  float y_;
  float z_;
  friend void  protobuf_AddDesc_space_5fcfg_2eproto();
  friend void protobuf_AssignDesc_space_5fcfg_2eproto();
  friend void protobuf_ShutdownFile_space_5fcfg_2eproto();

  void InitAsDefaultInstance();
  static Vec* default_instance_;
};
// -------------------------------------------------------------------

class SpaceCfg : public ::google::protobuf::Message {
 public:
  SpaceCfg();
  virtual ~SpaceCfg();

  SpaceCfg(const SpaceCfg& from);

  inline SpaceCfg& operator=(const SpaceCfg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpaceCfg& default_instance();

  void Swap(SpaceCfg* other);

  // implements Message ----------------------------------------------

  SpaceCfg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpaceCfg& from);
  void MergeFrom(const SpaceCfg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .gamer.cfg.Vec space_ori = 1;
  inline bool has_space_ori() const;
  inline void clear_space_ori();
  static const int kSpaceOriFieldNumber = 1;
  inline const ::gamer::cfg::Vec& space_ori() const;
  inline ::gamer::cfg::Vec* mutable_space_ori();
  inline ::gamer::cfg::Vec* release_space_ori();
  inline void set_allocated_space_ori(::gamer::cfg::Vec* space_ori);

  // required .gamer.cfg.Vec space_size = 2;
  inline bool has_space_size() const;
  inline void clear_space_size();
  static const int kSpaceSizeFieldNumber = 2;
  inline const ::gamer::cfg::Vec& space_size() const;
  inline ::gamer::cfg::Vec* mutable_space_size();
  inline ::gamer::cfg::Vec* release_space_size();
  inline void set_allocated_space_size(::gamer::cfg::Vec* space_size);

  // required .gamer.cfg.Vec space_box_num = 3;
  inline bool has_space_box_num() const;
  inline void clear_space_box_num();
  static const int kSpaceBoxNumFieldNumber = 3;
  inline const ::gamer::cfg::Vec& space_box_num() const;
  inline ::gamer::cfg::Vec* mutable_space_box_num();
  inline ::gamer::cfg::Vec* release_space_box_num();
  inline void set_allocated_space_box_num(::gamer::cfg::Vec* space_box_num);

  // required .gamer.cfg.Vec cell_size = 4;
  inline bool has_cell_size() const;
  inline void clear_cell_size();
  static const int kCellSizeFieldNumber = 4;
  inline const ::gamer::cfg::Vec& cell_size() const;
  inline ::gamer::cfg::Vec* mutable_cell_size();
  inline ::gamer::cfg::Vec* release_cell_size();
  inline void set_allocated_cell_size(::gamer::cfg::Vec* cell_size);

  // required .gamer.cfg.Vec cell_num = 5;
  inline bool has_cell_num() const;
  inline void clear_cell_num();
  static const int kCellNumFieldNumber = 5;
  inline const ::gamer::cfg::Vec& cell_num() const;
  inline ::gamer::cfg::Vec* mutable_cell_num();
  inline ::gamer::cfg::Vec* release_cell_num();
  inline void set_allocated_cell_num(::gamer::cfg::Vec* cell_num);

  // @@protoc_insertion_point(class_scope:gamer.cfg.SpaceCfg)
 private:
  inline void set_has_space_ori();
  inline void clear_has_space_ori();
  inline void set_has_space_size();
  inline void clear_has_space_size();
  inline void set_has_space_box_num();
  inline void clear_has_space_box_num();
  inline void set_has_cell_size();
  inline void clear_has_cell_size();
  inline void set_has_cell_num();
  inline void clear_has_cell_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::gamer::cfg::Vec* space_ori_;
  ::gamer::cfg::Vec* space_size_;
  ::gamer::cfg::Vec* space_box_num_;
  ::gamer::cfg::Vec* cell_size_;
  ::gamer::cfg::Vec* cell_num_;
  friend void  protobuf_AddDesc_space_5fcfg_2eproto();
  friend void protobuf_AssignDesc_space_5fcfg_2eproto();
  friend void protobuf_ShutdownFile_space_5fcfg_2eproto();

  void InitAsDefaultInstance();
  static SpaceCfg* default_instance_;
};
// ===================================================================


// ===================================================================

// Vec

// required float x = 1;
inline bool Vec::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vec::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vec::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vec::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vec::x() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.Vec.x)
  return x_;
}
inline void Vec::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:gamer.cfg.Vec.x)
}

// required float y = 2;
inline bool Vec::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vec::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vec::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vec::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vec::y() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.Vec.y)
  return y_;
}
inline void Vec::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:gamer.cfg.Vec.y)
}

// optional float z = 3;
inline bool Vec::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vec::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vec::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vec::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline float Vec::z() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.Vec.z)
  return z_;
}
inline void Vec::set_z(float value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:gamer.cfg.Vec.z)
}

// -------------------------------------------------------------------

// SpaceCfg

// required .gamer.cfg.Vec space_ori = 1;
inline bool SpaceCfg::has_space_ori() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SpaceCfg::set_has_space_ori() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SpaceCfg::clear_has_space_ori() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SpaceCfg::clear_space_ori() {
  if (space_ori_ != NULL) space_ori_->::gamer::cfg::Vec::Clear();
  clear_has_space_ori();
}
inline const ::gamer::cfg::Vec& SpaceCfg::space_ori() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.SpaceCfg.space_ori)
  return space_ori_ != NULL ? *space_ori_ : *default_instance_->space_ori_;
}
inline ::gamer::cfg::Vec* SpaceCfg::mutable_space_ori() {
  set_has_space_ori();
  if (space_ori_ == NULL) space_ori_ = new ::gamer::cfg::Vec;
  // @@protoc_insertion_point(field_mutable:gamer.cfg.SpaceCfg.space_ori)
  return space_ori_;
}
inline ::gamer::cfg::Vec* SpaceCfg::release_space_ori() {
  clear_has_space_ori();
  ::gamer::cfg::Vec* temp = space_ori_;
  space_ori_ = NULL;
  return temp;
}
inline void SpaceCfg::set_allocated_space_ori(::gamer::cfg::Vec* space_ori) {
  delete space_ori_;
  space_ori_ = space_ori;
  if (space_ori) {
    set_has_space_ori();
  } else {
    clear_has_space_ori();
  }
  // @@protoc_insertion_point(field_set_allocated:gamer.cfg.SpaceCfg.space_ori)
}

// required .gamer.cfg.Vec space_size = 2;
inline bool SpaceCfg::has_space_size() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SpaceCfg::set_has_space_size() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SpaceCfg::clear_has_space_size() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SpaceCfg::clear_space_size() {
  if (space_size_ != NULL) space_size_->::gamer::cfg::Vec::Clear();
  clear_has_space_size();
}
inline const ::gamer::cfg::Vec& SpaceCfg::space_size() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.SpaceCfg.space_size)
  return space_size_ != NULL ? *space_size_ : *default_instance_->space_size_;
}
inline ::gamer::cfg::Vec* SpaceCfg::mutable_space_size() {
  set_has_space_size();
  if (space_size_ == NULL) space_size_ = new ::gamer::cfg::Vec;
  // @@protoc_insertion_point(field_mutable:gamer.cfg.SpaceCfg.space_size)
  return space_size_;
}
inline ::gamer::cfg::Vec* SpaceCfg::release_space_size() {
  clear_has_space_size();
  ::gamer::cfg::Vec* temp = space_size_;
  space_size_ = NULL;
  return temp;
}
inline void SpaceCfg::set_allocated_space_size(::gamer::cfg::Vec* space_size) {
  delete space_size_;
  space_size_ = space_size;
  if (space_size) {
    set_has_space_size();
  } else {
    clear_has_space_size();
  }
  // @@protoc_insertion_point(field_set_allocated:gamer.cfg.SpaceCfg.space_size)
}

// required .gamer.cfg.Vec space_box_num = 3;
inline bool SpaceCfg::has_space_box_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SpaceCfg::set_has_space_box_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SpaceCfg::clear_has_space_box_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SpaceCfg::clear_space_box_num() {
  if (space_box_num_ != NULL) space_box_num_->::gamer::cfg::Vec::Clear();
  clear_has_space_box_num();
}
inline const ::gamer::cfg::Vec& SpaceCfg::space_box_num() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.SpaceCfg.space_box_num)
  return space_box_num_ != NULL ? *space_box_num_ : *default_instance_->space_box_num_;
}
inline ::gamer::cfg::Vec* SpaceCfg::mutable_space_box_num() {
  set_has_space_box_num();
  if (space_box_num_ == NULL) space_box_num_ = new ::gamer::cfg::Vec;
  // @@protoc_insertion_point(field_mutable:gamer.cfg.SpaceCfg.space_box_num)
  return space_box_num_;
}
inline ::gamer::cfg::Vec* SpaceCfg::release_space_box_num() {
  clear_has_space_box_num();
  ::gamer::cfg::Vec* temp = space_box_num_;
  space_box_num_ = NULL;
  return temp;
}
inline void SpaceCfg::set_allocated_space_box_num(::gamer::cfg::Vec* space_box_num) {
  delete space_box_num_;
  space_box_num_ = space_box_num;
  if (space_box_num) {
    set_has_space_box_num();
  } else {
    clear_has_space_box_num();
  }
  // @@protoc_insertion_point(field_set_allocated:gamer.cfg.SpaceCfg.space_box_num)
}

// required .gamer.cfg.Vec cell_size = 4;
inline bool SpaceCfg::has_cell_size() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SpaceCfg::set_has_cell_size() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SpaceCfg::clear_has_cell_size() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SpaceCfg::clear_cell_size() {
  if (cell_size_ != NULL) cell_size_->::gamer::cfg::Vec::Clear();
  clear_has_cell_size();
}
inline const ::gamer::cfg::Vec& SpaceCfg::cell_size() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.SpaceCfg.cell_size)
  return cell_size_ != NULL ? *cell_size_ : *default_instance_->cell_size_;
}
inline ::gamer::cfg::Vec* SpaceCfg::mutable_cell_size() {
  set_has_cell_size();
  if (cell_size_ == NULL) cell_size_ = new ::gamer::cfg::Vec;
  // @@protoc_insertion_point(field_mutable:gamer.cfg.SpaceCfg.cell_size)
  return cell_size_;
}
inline ::gamer::cfg::Vec* SpaceCfg::release_cell_size() {
  clear_has_cell_size();
  ::gamer::cfg::Vec* temp = cell_size_;
  cell_size_ = NULL;
  return temp;
}
inline void SpaceCfg::set_allocated_cell_size(::gamer::cfg::Vec* cell_size) {
  delete cell_size_;
  cell_size_ = cell_size;
  if (cell_size) {
    set_has_cell_size();
  } else {
    clear_has_cell_size();
  }
  // @@protoc_insertion_point(field_set_allocated:gamer.cfg.SpaceCfg.cell_size)
}

// required .gamer.cfg.Vec cell_num = 5;
inline bool SpaceCfg::has_cell_num() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SpaceCfg::set_has_cell_num() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SpaceCfg::clear_has_cell_num() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SpaceCfg::clear_cell_num() {
  if (cell_num_ != NULL) cell_num_->::gamer::cfg::Vec::Clear();
  clear_has_cell_num();
}
inline const ::gamer::cfg::Vec& SpaceCfg::cell_num() const {
  // @@protoc_insertion_point(field_get:gamer.cfg.SpaceCfg.cell_num)
  return cell_num_ != NULL ? *cell_num_ : *default_instance_->cell_num_;
}
inline ::gamer::cfg::Vec* SpaceCfg::mutable_cell_num() {
  set_has_cell_num();
  if (cell_num_ == NULL) cell_num_ = new ::gamer::cfg::Vec;
  // @@protoc_insertion_point(field_mutable:gamer.cfg.SpaceCfg.cell_num)
  return cell_num_;
}
inline ::gamer::cfg::Vec* SpaceCfg::release_cell_num() {
  clear_has_cell_num();
  ::gamer::cfg::Vec* temp = cell_num_;
  cell_num_ = NULL;
  return temp;
}
inline void SpaceCfg::set_allocated_cell_num(::gamer::cfg::Vec* cell_num) {
  delete cell_num_;
  cell_num_ = cell_num;
  if (cell_num) {
    set_has_cell_num();
  } else {
    clear_has_cell_num();
  }
  // @@protoc_insertion_point(field_set_allocated:gamer.cfg.SpaceCfg.cell_num)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace cfg
}  // namespace gamer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_space_5fcfg_2eproto__INCLUDED