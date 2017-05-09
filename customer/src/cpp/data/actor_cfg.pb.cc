// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: actor_cfg.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "actor_cfg.pb.h"

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

const ::google::protobuf::Descriptor* Actor_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Actor_reflection_ = NULL;
const ::google::protobuf::Descriptor* ActorCfg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ActorCfg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_actor_5fcfg_2eproto() {
  protobuf_AddDesc_actor_5fcfg_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "actor_cfg.proto");
  GOOGLE_CHECK(file != NULL);
  Actor_descriptor_ = file->message_type(0);
  static const int Actor_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, actor_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, model_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, position_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, rotation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, scale_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, ai_update_interval_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, first_state_id_),
  };
  Actor_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Actor_descriptor_,
      Actor::default_instance_,
      Actor_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Actor, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Actor));
  ActorCfg_descriptor_ = file->message_type(1);
  static const int ActorCfg_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActorCfg, actor_),
  };
  ActorCfg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ActorCfg_descriptor_,
      ActorCfg::default_instance_,
      ActorCfg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActorCfg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActorCfg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ActorCfg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_actor_5fcfg_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Actor_descriptor_, &Actor::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ActorCfg_descriptor_, &ActorCfg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_actor_5fcfg_2eproto() {
  delete Actor::default_instance_;
  delete Actor_reflection_;
  delete ActorCfg::default_instance_;
  delete ActorCfg_reflection_;
}

void protobuf_AddDesc_actor_5fcfg_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::gamer::cfg::protobuf_AddDesc_actor_5ftype_5fcfg_2eproto();
  ::gamer::cfg::protobuf_AddDesc_common_5fcfg_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017actor_cfg.proto\022\tgamer.cfg\032\024actor_type"
    "_cfg.proto\032\020common_cfg.proto\"\334\001\n\005Actor\022\n"
    "\n\002id\030\001 \002(\005\022)\n\nactor_type\030\002 \002(\0162\025.gamer.c"
    "fg.ActorTypes\022\020\n\010model_id\030\003 \002(\005\022!\n\010posit"
    "ion\030\004 \002(\0132\017.gamer.cfg.Vec3\022!\n\010rotation\030\005"
    " \002(\0132\017.gamer.cfg.Vec3\022\020\n\005scale\030\006 \001(\002:\0011\022"
    "\032\n\022ai_update_interval\030\007 \002(\002\022\026\n\016first_sta"
    "te_id\030\010 \002(\005\"+\n\010ActorCfg\022\037\n\005actor\030\001 \003(\0132\020"
    ".gamer.cfg.Actor", 336);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "actor_cfg.proto", &protobuf_RegisterTypes);
  Actor::default_instance_ = new Actor();
  ActorCfg::default_instance_ = new ActorCfg();
  Actor::default_instance_->InitAsDefaultInstance();
  ActorCfg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_actor_5fcfg_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_actor_5fcfg_2eproto {
  StaticDescriptorInitializer_actor_5fcfg_2eproto() {
    protobuf_AddDesc_actor_5fcfg_2eproto();
  }
} static_descriptor_initializer_actor_5fcfg_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Actor::kIdFieldNumber;
const int Actor::kActorTypeFieldNumber;
const int Actor::kModelIdFieldNumber;
const int Actor::kPositionFieldNumber;
const int Actor::kRotationFieldNumber;
const int Actor::kScaleFieldNumber;
const int Actor::kAiUpdateIntervalFieldNumber;
const int Actor::kFirstStateIdFieldNumber;
#endif  // !_MSC_VER

Actor::Actor()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.Actor)
}

void Actor::InitAsDefaultInstance() {
  position_ = const_cast< ::gamer::cfg::Vec3*>(&::gamer::cfg::Vec3::default_instance());
  rotation_ = const_cast< ::gamer::cfg::Vec3*>(&::gamer::cfg::Vec3::default_instance());
}

Actor::Actor(const Actor& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.Actor)
}

void Actor::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  actor_type_ = 0;
  model_id_ = 0;
  position_ = NULL;
  rotation_ = NULL;
  scale_ = 1;
  ai_update_interval_ = 0;
  first_state_id_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Actor::~Actor() {
  // @@protoc_insertion_point(destructor:gamer.cfg.Actor)
  SharedDtor();
}

void Actor::SharedDtor() {
  if (this != default_instance_) {
    delete position_;
    delete rotation_;
  }
}

