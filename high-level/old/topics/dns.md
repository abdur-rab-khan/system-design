# Domain Name System (DNS)

> A Domain Name System (DNS) is a phonebook of the internet, which translates human-readable domain names (e.g., <www.example.com>) into machine-readable IP address (e.g., 142.250.70.68) that computers use to identify each other on the network.

- [Domain Name System (DNS)](#domain-name-system-dns)
  - [Overview](#overview)
  - [How DNS Works](#how-dns-works)
  - [Steps how DNS works](#steps-how-dns-works)
  - [Types of DNS Records](#types-of-dns-records)

## Overview

- Each device connected to the internet has a unique IP address that other devices use to find and communicate with it.
- DNS servers eliminate the need for humans to memorize IP addresses such as 142.250.70.68 (for Google). Instead, we use domain names like <www.google.com>, which are easier to remember.
- When you enter a domain name in your web browser, the browser sends a request to a DNS server to look up the corresponding IP address.
- IP address can be in IPv4 (e.g., 142.250.70.68) or IPv6 (e.g., 2607:f8b0:4005:805::2004) format.

## How DNS Works

- The process of DNS resolution involves converting a domain name into an IP address, every devices connected to the internet has a unique IP address.
- To communicate with each other, devices use IP addresses, but humans find it easier to remember domain names.

- When you enter a domain name in your web browser, the following steps occur:

  1. **DNS Query Initiation**: Your computer (the client) sends a DNS query to a DNS resolver (usually provided by your ISP or a third-party service like Google Public DNS).
  2. **Recursive Query**: The DNS resolver checks its cache to see if it already has the IP address for the requested domain name. If not, it performs a recursive query to find the IP address.
  3. **Root Name Server**: The resolver first contacts a root name server, which responds with the address of a top-level domain (TLD) name server (e.g., for .com, .org).
  4. **TLD Name Server**: The resolver then contacts the TLD name server, which responds with the address of the authoritative name server for the specific domain (e.g., example.com).
  5. **Authoritative Name Server**: Finally, the resolver contacts the authoritative name server, which provides the IP address associated with the requested domain name.
  6. **Response to Client**: The DNS resolver sends the IP address back to your computer, which can then use it to establish a connection to the web server hosting the website.

- To improve performance, DNS resolvers often cache the IP addresses they retrieve for a certain period (defined by the Time to Live, or TTL, value). This reduces the need for repeated queries for the same domain name.

  ![HOW DNS WORKS](https://imgs.search.brave.com/2hzT-17txGHhx27GjpjNLtI-EBUIZNFOWdSjqIKMJBI/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly93d3cu/aG9zdGluZ2VyLmNv/bS90dXRvcmlhbHMv/d3AtY29udGVudC91/cGxvYWRzL3NpdGVz/LzIvMjAyMy8wMS9o/b3ctZG9lcy1kbnMt/d29yay0xMDI0eDU5/MC5wbmc)

## Steps how DNS works

1. User types a domain name (e.g., <www.example.com>) into their web browser.
2. The browser checks its local cache to see if it has recently resolved the domain name. If found, it uses the cached IP address.
3. If not found in the cache, the browser sends a DNS query to the configured DNS resolver (usually provided by the ISP).
4. The DNS resolver checks its cache for the IP address. If found, it returns the IP address to the browser.
5. If not found, the resolver sends a query to a root name server.
6. The root name server responds with the address of a top-level domain (TLD) name server (e.g., for .com).
7. The resolver then queries the TLD name server, which responds with the address of the authoritative name server for the specific domain (e.g., example.com).
8. The resolver queries the authoritative name server, which provides the IP address associated with the domain name.
9. The resolver sends the IP address back to the browser.
10. The browser uses the IP address to establish a connection to the web server and retrieves the requested web page.
11. The browser displays the web page to the user.

## Types of DNS Records

| Record Type  | Description                                                          | Example                                                |
| ------------ | -------------------------------------------------------------------- | ------------------------------------------------------ |
| A Record     | Maps a domain name to an IPv4 address.                               | example.com -> 148.18.10.0                             |
| AAAA Record  | Maps a domain name to an IPv6 address.                               | example.com -> 2001:0db8::1                            |
| CNAME Record | Maps a domain name to another domain name.                           | www.example.com -> example.com                         |
| MX Record    | Specifies the mail servers for a domain.                             | example.com -> mail.example.com                        |
| TXT Record   | Holds text information for various purposes.                         | example.com -> "v=spf1 include:\_spf.example.com ~all" |
| NS Record    | Specifies the authoritative name servers (DNS servers) for a domain. | example.com -> ns1.example.com, ns2.example.com        |
