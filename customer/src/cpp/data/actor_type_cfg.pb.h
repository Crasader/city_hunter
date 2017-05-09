// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: actor_type_cfg.proto

#ifndef PROTOBUF_actor_5ftype_5fcfg_2eproto__INCLUDED
#define PROTOBUF_actor_5ftype_5fcfg_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace cfg {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_actor_5ftype_5fcfg_2eproto();
void protobuf_AssignDesc_actor_5ftype_5fcfg_2eproto();
void protobuf_ShutdownFile_actor_5ftype_5fcfg_2eproto();


enum ActorTypes {
  ACTOR_HERO_KNIGHT = 0,
  ACTOR_HERO_ARCHER = 1,
  ACTOR_HERO_MAGE = 2
};
bool ActorTypes_IsValid(int value);
const ActorTypes ActorTypes_MIN = ACTOR_HERO_KNIGHT;
const ActorTypes ActorTypes_MAX = ACTOR_HERO_MAGE;
const int ActorTypes_ARRAYSIZE = ActorTypes_MAX + 1;

const ::google::protobuf::EnumDescriptor* ActorTypes_descriptor();
inline const ::std::string& ActorTypes_Name(ActorTypes value) {
  return ::google::protobuf::internal::NameOfEnum(
    ActorTypes_descriptor(), value);
}
inline bool ActorTypes_Parse(
    const ::std::string& name, ActorTypes* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ActorTypes>(
    ActorTypes_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace cfg
}  // namespace gamer

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::gamer::cfg::ActorTypes> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::gamer::cfg::ActorTypes>() {
  return ::gamer::cfg::ActorTypes_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_actor_5ftype_5fcfg_2eproto__INCLUDED
