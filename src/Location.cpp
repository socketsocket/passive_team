#include <iostream>
#include "Location.hpp"
#include "TermPrinter.hpp"

Location::Location(const Location& ref)
	: path(ref.path),
	  root(ref.root),
	  indexes(ref.indexes),
	  auto_index(ref.auto_index),
	  error_pages(ref.error_pages),
	  methods_allowed(ref.methods_allowed),
	  cgi_infos(ref.cgi_infos),
	  return_to(ref.return_to) {}


Location::Location(
	std::string path,
	std::string root,
	std::vector<std::string> indexes,
	bool auto_index,
	std::map<stat_type, std::string> error_pages,
	Method methods_allowed,
	std::map<std::string, std::string> cgi_infos,
	std::pair<stat_type, std::string> return_to)
	: path(path),
	  root(root),
	  indexes(indexes),
	  auto_index(auto_index),
	  error_pages(error_pages),
	  methods_allowed(methods_allowed),
	  cgi_infos(cgi_infos),
	  return_to(return_to) {}

Location::~Location() {}

const std::string& Location::getPath() const {
	return this->path;
}

const std::string& Location::getRoot() const {
	return this->root;
}

Method Location::getMethodsAllowed() const {
	return this->methods_allowed;
}

const std::vector<std::string>& Location::getIndexes() const {
	return this->indexes;
}

const bool& Location::isAutoIndex() const {
	return this->auto_index;
}

const std::map<stat_type, std::string>& Location::getDefaultErrorPages() const {
	return this->error_pages;
}

const std::string Location::getDefaultErrorPage(stat_type stat) const {
	if (this->error_pages.count(stat))
		return (*this->error_pages.find(stat)).second;
	else
		return "";
};

const std::string		Location::getCgiBinary(std::string extension) const {
	for (std::map<std::string, std::string>::const_iterator it = this->cgi_infos.begin();
	it != this->cgi_infos.end(); ++it) {
		if (it->first == "." + extension)
			return it->second;
	}
	return "";
}

const std::map<std::string, std::string>&	Location::getCgiInfos() const {
	return this->cgi_infos;
}

std::pair<stat_type, std::string>	Location::getReturnTo() const {
	return this->return_to;
}