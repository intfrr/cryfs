#pragma once
#ifndef MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_CIPHERS_CIPHER_H_
#define MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_CIPHERS_CIPHER_H_

#include <boost/concept_check.hpp>
#include <cstdint>
#include <messmer/cpp-utils/data/Data.h>
#include <messmer/cpp-utils/random/Random.h>

namespace blockstore {
namespace encrypted {

template<class X>
struct CipherConcept {
public:
  BOOST_CONCEPT_USAGE(CipherConcept) {
    same_type(UINT32_C(0), X::ciphertextSize(UINT32_C(5)));
    same_type(UINT32_C(0), X::plaintextSize(UINT32_C(5)));
    typename X::EncryptionKey key = X::CreateKey(cpputils::Random::OSRandom());
    same_type(cpputils::Data(0), X::encrypt((uint8_t*)nullptr, UINT32_C(0), key));
    same_type(boost::optional<cpputils::Data>(cpputils::Data(0)), X::decrypt((uint8_t*)nullptr, UINT32_C(0), key));
  }

private:
  // Type deduction will fail unless the arguments have the same type.
  template <typename T> void same_type(T const&, T const&);
};

}
}



#endif