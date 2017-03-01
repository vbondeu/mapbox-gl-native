#include <mbgl/test/util.hpp>
#include <mbgl/style/sources/geojson_source.hpp>


#include <mbgl/style/sources/custom_vector_source.hpp>

using namespace mbgl;


TEST(CustomVectorSource, EmptyData) {
    mbgl::style::GeoJSONOptions options;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
    const auto callback = ^void(uint8_t z, uint32_t x, uint32_t y) {};
#pragma clang diagnostic pop

    auto testSource = std::make_unique<mbgl::style::CustomVectorSource>("source", options,  callback);

    mbgl::FeatureCollection featureCollection;
    testSource->setTileData(0, 0, 0, mbgl::GeoJSON{featureCollection});
}
