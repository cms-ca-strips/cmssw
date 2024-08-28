#ifndef Geometry_CommonTopologies_SimplePixelStripTopology_h
#define Geometry_CommonTopologies_SimplePixelStripTopology_h
#include <iostream>
#include "Geometry/CommonTopologies/interface/SimplePixelTopology.h"

namespace phase1PixelStripTopology {
  
  struct LayerData {
    uint32_t start;
    uint32_t end;
    bool isStrip2D = false; // if true then map every two module indices to the same sequential ID
  };

  enum Layer : uint8_t;

  struct LayerPairData {
    Layer inner;
    Layer outer;
    int16_t phicut;
    float minz;
    float maxz;
    float maxr;
  };

  enum Layer : uint8_t {
    BPIX1 = 0,
    BPIX2,
    BPIX3,
    BPIX4,
    FPIX1Pos,
    FPIX2Pos,
    FPIX3Pos,
    FPIX1Neg,
    FPIX2Neg,
    FPIX3Neg,
    TIB1,
    TIB2,
    TID1Pos2D,
    TID2Pos2D,
    TID3Pos2D,
    TID1Neg2D,
    TID2Neg2D,
    TID3Neg2D,
    nLayers
  };

  constexpr LayerData layerData[nLayers] = {
    {0,     96    },      // BPIX1 
    {96,    320   },      // BPIX2 
    {320,   672   },      // BPIX3 
    {672,   1184  },      // BPIX4 
    {1184,  1296  },      // FPIX1Pos 
    {1296,  1408  },      // FPIX2Pos 
    {1408,  1520  },      // FPIX3Pos 
    {1520,  1632  },      // FPIX1Neg 
    {1632,  1744  },      // FPIX2Neg 
    {1744,  1856  },      // FPIX3Neg 
    {1856,  2528, true},  // TIB1 
    {2528,  3392, true},  // TIB2 
    {4580,  4676, true},  // TID1Pos2D
    {4716,  4812, true},  // TID2Pos2D
    {4852,  4948, true},  // TID3Pos2D
    {4988,  5084, true},  // TID1Neg2D
    {5124,  5220, true},  // TID2Neg2D
    {5260,  5356, true},  // TID3Neg2D
  };

