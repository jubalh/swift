/*
 * Copyright (c) 2010 Remko Tronçon
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "SwifTools/Linkify.h"

using namespace Swift;

class LinkifyTest : public CppUnit::TestFixture {
		CPPUNIT_TEST_SUITE(LinkifyTest);
		CPPUNIT_TEST(testLinkify_URLWithResource);
		CPPUNIT_TEST(testLinkify_HTTPSURLWithResource);
		CPPUNIT_TEST(testLinkify_URLWithEmptyResource);
		CPPUNIT_TEST(testLinkify_BareURL);
		CPPUNIT_TEST(testLinkify_URLSurroundedByWhitespace);
		CPPUNIT_TEST(testLinkify_MultipleURLs);
		CPPUNIT_TEST(testLinkify_CamelCase);
		CPPUNIT_TEST(testLinkify_HierarchicalResource);
		CPPUNIT_TEST(testLinkify_Anchor);
		CPPUNIT_TEST(testLinkify_Plus);
		CPPUNIT_TEST(testLinkify_Tilde);
		CPPUNIT_TEST(testLinkify_Equal);
		CPPUNIT_TEST(testLinkify_Authentication);
		CPPUNIT_TEST(testLinkify_At);
		CPPUNIT_TEST(testLinkify_Amps);
		CPPUNIT_TEST_SUITE_END();

	public:
		void testLinkify_URLWithResource() {
			String result = Linkify::linkify("http://swift.im/blog");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://swift.im/blog\">http://swift.im/blog</a>"),
					result);
		}

		void testLinkify_HTTPSURLWithResource() {
			String result = Linkify::linkify("https://swift.im/blog");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"https://swift.im/blog\">https://swift.im/blog</a>"),
					result);
		}

		void testLinkify_URLWithEmptyResource() {
			String result = Linkify::linkify("http://swift.im/");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://swift.im/\">http://swift.im/</a>"),
					result);
		}


		void testLinkify_BareURL() {
			String result = Linkify::linkify("http://swift.im");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://swift.im\">http://swift.im</a>"),
					result);
		}

		void testLinkify_URLSurroundedByWhitespace() {
			String result = Linkify::linkify("Foo http://swift.im/blog Bar");

			CPPUNIT_ASSERT_EQUAL(
					String("Foo <a href=\"http://swift.im/blog\">http://swift.im/blog</a> Bar"),
					result);
		}

		void testLinkify_MultipleURLs() {
			String result = Linkify::linkify("Foo http://swift.im/blog Bar http://el-tramo.be/about Baz");

			CPPUNIT_ASSERT_EQUAL(
					String("Foo <a href=\"http://swift.im/blog\">http://swift.im/blog</a> Bar <a href=\"http://el-tramo.be/about\">http://el-tramo.be/about</a> Baz"),
					result);
		}

		void testLinkify_CamelCase() {
			String result = Linkify::linkify("http://fOo.cOm/bAz");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://fOo.cOm/bAz\">http://fOo.cOm/bAz</a>"),
					result);
		}

		void testLinkify_HierarchicalResource() {
			String result = Linkify::linkify("http://foo.com/bar/baz/");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://foo.com/bar/baz/\">http://foo.com/bar/baz/</a>"),
					result);
		}

		void testLinkify_Anchor() {
			String result = Linkify::linkify("http://foo.com/bar#baz");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://foo.com/bar#baz\">http://foo.com/bar#baz</a>"),
					result);
		}

		void testLinkify_Plus() {
			String result = Linkify::linkify("http://foo.com/bar+baz");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://foo.com/bar+baz\">http://foo.com/bar+baz</a>"),
					result);
		}

		void testLinkify_Tilde() {
			String result = Linkify::linkify("http://foo.com/~kev/");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://foo.com/~kev/\">http://foo.com/~kev/</a>"),
					result);
		}

		void testLinkify_Equal() {
			String result = Linkify::linkify("http://www.amazon.co.uk/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=xmpp+definitive+guide&x=0&y=0");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://www.amazon.co.uk/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=xmpp+definitive+guide&x=0&y=0\">http://www.amazon.co.uk/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=xmpp+definitive+guide&x=0&y=0</a>"),
					result);
		}

		void testLinkify_Authentication() {
			String result = Linkify::linkify("http://bob:bla@swift.im/foo/bar");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://bob:bla@swift.im/foo/bar\">http://bob:bla@swift.im/foo/bar</a>"),
					result);
		}

		void testLinkify_At() {
			String result = Linkify::linkify("http://swift.im/foo@bar");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://swift.im/foo@bar\">http://swift.im/foo@bar</a>"),
					result);
		}

		void testLinkify_Amps() {
			String result = Linkify::linkify("http://swift.im/foo&bar&baz");

			CPPUNIT_ASSERT_EQUAL(
					String("<a href=\"http://swift.im/foo&bar&baz\">http://swift.im/foo&bar&baz</a>"),
					result);
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(LinkifyTest);
