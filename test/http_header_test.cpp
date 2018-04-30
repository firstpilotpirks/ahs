#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "ahs/http/http_header.h"

BOOST_AUTO_TEST_SUITE(http_header_test)

    BOOST_AUTO_TEST_CASE(constructor_init)
    {
        http_header::header_data data
                {
                        {"param_1", "value_1"},
                        {"param_2", "value_2"},
                        {"param_3", "value_3"},
                };

        http_header header(data);

        BOOST_CHECK_EQUAL(header["param_1"], "value_1");
        BOOST_CHECK_EQUAL(header["param_2"], "value_2");
        BOOST_CHECK_EQUAL(header["param_3"], "value_3");
    }

    BOOST_AUTO_TEST_CASE(constructor_init_move)
    {
        http_header header(http_header::header_data
                {
                        {"param_1", "value_1"},
                        {"param_2", "value_2"},
                        {"param_3", "value_3"},
                });

        BOOST_CHECK_EQUAL(header["param_1"], "value_1");
        BOOST_CHECK_EQUAL(header["param_2"], "value_2");
        BOOST_CHECK_EQUAL(header["param_3"], "value_3");
    }

    BOOST_AUTO_TEST_CASE(access_to_element)
    {
        http_header header(http_header::header_data
                                   {
                                           {"param_1", "value_1"},
                                           {"param_2", "value_2"},
                                           {"param_3", "value_3"},
                                   });

        header["param_1"] = "value_over_9001";
        header["param_2"] = "value_over_9002";
        header["param_3"] = "value_over_9003";

        BOOST_CHECK_EQUAL(header["param_1"], "value_over_9001");
        BOOST_CHECK_EQUAL(header["param_2"], "value_over_9002");
        BOOST_CHECK_EQUAL(header["param_3"], "value_over_9003");
    }

BOOST_AUTO_TEST_SUITE_END()