void Actor::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Actor::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Actor_descriptor_;
}

const Actor& Actor::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_actor_5fcfg_2eproto();
  return *default_instance_;
}

Actor* Actor::default_instance_ = NULL;

Actor* Actor::New() const {
  return new Actor;
}

void Actor::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Actor*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(id_, actor_type_);
    ZR_(ai_update_interval_, first_state_id_);
    model_id_ = 0;
    if (has_position()) {
      if (position_ != NULL) position_->::gamer::cfg::Vec3::Clear();
    }
    if (has_rotation()) {
      if (rotation_ != NULL) rotation_->::gamer::cfg::Vec3::Clear();
    }
    scale_ = 1;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Actor::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.Actor)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_actor_type;
        break;
      }

      // required .gamer.cfg.ActorTypes actor_type = 2;
      case 2: {
        if (tag == 16) {
         parse_actor_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::gamer::cfg::ActorTypes_IsValid(value)) {
            set_actor_type(static_cast< ::gamer::cfg::ActorTypes >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_model_id;
        break;
      }

      // required int32 model_id = 3;
      case 3: {
        if (tag == 24) {
         parse_model_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &model_id_)));
          set_has_model_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_position;
        break;
      }

      // required .gamer.cfg.Vec3 position = 4;
      case 4: {
        if (tag == 34) {
         parse_position:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_position()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_rotation;
        break;
      }

      // required .gamer.cfg.Vec3 rotation = 5;
      case 5: {
        if (tag == 42) {
         parse_rotation:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_rotation()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(53)) goto parse_scale;
        break;
      }

      // optional float scale = 6 [default = 1];
      case 6: {
        if (tag == 53) {
         parse_scale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &scale_)));
          set_has_scale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(61)) goto parse_ai_update_interval;
        break;
      }

      // required float ai_update_interval = 7;
      case 7: {
        if (tag == 61) {
         parse_ai_update_interval:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &ai_update_interval_)));
          set_has_ai_update_interval();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_first_state_id;
        break;
      }

      // required int32 first_state_id = 8;
      case 8: {
        if (tag == 64) {
         parse_first_state_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &first_state_id_)));
          set_has_first_state_id();
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
  // @@protoc_insertion_point(parse_success:gamer.cfg.Actor)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.Actor)
  return false;
#undef DO_
}

void Actor::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.Actor)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required .gamer.cfg.ActorTypes actor_type = 2;
  if (has_actor_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->actor_type(), output);
  }

  // required int32 model_id = 3;
  if (has_model_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->model_id(), output);
  }

  // required .gamer.cfg.Vec3 position = 4;
  if (has_position()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->position(), output);
  }

  // required .gamer.cfg.Vec3 rotation = 5;
  if (has_rotation()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->rotation(), output);
  }

  // optional float scale = 6 [default = 1];
  if (has_scale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->scale(), output);
  }

  // required float ai_update_interval = 7;
  if (has_ai_update_interval()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(7, this->ai_update_interval(), output);
  }

  // required int32 first_state_id = 8;
  if (has_first_state_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->first_state_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.Actor)
}

::google::protobuf::uint8* Actor::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.Actor)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required .gamer.cfg.ActorTypes actor_type = 2;
  if (has_actor_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->actor_type(), target);
  }

  // required int32 model_id = 3;
  if (has_model_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->model_id(), target);
  }

  // required .gamer.cfg.Vec3 position = 4;
  if (has_position()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->position(), target);
  }

  // required .gamer.cfg.Vec3 rotation = 5;
  if (has_rotation()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->rotation(), target);
  }

  // optional float scale = 6 [default = 1];
  if (has_scale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->scale(), target);
  }

  // required float ai_update_interval = 7;
  if (has_ai_update_interval()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(7, this->ai_update_interval(), target);
  }

  // required int32 first_state_id = 8;
  if (has_first_state_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->first_state_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.Actor)
  return target;
}

int Actor::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required .gamer.cfg.ActorTypes actor_type = 2;
    if (has_actor_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->actor_type());
    }

    // required int32 model_id = 3;
    if (has_model_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->model_id());
    }

    // required .gamer.cfg.Vec3 position = 4;
    if (has_position()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->position());
    }

    // required .gamer.cfg.Vec3 rotation = 5;
    if (has_rotation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->rotation());
    }

    // optional float scale = 6 [default = 1];
    if (has_scale()) {
      total_size += 1 + 4;
    }

    // required float ai_update_interval = 7;
    if (has_ai_update_interval()) {
      total_size += 1 + 4;
    }

    // required int32 first_state_id = 8;
    if (has_first_state_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->first_state_id());
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

