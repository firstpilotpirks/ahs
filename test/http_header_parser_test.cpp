#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "ahs/http/http_header_parser.hpp"

BOOST_AUTO_TEST_SUITE(http_header_parser_test)

 BOOST_AUTO_TEST_CASE(parse) {

   std::string raw_header(
       "GET /tutorials/other/top-20-mysql-best-practices/ HTTP/1.1\r\n"
       "Host: net.tutsplus.com\r\n"
       "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\n"
       " Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;"
       "q=0.8\r\n"
       "   Accept-Language: en-us,en;q=0.5\r\n"
       "Accept-Encoding : gzip,deflate\r\n"
       "Accept-Charset   : ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n"
       "      Keep-Alive     : 300\r\n"
       " Connection : keep-alive\r\n"
       "Cookie:       PHPSESSID=r2t5uvjq435r4q7ib3vtdjq120   \r\n"
       "Pragma: no-cache   \r\n"
       "Cache-Control:    no-cache\r\n"
   );

   http_header_parser parser;
   auto header = parser.parse(raw_header);

   BOOST_CHECK_EQUAL(header["Host"], "net.tutsplus.com");
   BOOST_CHECK_EQUAL(header["User-Agent"],
                     "Mozilla/5.0 (Windows; U; Windows "
                     "NT 6.1; en-US; rv:1.9.1.5) "
                     "Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)");

   BOOST_CHECK_EQUAL(header["Accept"],
                     "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");

   BOOST_CHECK_EQUAL(header["Accept-Language"], "en-us,en;q=0.5");
   BOOST_CHECK_EQUAL(header["Accept-Encoding"], "gzip,deflate");
   BOOST_CHECK_EQUAL(header["Accept-Charset"],
                     "ISO-8859-1,utf-8;q=0.7,*;q=0.7");

   BOOST_CHECK_EQUAL(header["Keep-Alive"], "300");
   BOOST_CHECK_EQUAL(header["Connection"], "keep-alive");
   BOOST_CHECK_EQUAL(header["Cookie"], "PHPSESSID=r2t5uvjq435r4q7ib3vtdjq120");
   BOOST_CHECK_EQUAL(header["Pragma"], "no-cache");
   BOOST_CHECK_EQUAL(header["Cache-Control"], "no-cache");
 }

BOOST_AUTO_TEST_SUITE_END()


