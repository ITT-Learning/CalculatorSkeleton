#include <iostream>
#include <filesystem>

#include <boost/utility/string_ref.hpp>

#include "HttpRequestHandler.h"

namespace calculator { namespace httpserver
{

void HttpRequestHandler::onRequest(const Pistache::Http::Request& req, Pistache::Http::ResponseWriter response)
{
    boost::string_ref resourceStringRef{req.resource()};
    if(resourceStringRef.starts_with(API_PREFIX))
    {
        auto apiResource = resourceStringRef.substr(5, resourceStringRef.length() - 5);
        if(apiResource.starts_with(API_LIST_PREFIX) && req.method() == Pistache::Http::Method::Get)
        {
            // TODO
        }
        else if(apiResource.starts_with(API_STORE_PREFIX) && req.method() == Pistache::Http::Method::Post)
        {
            // TODO
        }
        else if(apiResource.starts_with(API_CALCULATE_PREFIX) && req.method() == Pistache::Http::Method::Post)
        {
            // TODO
        }
    }
    else if(req.method() == Pistache::Http::Method::Get)
    {
        // We always iterate over the files in the file root directory to ensure that, even if a file is added or
        // removed after the server is started, the server will know of those changes. A caching solution would have
        // better performance, but that's some more work that I don't have the time for right now.
        std::filesystem::path fileRootDirectoryPath{FILE_ROOT_DIRECTORY};
        std::filesystem::recursive_directory_iterator fileRootDirectoryIterator{fileRootDirectoryPath};
        bool fileFound = false;
        for(const auto &currentFile : fileRootDirectoryIterator)
        {
            const auto &filePath = currentFile.path();
            std::cout << filePath.string() << std::endl;
            boost::string_ref filePathStringRef{filePath.string()};
            if(filePathStringRef.ends_with(resourceStringRef))
            {
                Pistache::Http::serveFile(response, filePathStringRef.to_string());
                fileFound = true;
                break;
            }
            fileRootDirectoryIterator++;
        }
    }
    else
    {
        // we couldn't do anything with the request
    }
}

}}