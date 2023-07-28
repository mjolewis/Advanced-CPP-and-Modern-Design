//
// Simple illustration of how to use tags with BiMaps to make the code easier to read and work with
//
// Created by Michael Lewis on 7/28/23.
//

#include <iostream>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

// Create tags for readability
struct IPAddress{};
struct DomainName{};

// Part A - Create a bimap with tags IpAddress and DomainName whose left and right
// containers are unordered sets. Model domain names as strings and IP addresses as Boost UUID instances.
typedef boost::bimap
        <
                boost::bimaps::unordered_set_of<boost::bimaps::tagged<boost::uuids::uuid, DomainName>>,
                boost::bimaps::unordered_set_of<boost::bimaps::tagged<std::string, IPAddress>>,
                boost::bimaps::list_of_relation
        > DNS;


void printDNS(const DNS& dns)
{
    for (DNS::const_iterator it = dns.begin(), end = dns.end(); it != end; ++it)
    {
        std::cout << it->get<DomainName>() << "<--->" << it->get<IPAddress>() << std::endl;
    }
}

int main()
{
    // Part B - Create some instances of DNS. Find a domain name for a given IP
    // address and find an IP address for a given domain name.
    DNS dnsDB;

    // Create UUIDs
    boost::uuids::string_generator generator;
    boost::uuids::uuid uuid1 = generator("12345678-1234-1234-1234-123456789123");
    boost::uuids::uuid uuid2 = generator("12345678-0000-0000-0000-123456789123");

    std::string domain1{"quantnet.com"};
    std::string domain2{"cppreference.com"};
    dnsDB.push_back(DNS::value_type(uuid1, domain1));
    dnsDB.push_back(DNS::value_type(uuid2, domain2));

    DNS::map_by<DomainName>::const_iterator name = dnsDB.by<DomainName>().find(uuid1);
    DNS::map_by<IPAddress>::const_iterator ip = dnsDB.by<IPAddress>().find(domain2);

    if (name != dnsDB.by<DomainName>().end())
    {
        std::cout << uuid1 << name->get<IPAddress>() << std::endl;
    }

    if (ip != dnsDB.by<IPAddress>().end())
    {
        std::cout << domain2 << " : " << ip->get<DomainName>()  << std::endl;
    }

    // Part C - Create a function to print the contents of the DNS ‘database’.
    printDNS(dnsDB);

    return 0;
}
