/*
 * Copyright (c) 2010 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/filesystem/path.hpp>

#include "Swiften/Disco/CapsStorage.h"
#include <string>

namespace Swift {
	class CapsFileStorage : public CapsStorage {
		public:
			CapsFileStorage(const boost::filesystem::path& path);

			virtual DiscoInfo::ref getDiscoInfo(const std::string& hash) const;
			virtual void setDiscoInfo(const std::string& hash, DiscoInfo::ref discoInfo);

		private:
			boost::filesystem::path getCapsPath(const std::string& hash) const;

		private:
			boost::filesystem::path path;
	};
}
