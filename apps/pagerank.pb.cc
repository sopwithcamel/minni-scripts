// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "pagerank.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace pagerank {

namespace {

const ::google::protobuf::Descriptor* pao_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  pao_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_pagerank_2eproto() {
  protobuf_AddDesc_pagerank_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "pagerank.proto");
  GOOGLE_CHECK(file != NULL);
  pao_descriptor_ = file->message_type(0);
  static const int pao_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pao, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pao, rank_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pao, links_),
  };
  pao_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      pao_descriptor_,
      pao::default_instance_,
      pao_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pao, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pao, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(pao));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_pagerank_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    pao_descriptor_, &pao::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_pagerank_2eproto() {
  delete pao::default_instance_;
  delete pao_reflection_;
}

void protobuf_AddDesc_pagerank_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016pagerank.proto\022\010pagerank\"/\n\003pao\022\013\n\003key"
    "\030\001 \002(\014\022\014\n\004rank\030\002 \002(\002\022\r\n\005links\030\003 \003(\tB\002H\001", 79);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "pagerank.proto", &protobuf_RegisterTypes);
  pao::default_instance_ = new pao();
  pao::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_pagerank_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_pagerank_2eproto {
  StaticDescriptorInitializer_pagerank_2eproto() {
    protobuf_AddDesc_pagerank_2eproto();
  }
} static_descriptor_initializer_pagerank_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int pao::kKeyFieldNumber;
const int pao::kRankFieldNumber;
const int pao::kLinksFieldNumber;
#endif  // !_MSC_VER

pao::pao()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void pao::InitAsDefaultInstance() {
}

pao::pao(const pao& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void pao::SharedCtor() {
  _cached_size_ = 0;
  key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  rank_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

pao::~pao() {
  SharedDtor();
}

void pao::SharedDtor() {
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    delete key_;
  }
  if (this != default_instance_) {
  }
}

void pao::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* pao::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return pao_descriptor_;
}

const pao& pao::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_pagerank_2eproto();  return *default_instance_;
}

pao* pao::default_instance_ = NULL;

pao* pao::New() const {
  return new pao;
}

void pao::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_key()) {
      if (key_ != &::google::protobuf::internal::kEmptyString) {
        key_->clear();
      }
    }
    rank_ = 0;
  }
  links_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool pao::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes key = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_key()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_rank;
        break;
      }
      
      // required float rank = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_rank:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &rank_)));
          set_has_rank();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_links;
        break;
      }
      
      // repeated string links = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_links:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_links()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->links(0).data(), this->links(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_links;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void pao::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required bytes key = 1;
  if (has_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->key(), output);
  }
  
  // required float rank = 2;
  if (has_rank()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->rank(), output);
  }
  
  // repeated string links = 3;
  for (int i = 0; i < this->links_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->links(i).data(), this->links(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->links(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* pao::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes key = 1;
  if (has_key()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->key(), target);
  }
  
  // required float rank = 2;
  if (has_rank()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->rank(), target);
  }
  
  // repeated string links = 3;
  for (int i = 0; i < this->links_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->links(i).data(), this->links(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->links(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int pao::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes key = 1;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->key());
    }
    
    // required float rank = 2;
    if (has_rank()) {
      total_size += 1 + 4;
    }
    
  }
  // repeated string links = 3;
  total_size += 1 * this->links_size();
  for (int i = 0; i < this->links_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->links(i));
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

void pao::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const pao* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const pao*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void pao::MergeFrom(const pao& from) {
  GOOGLE_CHECK_NE(&from, this);
  links_.MergeFrom(from.links_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_key()) {
      set_key(from.key());
    }
    if (from.has_rank()) {
      set_rank(from.rank());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void pao::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void pao::CopyFrom(const pao& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool pao::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void pao::Swap(pao* other) {
  if (other != this) {
    std::swap(key_, other->key_);
    std::swap(rank_, other->rank_);
    links_.Swap(&other->links_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata pao::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = pao_descriptor_;
  metadata.reflection = pao_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pagerank

// @@protoc_insertion_point(global_scope)
