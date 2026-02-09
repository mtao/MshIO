#include <catch2/catch_all.hpp>
#include <sstream>

#include <mshio/mshio.h>


TEST_CASE("Load_mdspan", "[io]")
{
    using namespace mshio;
    MshSpec spec;
    SECTION("v2.2 ascii")
    {
        spec = load_msh(MSHIO_DATA_DIR "/test_2.2_ascii.msh");
        validate_spec(spec);
        REQUIRE(spec.nodes.num_nodes == 6);
        REQUIRE(spec.elements.num_elements == 2);


        // REQUIRE(spec.nodes.num_nodes == spec.nodes.entity_blocks.size());
        for (size_t j = 0; j < spec.nodes.entity_blocks.size(); ++j) {
            auto & node_block = spec.nodes.entity_blocks[j];
            const auto & node_block_const = spec.nodes.entity_blocks[j];

            auto tags = node_block.tags_as_mdspan();
            auto data = node_block.data_as_mdspan();

            REQUIRE(tags.size() == node_block.num_nodes_in_block);
            REQUIRE(data.extent(1) == node_block.num_nodes_in_block);
        }
    }

    SECTION("v2.2 binary")
    {
        spec = load_msh(MSHIO_DATA_DIR "/test_2.2_bin.msh");
        validate_spec(spec);
        REQUIRE(spec.nodes.num_nodes == 6);
        REQUIRE(spec.elements.num_elements == 2);
    }

    SECTION("v4.1 ascii")
    {
        spec = load_msh(MSHIO_DATA_DIR "/test_4.1_ascii.msh");
        validate_spec(spec);
        REQUIRE(spec.nodes.num_nodes == 6);
        REQUIRE(spec.elements.num_elements == 2);
    }

    SECTION("v4.1 binary")
    {
        spec = load_msh(MSHIO_DATA_DIR "/test_4.1_bin.msh");
        validate_spec(spec);
        REQUIRE(spec.nodes.num_nodes == 6);
        REQUIRE(spec.elements.num_elements == 2);
    }
}