void Actor::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Actor* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Actor*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Actor::MergeFrom(const Actor& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_actor_type()) {
      set_actor_type(from.actor_type());
    }
    if (from.has_model_id()) {
      set_model_id(from.model_id());
    }
    if (from.has_position()) {
      mutable_position()->::gamer::cfg::Vec3::MergeFrom(from.position());
    }
    if (from.has_rotation()) {
      mutable_rotation()->::gamer::cfg::Vec3::MergeFrom(from.rotation());
    }
    if (from.has_scale()) {
      set_scale(from.scale());
    }
    if (from.has_ai_update_interval()) {
      set_ai_update_interval(from.ai_update_interval());
    }
    if (from.has_first_state_id()) {
      set_first_state_id(from.first_state_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Actor::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Actor::CopyFrom(const Actor& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Actor::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000df) != 0x000000df) return false;

  if (has_position()) {
    if (!this->position().IsInitialized()) return false;
  }
  if (has_rotation()) {
    if (!this->rotation().IsInitialized()) return false;
  }
  return true;
}

void Actor::Swap(Actor* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(actor_type_, other->actor_type_);
    std::swap(model_id_, other->model_id_);
    std::swap(position_, other->position_);
    std::swap(rotation_, other->rotation_);
    std::swap(scale_, other->scale_);
    std::swap(ai_update_interval_, other->ai_update_interval_);
    std::swap(first_state_id_, other->first_state_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Actor::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Actor_descriptor_;
  metadata.reflection = Actor_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ActorCfg::kActorFieldNumber;
#endif  // !_MSC_VER

ActorCfg::ActorCfg()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.cfg.ActorCfg)
}

void ActorCfg::InitAsDefaultInstance() {
}

ActorCfg::ActorCfg(const ActorCfg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.cfg.ActorCfg)
}

void ActorCfg::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ActorCfg::~ActorCfg() {
  // @@protoc_insertion_point(destructor:gamer.cfg.ActorCfg)
  SharedDtor();
}

void ActorCfg::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ActorCfg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ActorCfg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ActorCfg_descriptor_;
}

const ActorCfg& ActorCfg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_actor_5fcfg_2eproto();
  return *default_instance_;
}

ActorCfg* ActorCfg::default_instance_ = NULL;

ActorCfg* ActorCfg::New() const {
  return new ActorCfg;
}

void ActorCfg::Clear() {
  actor_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ActorCfg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.cfg.ActorCfg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .gamer.cfg.Actor actor = 1;
      case 1: {
        if (tag == 10) {
         parse_actor:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_actor()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_actor;
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
  // @@protoc_insertion_point(parse_success:gamer.cfg.ActorCfg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.cfg.ActorCfg)
  return false;
#undef DO_
}

void ActorCfg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.cfg.ActorCfg)
  // repeated .gamer.cfg.Actor actor = 1;
  for (int i = 0; i < this->actor_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->actor(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.cfg.ActorCfg)
}

::google::protobuf::uint8* ActorCfg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.cfg.ActorCfg)
  // repeated .gamer.cfg.Actor actor = 1;
  for (int i = 0; i < this->actor_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->actor(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.cfg.ActorCfg)
  return target;
}

int ActorCfg::ByteSize() const {
  int total_size = 0;

  // repeated .gamer.cfg.Actor actor = 1;
  total_size += 1 * this->actor_size();
  for (int i = 0; i < this->actor_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->actor(i));
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

void ActorCfg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ActorCfg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ActorCfg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ActorCfg::MergeFrom(const ActorCfg& from) {
  GOOGLE_CHECK_NE(&from, this);
  actor_.MergeFrom(from.actor_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ActorCfg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ActorCfg::CopyFrom(const ActorCfg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ActorCfg::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->actor())) return false;
  return true;
}

void ActorCfg::Swap(ActorCfg* other) {
  if (other != this) {
    actor_.Swap(&other->actor_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ActorCfg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ActorCfg_descriptor_;
  metadata.reflection = ActorCfg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace cfg
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
