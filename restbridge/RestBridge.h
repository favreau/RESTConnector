/* Copyright (c) 2014-2015, Human Brain Project
 *                          Grigori Chevtchenko <grigori.chevtchenko@epfl.ch>
 */

#ifndef RESTBRIDGE_RESTBRIDGE_H
#define RESTBRIDGE_RESTBRIDGE_H

#include <restbridge/types.h>
#include <boost/noncopyable.hpp>
#include <string>

namespace restbridge
{

namespace detail { class RestBridge; }

/**
 * The RestBridge class is responsible starting a HTTP server
 * in a dedicated thread, according to a given hostname and port.
 * HTTP requests are forwarded to an implicitely registered handler.
 */
class RestBridge : public boost::noncopyable
{
public:
    /**
     * Default constructor.
     * @param hostname Hostname or IP address
     * @param port Listening port
     */
    RestBridge( const std::string& hostname, const uint16_t port );

    ~RestBridge();

    /**
     * Listening to HTTP requests and forwarding them to the handler in
     * a dedicated thread.
     * @param schema Schema prefix used by zeq publisher and subscriber
     * @throw std::runtime_error if HTTP server is already running or could not be started
     */
    void run( const std::string& schema );

    /**
     * Stop the HTTP server thread.
     * @throw std::runtime_error if HTTP server is not running
     */
    void stop();

private:
    detail::RestBridge* const _impl;
};

}
#endif // RESTBRIDGE_RESTBRIDGE_H