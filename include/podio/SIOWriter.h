#ifndef SIOWRITER_H
#define SIOWRITER_H

#include "podio/CollectionBase.h"
#include "podio/EventStore.h"
#include "podio/SIOBlock.h"

// SIO specific includes
#include <sio/definitions.h>
#include <sio/exception.h>
#include <sio/api.h>

#include <string>
#include <vector>
#include <iostream>

// forward declarations


namespace podio {
  class SIOWriter {

  public:
    SIOWriter(const std::string& filename, EventStore* store);
    ~SIOWriter();

    void registerForWrite(const std::string& name);
    void writeEvent();
    void finish();

  private:
    void writeCollectionIDTable();

    // members
    std::string m_filename{};
    EventStore* m_store=nullptr;

    std::shared_ptr<SIOEventMetaDataBlock> m_eventMetaData;
    sio::ofstream m_stream{} ;
    sio::block_list  m_blocks {} ;
    sio::buffer m_buffer{ sio::mbyte } ;
    sio::buffer m_com_buffer{ sio::mbyte } ;
    bool m_firstEvent{true};

    std::shared_ptr<SIONumberedMetaDataBlock> m_runMetaData;
    std::shared_ptr<SIONumberedMetaDataBlock> m_collectionMetaData;
  };

} //namespace
#endif