  using pixelTopology::phi5deg;
  using pixelTopology::phi0p05;
  using pixelTopology::phi0p06;
  using pixelTopology::phi0p07;
  using pixelTopology::phi0p09;
  //constexpr int16_t phi0p05 = 522;  // round(521.52189...) = phi2short(0.05);
  //constexpr int16_t phi0p06 = 626;  // round(625.82270...) = phi2short(0.06);
  //constexpr int16_t phi0p07 = 730;  // round(730.12648...) = phi2short(0.07);
  //constexpr int16_t phi0p09 = 900;
  //constexpr int16_t phi5deg = 1820; 
  constexpr LayerPairData layerPairData[] = {
  //  inner     outer       phicuts   minz    maxz  maxr
  { BPIX1,    BPIX2,      phi0p09,  -20.,   20.,  20.           }, // 0  (No inner layer) OK
  { BPIX1,    FPIX1Pos,   phi0p07,  0.,     30.,  9.            }, // 1  (No inner layer) OK
  { BPIX1,    FPIX1Neg,   phi0p07,  -30.,   0.,   9.            }, // 2  (No inner layer) OK
  { BPIX2,    BPIX3,      phi0p09,  -22.,   22.,  20.           }, // 3  OK
  { BPIX2,    FPIX1Pos,   phi0p09,  10.,    30.,  7.            }, // 4  OK
  { BPIX2,    FPIX1Neg,   phi0p09,  -30.,   -10., 7.            }, // 5  OK
  { FPIX1Pos, FPIX2Pos,   phi0p07,  -70.,   70.,  5.            }, // 6  OK
  { FPIX1Neg, FPIX2Neg,   phi0p07,  -70.,   70.,  5.            }, // 7  OK
  { BPIX1,    BPIX3,      phi0p09,  -20.,   20.,  20.           }, // 8 (No inner layer) OK
  { BPIX2,    BPIX4,      phi0p09,  -22.,   22.,  20.           }, // 9  OK
  { BPIX1,    FPIX2Pos,   phi0p07,    0.,   30.,  9.            }, // 10 (No inner layer) OK
  { BPIX1,    FPIX2Neg,   phi0p07,  -30.,   0.,   9.            }, // 11 (No inner layer) Until here Starting Pairs OK
  { FPIX1Pos, TIB1,       phi5deg,  -70.,   70.,  1000.         }, // 12 
  { FPIX1Neg, TIB1,       phi5deg,  -70.,   70.,  1000.         }, // 13 
  { BPIX3,    BPIX4,      phi0p09,  -22.,   22.,  20.           }, // 14    
  { BPIX3,    FPIX1Pos,   phi0p07,  15.,    30.,  6.            }, // 15 
  { BPIX3,    FPIX1Neg,   phi0p07,  -30,   -15.,  6.            }, // 16 
  { FPIX2Pos, FPIX3Pos,   phi0p07,  -70.,   70.,  5.            }, // 17 
  { FPIX2Neg, FPIX3Neg,   phi0p07,  -70.,   70.,  5.            }, // 18 
  { BPIX3,    TIB1,       phi5deg,  -22.,   22.,   1000.        }, // 19 
  { BPIX4,    TIB1,       phi5deg,  -22.,   22.,   1000.        }, // 20 
  { BPIX4,    TIB2,       phi5deg,  -22.,   22.,   1000.        }, // 21 
  { TIB1,     TIB2,       phi5deg,  -55.,   55.,   1000.        }, // 22
  { FPIX2Pos, TIB1,       phi5deg,  -70.,   70.,   1000.        }, // 23 
  { FPIX2Neg, TIB1,       phi5deg,  -70.,   70.,   1000.        }, // 24 
  { FPIX3Pos, TIB1,       phi5deg,  -70.,   70.,   1000.        }, // 25
  { FPIX3Pos, TID1Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 26 
  { FPIX3Pos, TID2Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 27
  { FPIX3Pos, TID3Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 28
  { FPIX3Neg, TIB1,       phi5deg,  -70.,   70.,   1000.        }, // 29
  { FPIX3Neg, TID1Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 30
  { FPIX3Neg, TID2Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 31
  { FPIX3Neg, TID3Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 32
  { TID1Pos2D,TID2Pos2D,  phi0p09,  -1000., 1000., 1000.        }, // 33
  { TID2Pos2D,TID3Pos2D,  phi0p09,  -1000., 1000., 1000.        }, // 34
  { TID1Neg2D,TID2Neg2D,  phi0p09,  -1000., 1000., 1000.        }, // 35
  { TID2Neg2D,TID3Neg2D,  phi0p09,  -1000., 1000., 1000.        }, // 36
  { TIB1,     TID1Pos2D,  phi5deg,   0.,    55.,   1000.        }, // 37
  { TIB1,     TID1Neg2D,  phi5deg,  -55.,   0.,    1000.        }, // 38
  { TIB2,     TID1Pos2D,  phi5deg,    0.,   55.,   1000.        }, // 39
  { TIB2,     TID1Neg2D,  phi5deg,  -55.,   0.,    1000.        }, // 40
  { BPIX2,    TIB1,       phi0p09,  -22.,   0.,    1000.        }, // 41 
  { BPIX2,    TIB2,       phi0p09,  -22.,   0.,    1000.        }, // 42
  { BPIX1,    TIB1,       phi5deg,  -22.,   0.,    1000.        }, // 43
  { BPIX1,    TIB2,       phi5deg,  -22.,   0.,    1000.        }, // 44
  { BPIX3,    TIB2,       phi5deg,  -22.,   22.,   1000.        }, // 45
  { BPIX4,    TID1Pos2D,   phi5deg,   0.,   55.,   1000.        }, // 46
  { BPIX4,    TID1Neg2D,   phi5deg,  -55.,  0.,    1000.        }, // 47
  { FPIX1Pos, FPIX3Pos,   phi0p07,  -70.,   70.,      9.        }, // 48
  { FPIX1Pos, TIB2,       phi5deg,  -70.,   70.,   1000.        }, // 49
  { FPIX1Pos, TID1Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 50
  { FPIX1Pos, TID2Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 51
  { FPIX1Pos, TID3Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 52
  { FPIX1Neg, FPIX3Neg,   phi0p07,  -70.,   70.,      9.        }, // 53
  { FPIX1Neg, TIB2,       phi5deg,  -70.,   70.,   1000.        }, // 54
  { FPIX1Neg, TID1Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 55
  { FPIX1Neg, TID2Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 56
  { FPIX1Neg, TID3Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 57
  { FPIX2Pos, TIB2,       phi5deg,  -70.,   70.,   1000.        }, // 58
  { FPIX2Pos, TID1Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 59
  { FPIX2Pos, TID2Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 60
  { FPIX2Pos, TID3Pos2D,  phi5deg,  -70.,   70.,   1000.        }, // 61
  { FPIX2Neg, TIB2,       phi5deg,  -70.,   70.,   1000.        }, // 62
  { FPIX2Neg, TID1Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 63
  { FPIX2Neg, TID2Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 64
  { FPIX2Neg, TID3Neg2D,  phi5deg,  -70.,   70.,   1000.        }, // 65
  { FPIX3Pos, TIB2,       phi5deg,  -70.,   70.,   1000.        }, // 66
  { FPIX3Neg, TIB2,       phi5deg,  -70.,   70.,   1000.        }  // 67
  };
  
  constexpr uint32_t maxNumClustersPerModules = 1024;
  constexpr auto numberOfLayers = nLayers;
  constexpr auto nPairs = std::size(layerPairData);

  constexpr auto makeLayerStart() {
    std::array<uint32_t, numberOfLayers + 1> layerStart = {{0}};
    for (auto i = 0u; i < numberOfLayers; ++i)
      if (layerData[i].isStrip2D)
        layerStart[i + 1] = layerStart[i] + (layerData[i].end - layerData[i].start) / 2;
      else
        layerStart[i + 1] = layerStart[i] + layerData[i].end - layerData[i].start;
    return layerStart;
  }

  HOST_DEVICE_CONSTANT std::array<uint32_t, numberOfLayers + 1> layerStart = makeLayerStart();
  
  constexpr uint16_t numberOfModules = layerStart[numberOfLayers];

  constexpr auto makeLayerPairs() {
    std::array<uint8_t, 2 * nPairs> layerPairs = {{0}};
    for (auto i = 0u; i < nPairs; ++i) {
      layerPairs[2 * i] = layerPairData[i].inner;
      layerPairs[2 * i + 1] = layerPairData[i].outer;
    }
    return layerPairs;
  }

  HOST_DEVICE_CONSTANT std::array<uint8_t, 2 * nPairs> layerPairs = makeLayerPairs();

  template <class T, class F>
  constexpr auto makePairCutsArray(F&& f) {
    std::array<T, nPairs> result{};
    for (auto i = 0u; i < nPairs; ++i)
      result[i] = f(layerPairData[i]);
    return result;
  }

  HOST_DEVICE_CONSTANT std::array<int16_t, nPairs> phicuts = makePairCutsArray<int16_t>([] (const auto& x) { return x.phicut; });
  HOST_DEVICE_CONSTANT std::array<float, nPairs> minz = makePairCutsArray<float>([] (const auto& x) { return x.minz; });
  HOST_DEVICE_CONSTANT std::array<float, nPairs> maxz = makePairCutsArray<float>([] (const auto& x) { return x.maxz; });
  HOST_DEVICE_CONSTANT std::array<float, nPairs> maxr = makePairCutsArray<float>([] (const auto& x) { return x.maxr; });

  using IndexMap = std::array<int, layerData[numberOfLayers - 1].end>;

  constexpr IndexMap makeIndexMap() {
    IndexMap indexMap = {{0}};
    for (auto& i : indexMap)
      i = numberOfModules;
    int newIndex = 0;
    for (const auto& layer : layerData) {
      for (auto i = layer.start; i < layer.end; ++i) {
        indexMap[i] = newIndex;
        if (!layer.isStrip2D || i % 2 == 1)
          ++newIndex;
      }
    }
    return indexMap;
  }

  constexpr IndexMap indexMap = makeIndexMap();

} // namespace phase1PixelStripTopology

namespace pixelTopology {

  struct Phase1Strip : public Phase1 {

    typedef Phase1 PixelBase; //Could be removed using based class
    static constexpr uint32_t maxNumClustersPerModules = phase1PixelStripTopology::maxNumClustersPerModules;
    static constexpr uint32_t maxHitsInModule = phase1PixelStripTopology::maxNumClustersPerModules;
    static constexpr uint32_t maxNumberOfHits = 256 * 2048;
    static constexpr uint32_t maxCellNeighbors = 64;
    static constexpr uint32_t maxCellTracks = 302;
    static constexpr uint32_t maxHitsOnTrack = 15;
    static constexpr uint32_t maxHitsOnTrackForFullFit = 6;
    static constexpr uint32_t avgHitsPerTrack = 7;
    static constexpr uint32_t maxCellsPerHit = 256;
    static constexpr uint32_t avgTracksPerHit = 10;
    static constexpr uint32_t maxNumberOfTuples = 256 * 2048;
    //this is well above thanks to maxNumberOfTuples
    static constexpr uint32_t maxHitsForContainers = avgHitsPerTrack * maxNumberOfTuples;
    static constexpr uint32_t maxNumberOfDoublets = 5 * 512 * 2048;
    static constexpr uint32_t maxNumOfActiveDoublets = maxNumberOfDoublets / 8;
    static constexpr uint32_t maxNumberOfQuadruplets = maxNumberOfTuples*4;
    static constexpr uint32_t maxDepth = 12;

    static constexpr uint32_t const *layerStart = phase1PixelStripTopology::layerStart.data();
    
    static constexpr float const *minz = phase1PixelStripTopology::minz.data();
    static constexpr float const *maxz = phase1PixelStripTopology::maxz.data();
    static constexpr float const *maxr = phase1PixelStripTopology::maxr.data();

    static constexpr uint8_t const *layerPairs = phase1PixelStripTopology::layerPairs.data();
    static constexpr int16_t const *phicuts = phase1PixelStripTopology::phicuts.data();

    static constexpr uint32_t numberOfLayers = phase1PixelStripTopology::numberOfLayers;
    static constexpr uint32_t numberOfStripLayers = numberOfLayers - numberOfPixelLayers;

    static constexpr uint16_t numberOfModules = phase1PixelStripTopology::numberOfModules;
    static constexpr uint16_t numberOfPixelModules = phase1PixelStripTopology::layerStart[numberOfPixelLayers];
    static constexpr uint16_t numberOfStripModules = numberOfModules - numberOfPixelModules;

    static constexpr int nPairsForQuadruplets = phase1PixelStripTopology::nPairs;                     // quadruplets require hits in all layers
    static constexpr int nPairsForTriplets = nPairsForQuadruplets ;  // include barrel "jumping" layer pairs
    static constexpr int nPairs = nPairsForTriplets;                // include forward "jumping" layer pairs


    static constexpr char const *nameModifier = "Phase1Strip";
    
    static constexpr int mapIndex(int i) {
      if (i > 0 && i < (int)phase1PixelStripTopology::indexMap.size())
        return phase1PixelStripTopology::indexMap[i];
      else
        return i;
    }
  };
  
}  // namespace pixelTopology

#endif  // Geometry_CommonTopologies_SimplePixelStripTopology_h
