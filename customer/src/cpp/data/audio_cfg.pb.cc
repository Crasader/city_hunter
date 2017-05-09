// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: audio_cfg.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "audio_cfg.pb.h"

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

const ::google::protobuf::Descriptor* Audio_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Audio_reflection_ = NULL;
const ::google::protobuf::Descriptor* AudioCfg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AudioCfg_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* AudioIDs_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_audio_5fcfg_2eproto() {
  protobuf_AddDesc_audio_5fcfg_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "audio_cfg.proto");
  GOOGLE_CHECK(file != NULL);
  Audio_descriptor_ = file->message_type(0);
  static const int Audio_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Audio, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Audio, file_),
  };
  Audio_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Audio_descriptor_,
      Audio::default_instance_,
      Audio_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Audio, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Audio, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Audio));
  AudioCfg_descriptor_ = file->message_type(1);
  static const int AudioCfg_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AudioCfg, audio_),
  };
  AudioCfg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AudioCfg_descriptor_,
      AudioCfg::default_instance_,
      AudioCfg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AudioCfg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AudioCfg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AudioCfg));
  AudioIDs_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_audio_5fcfg_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Audio_descriptor_, &Audio::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AudioCfg_descriptor_, &AudioCfg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_audio_5fcfg_2eproto() {
  delete Audio::default_instance_;
  delete Audio_reflection_;
  delete AudioCfg::default_instance_;
  delete AudioCfg_reflection_;
}

void protobuf_AddDesc_audio_5fcfg_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017audio_cfg.proto\022\tgamer.cfg\"6\n\005Audio\022\037\n"
    "\002id\030\001 \002(\0162\023.gamer.cfg.AudioIDs\022\014\n\004file\030\002"
    " \002(\t\"+\n\010AudioCfg\022\037\n\005audio\030\001 \003(\0132\020.gamer."
    "cfg.Audio*\200\006\n\010AudioIDs\022!\n\035AUDIO_HERO_KNI"
    "GHT_NORMAL_ATK1\020\000\022!\n\035AUDIO_HERO_KNIGHT_N"
    "ORMAL_ATK2\020\001\022\"\n\036AUDIO_HERO_KNIGHT_SPECIA"
    "L_ATK1\020\002\022\"\n\036AUDIO_HERO_KNIGHT_SPECIAL_AT"
    "K2\020\003\022\033\n\027AUDIO_HERO_KNIGHT_HURT1\020\004\022\033\n\027AUD"
    "IO_HERO_KNIGHT_HURT2\020\005\022\034\n\030AUDIO_HERO_KNI"
    "GHT_DEFEND\020\006\022\032\n\026AUDIO_HERO_KNIGHT_DEAD\020\007"
    "\022!\n\035AUDIO_HERO_ARCHER_NORMAL_ATK1\020\010\022!\n\035A"
    "UDIO_HERO_ARCHER_NORMAL_ATK2\020\t\022\"\n\036AUDIO_"
    "HERO_ARCHER_SPECIAL_ATK1\020\n\022\"\n\036AUDIO_HERO"
    "_ARCHER_SPECIAL_ATK2\020\013\022\033\n\027AUDIO_HERO_ARC"
    "HER_HURT1\020\014\022\033\n\027AUDIO_HERO_ARCHER_HURT2\020\r"
    "\022\034\n\030AUDIO_HERO_ARCHER_DEFEND\020\016\022\032\n\026AUDIO_"
    "HERO_ARCHER_DEAD\020\017\022\037\n\033AUDIO_HERO_MAGE_NO"
    "RMAL_ATK1\020\020\022\037\n\033AUDIO_HERO_MAGE_NORMAL_AT"
    "K2\020\021\022 \n\034AUDIO_HERO_MAGE_SPECIAL_ATK1\020\022\022 "
    "\n\034AUDIO_HERO_MAGE_SPECIAL_ATK2\020\023\022\031\n\025AUDI"
    "O_HERO_MAGE_HURT1\020\024\022\031\n\025AUDIO_HERO_MAGE_H"
    "URT2\020\025\022\032\n\026AUDIO_HERO_MAGE_DEFEND\020\026\022\030\n\024AU"
    "DIO_HERO_MAGE_DEAD\020\027", 900);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "audio_cfg.proto", &protobuf_RegisterTypes);
  Audio::default_instance_ = new Audio();
  AudioCfg::default_instance_ = new AudioCfg();
  Audio::default_instance_->InitAsDefaultInstance();
  AudioCfg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_audio_5fcfg_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_audio_5fcfg_2eproto {
  StaticDescriptorInitializer_audio_5fcfg_2eproto() {
    protobuf_AddDesc_audio_5fcfg_2eproto();
  }
} static_descriptor_initializer_audio_5fcfg_2eproto_;
const ::google::protobuf::EnumDescriptor* AudioIDs_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AudioIDs_descriptor_;
}
bool AudioIDs_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int Audio::kIdFieldNumber;
const int Audio::kFileFieldNumber;
#endif  // !_MSC_VER

