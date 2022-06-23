R__LOAD_LIBRARY(ROOTNTuple)

#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleModel.hxx>

#include "tests/datamodel/ExampleMCCollection.h"


using RNTupleModel = ROOT::Experimental::RNTupleModel;
using RNTupleReader = ROOT::Experimental::RNTupleReader;
using RNTupleWriter = ROOT::Experimental::RNTupleWriter;
using RFieldBase = ROOT::Experimental::Detail::RFieldBase;

void read() {
gSystem->Load("libTestDataModel");
gSystem->Load("libpodio");
gSystem->Load("libpodioDict");
auto model = RNTupleModel::Create();
 
// We only define the fields that are needed for reading
auto fldVpx = model->MakeField<std::vector<ExampleMC>>("mcparticles");

// Create an ntuple without imposing a specific data model.  We could gen    erate the data model from the ntuple
// but here we prefer the view because we only want to access a single fi    eld
auto ntuple = RNTupleReader::Open(std::move(model), "F", "build/tests/example_rntuple.root")    ;

// Quick overview of the ntuple's key meta-data
ntuple->PrintInfo();
}