Audio::Audio()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.Audio)
}

void Audio::InitAsDefaultInstance() {
}

Audio::Audio(const Audio& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.Audio)
}

void Audio::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  file_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Audio::~Audio() {
  // @@protoc_insertion_point(destructor:gamer.cfg.Audio)
  SharedDtor();
}

void Audio::SharedDtor() {
  if (file_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete file_;
  }
  if (this != default_instance_) {
  }
}

void Audio::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Audio::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Audio_descriptor_;
}

const Audio& Audio::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_audio_5fcfg_2eproto();
  return *default_instance_;
}

Audio* Audio::default_instance_ = NULL;

Audio* Audio::New() const {
  return new Audio;
}

void Audio::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    id_ = 0;
    if (has_file()) {
      if (file_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        file_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Audio::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.Audio)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .gamer.cfg.AudioIDs id = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::gamer::cfg::AudioIDs_IsValid(value)) {
            set_id(static_cast< ::gamer::cfg::AudioIDs >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_file;
        break;
      }

      // required string file = 2;
      case 2: {
        if (tag == 18) {
         parse_file:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_file()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->file().data(), this->file().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "file");
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
  // @@protoc_insertion_point(parse_success:gamer.cfg.Audio)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.Audio)
  return false;
#undef DO_
}

void Audio::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.Audio)
  // required .gamer.cfg.AudioIDs id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->id(), output);
  }

  // required string file = 2;
  if (has_file()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->file().data(), this->file().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "file");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->file(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.Audio)
}

::google::protobuf::uint8* Audio::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.Audio)
  // required .gamer.cfg.AudioIDs id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->id(), target);
  }

  // required string file = 2;
  if (has_file()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->file().data(), this->file().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "file");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->file(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.Audio)
  return target;
}

int Audio::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .gamer.cfg.AudioIDs id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->id());
    }

    // required string file = 2;
    if (has_file()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->file());
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

void Audio::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Audio* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Audio*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Audio::MergeFrom(const Audio& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_file()) {
      set_file(from.file());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Audio::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Audio::CopyFrom(const Audio& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Audio::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Audio::Swap(Audio* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(file_, other->file_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Audio::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Audio_descriptor_;
  metadata.reflection = Audio_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int AudioCfg::kAudioFieldNumber;
#endif  // !_MSC_VER

AudioCfg::AudioCfg()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.AudioCfg)
}

void AudioCfg::InitAsDefaultInstance() {
}

AudioCfg::AudioCfg(const AudioCfg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.AudioCfg)
}

void AudioCfg::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AudioCfg::~AudioCfg() {
  // @@protoc_insertion_point(destructor:gamer.cfg.AudioCfg)
  SharedDtor();
}

void AudioCfg::SharedDtor() {
  if (this != default_instance_) {
  }
}

void AudioCfg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AudioCfg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AudioCfg_descriptor_;
}

const AudioCfg& AudioCfg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_audio_5fcfg_2eproto();
  return *default_instance_;
}

AudioCfg* AudioCfg::default_instance_ = NULL;

AudioCfg* AudioCfg::New() const {
  return new AudioCfg;
}

void AudioCfg::Clear() {
  audio_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AudioCfg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.AudioCfg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .gamer.cfg.Audio audio = 1;
      case 1: {
        if (tag == 10) {
         parse_audio:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_audio()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_audio;
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
  // @@protoc_insertion_point(parse_success:gamer.cfg.AudioCfg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.AudioCfg)
  return false;
#undef DO_
}

void AudioCfg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.AudioCfg)
  // repeated .gamer.cfg.Audio audio = 1;
  for (int i = 0; i < this->audio_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->audio(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.AudioCfg)
}

::google::protobuf::uint8* AudioCfg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.AudioCfg)
  // repeated .gamer.cfg.Audio audio = 1;
  for (int i = 0; i < this->audio_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->audio(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.AudioCfg)
  return target;
}

int AudioCfg::ByteSize() const {
  int total_size = 0;

  // repeated .gamer.cfg.Audio audio = 1;
  total_size += 1 * this->audio_size();
  for (int i = 0; i < this->audio_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->audio(i));
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

void AudioCfg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AudioCfg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AudioCfg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AudioCfg::MergeFrom(const AudioCfg& from) {
  GOOGLE_CHECK_NE(&from, this);
  audio_.MergeFrom(from.audio_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AudioCfg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AudioCfg::CopyFrom(const AudioCfg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AudioCfg::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->audio())) return false;
  return true;
}

void AudioCfg::Swap(AudioCfg* other) {
  if (other != this) {
    audio_.Swap(&other->audio_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AudioCfg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AudioCfg_descriptor_;
  metadata.reflection = AudioCfg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace cfg
}  // namespace gamer

// @@protoc_insertion_point(global_scope)