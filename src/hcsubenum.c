/*
*
* hcsubenum.c - contains the subdomain_enumeration() command
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
*
* ~~~~~~~~~~~~~[ What is Subdomain Enumeration ]~~~~~~~~~~~~~~~~~~~~~~
*
* A subdomain enumeration is a method of finding subdomains of a domain
* It's used for hacking, security or if you're really curious how someone's site works
* 
* Why are there multiple subdomains?:
* They cannot hide from us we'll know that they exist even if it's ns69420 or mysql1121191839
* 
* Education?:
* Check the subdomains array and learn where the subdomains are used for.
*
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*/

#pragma warning(disable : 6262)

#include "hcsubenum.h"
#include "stdheads.h"

void subdomain_enumeration(const char* f, const char* opts)
{
    /* It's messy */
    char subdomains[][64] = {
        // [0.1] www protocols
        "www", "www1", "www2", "www3", "ww1", "ww2", "ww3", "wwwl", "wwl",

        // [0.2] dev 0 - 30
        "dev0", "dev", "dev1", "dev2", "dev3", "dev4", "dev5", "dev6", "dev7", "dev8", "dev9", "dev10", "dev11", "dev12", "dev13", "dev14",
        "dev15", "dev16", "dev17", "dev18", "dev19", "dev20", "dev21", "dev22", "dev23", "dev24", "dev25", "dev26", "dev27", "dev28", "dev29", "dev30",

        // [0.3] ns 0 - 65
        "ns0", "ns", "ns1", "ns2", "ns3", "ns4", "ns5", "ns6", "ns7", "ns8", "ns9", "ns10", "ns11", "ns12", "ns13", "ns14", "ns15", "ns16",
        "ns17", "ns18", "ns19", "ns20", "ns21", "ns22", "ns23", "ns24", "ns25", "ns26", "ns27", "ns28", "ns29", "ns30", "ns31", "ns32",
        "ns33", "ns34", "ns35", "ns36", "ns37", "ns38", "ns39", "ns40", "ns41", "ns42", "ns43", "ns44", "ns45", "ns46", "ns47", "ns48",
        "ns49", "ns50", "ns51", "ns52", "ns53", "ns54", "ns55", "ns56", "ns57", "ns58", "ns59", "ns60", "ns61", "ns62", "ns63", "ns64", "ns65",

        // [0.4] mysql 0 - 30
        "mysql0", "mysql", "mysql1", "mysql2", "mysql3", "mysql4", "mysql5", "mysql6", "mysql7", "mysql8", "mysql9", "mysql10", "mysql11", "mysql12",
        "mysql13", "mysql14", "mysql15", "mysql16", "mysql17", "mysql18", "mysql19", "mysql20", "mysql21", "mysql22", "mysql23", "mysql24", "mysql25",
        "mysql26", "mysql27", "mysql28", "mysql29", "mysql30", "mysql31", "mysql32", "mysql33", "mysql34", "mysql35", "mysql36", "mysql37",

        // [0.5] dns 0 -  29
        "dns0", "dns", "dns1", "dns2", "dns3", "dns4", "dns5", "dns6", "dns7", "dns8", "dns9", "dns10", "dns11", "dns12", "dns13", "dns14", "dns15", "dns16", "dns17",
        "dns18", "dns19", "dns20", "dns21", "dns22", "dns23", "dns24", "dns25", "dns26", "dns27", "dns28", "dns29",

        // [0.5.1] Node 0 - 00
        "node0", "node", "node1", "node2", "node3", "node4", "node5", "node6",

        // Alphabet
        "a", "b", "c", "d", "e", "f", "g", "h", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",

        // Numbers
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",

        // [0.6] most common subdomains
        "about", "mail", "news", "images", "img", "cdn", "ftp", "billing", "landing", "blog", "wiki", "web",

        // Admin
        "admin", "adm", "myadmin", "phpmyadmin", "phpmyadmin1", "phpmyadmin2",

        // [0.7] databases
        "oracle", "azure", "sql", "sql1", "database", "mongodb", "dbadmin", "db", "docker", "mariadb",

        // [0.8] Store
        "shop", "store", "merch", "estore", "eshop", "order", "checkout", "cart", "pay", "shopping", "sale", "sales", "markt", "market", "marketplace", "deal", "deals", "dealling",
        "pricing", "shipping", "aparrel", "aparrell", "reseller", "resell", "your-orders", "manage-orders",

        // [0.9] other protocols
        "ssh", "ssl", "dhcp", "inet", "tcp", "voip", "ldap", "dcp", "p2p", "tor", "udp", "dtp", "smtp", "ntp", "proc",

        // [0.10] (I)nternet (P)rotocol
        "internet-protocol", "ip", "ipv4", "ipv6", "ip4", "ip5", "ips",

        // [0.11] Livestreaming
        "stream", "yt", "live", "tv", "iptv", "streaming", "sub",

        // [0.12] carrier subdomains
        "carrier", "jobs", "work", "carriers", "works", "apply",

        // [0.13] mail
        "exchange", "email", "thunderbird", "mailer", "write", "newmail", "mail0", "mail1", "mail2", "mail3", "mail4", "mail5", "mail6", "mail7", "e-mail",

        // File Storages
        "drive", "dropbox", "static", "media", "photos", "video", "mirror", "archive", "pic", "gif", "scripts", "script", "documents", "mirrors", "source",

        // [0.15] cloud
        "cloud", "aws", "cloudflare",

        // [0.16] chat & call
        "meet", "call", "contact", "chat", "msg", "message", "messager", "slack", "conference",

        // Adverticements
        "promote", "ads", "promo", "promotion", "redirect", "ad", "traffic", "click", "marketing", "opt", "adsense", "admob"

        // [0.18] Education
        "edu", "education", "academy", "learn", "learning", "elearning", "uni", "university", "college", "schools", "school", "student", "students", "classroom", "class",
        "netacad", "knowledge",

        // [0.19] virtualisation
        "vm", "virtual", "vcenter", "virtual", "vsphere", "vps", "vpn", "vpn1", "vpn2", "citrix", "proxmox",

        // [0.20] news
        "newsletter", "blogs", "post", "posts", "feed", "article", "newsletter",

        // [0.21] Legal
        "legal", "privacy", "tos", "cookies", "policy", "police", "law", "rules", "licensing", "license", "gov", "goverment", "copyright",

        // [0.22] hosting
        "nginx", "apache", "hosting", "bluemix", "server", "server01", "server02", "wordpress", "wp", "wikimedia", "godaddy", "wix", "jimdo",

        // File Ext
        "css", "js", "doc", "php", "pdf", "cpp", "c", "html", "style", "svn", "svg",

        // [0.24] Shell-related
        "system", "computer", "console", "shell", "root", "fs", "sh", "ping",

        // [0.25] NSFW / Dating 
        "love", "dating", "sex", "porn", "xxx", "xx", "18", "cupid", "iloveyou", "wedding", "marrige", "pp", "gambling", "casino", "drugs", "nightlife", "win", "getnow", "adults", 

        // [0.26] Corperation
        "corp", "corperation", "corperate", "holding", "incorperated", "inc", "llc", "limmited",

        // [0.27] Developer
        "develop", "developer", "ide", "git", "software", "coding", "code", "scripting", "webdev", "oss", "developers", "xyz", "api", "apis", "docs", "flags", "flag",
        "opensource", "open-source", "computing", "master", "tools", "dev-buisness", "sso", "seo",

        // [0.28] Gender
        "male", "female", "man", "woman", "men", "boy", "girl", "boys", "girls", "mother", "father", "mom", "dad",

        // [0.29] Support
        "helpdesk", "support", "bugs", "issues", "issue", "report", "forum", "asks", "ask", "ticket", "manual", "gethelp", "infocenter", "service-desk", "servicedesk",

        // [0.30] Music Entertainment
        "music", "radio", "listen", "listening", "songs", "song", "sound", "sounds", "lyrics", "fm", "shuffle", "stage", "instruments", "soundtrack", "soundtracks",

        // [0.31] Graphical Entertaiment
        "movie", "movies", "entertain", "entertainment", "filming", "recording", "film", "anime", "animations", "animation", "vfx", "sfx", "cgi", "watch",
        "studio", "studios", "tube", "vod", "cam", "cams", "camera", "webcams", "pictures", "cinema", "videos", "trailers", "trailer",
        "film", "films", "productions", "production", "television", "premere", "blockbuster", "primetime", "picture", "player", "stock", "fotos", "digital", "thumb", "sports",
        "esports", "e-sports", "dvd", "analog",

         // [0.32] LINUX
        "kali", "ubuntu", "darwin", "arch", "deb", "debian", "superuser", "linux", "gnu", "apt", "ls", "cd", "dpkg", "mkdir", "rm", "mv", "rmdir", "sudo", "su", "ps", "process", "processes",
        "touch", "nano", "vi", "vim", "neovim", "systemctl", "cp", "wget", "pkill", "kill", "net-tools", "ifconfig",

        // [0.33] Regions
        "union", "euro", "europe", "america", "asia", "africa", "australia", "nation", "east", "west", "south", "north", "center", "central", "us-east", "us-west", "us-sorth", "us-north",
        "eu-sorth", "eu-north", "eu-west", "eu-east", "united", "latin", "earth", "moon", "sun",

        // [0.34] Network Related
        "imap", "eth", "ethernet", "loopback", "nat", "nas", "client", "clients", "iot", "nmap", "network", "networks", "internet", "url", "hotspot",
        "gatekeeper", "remote", "router", "pfsense", "reciever",

        // [0.35] Account Managment
        "upload", "profile", "register", "members", "signup", "login", "dashboard", "guest", "accounts", "account", "moderation", "myaccount",

        // [0.36] Health
        "health", "heatlthy", "together", "trust", "trusted", "safety", "safe", "care", "friends", "bio", "connect", "insurance", "meds", "medical", "hospital", "ambulance",

        // [0.37] Information
        "information", "info", "newsroom", "guide", "infopoint",

        // [0.38] Plattforms
        "mobile", "phones", "desktop", "unix", "mac", "iphone", "android", "phone", "browser", "app", "apps", "application", "applications",

        // [0.39] Security
        "oauth", "auth", "oauth2", "spy", "spying", "cyber", "cybersecurity", "hacking", "hack", "hacked", "secure", "gateway", "midway-gateway", "proxy0", "proxy", "proxy1", "proxies", "proxy-ratelimmit", "security",
        "certification", "certifications", "certificates", "cert", "firewall", "tracking", "captcha", "hacker", "gate", "ctf0", "ctf", "ctf1", "sync", "protect", "protection",
        "void", "voided", "backup", "monitor", "monitoring", 

        // [0.40] Game Entertainment
        "games", "gaming", "play", "arcade", "chess",

        // [0.41] Exclusive
        "pro", "premium", "subscribe", "vip", "mvp", "exclusive", "prime", "unsubscribe", "deluxe", "special", "specials", "expensive", "membership", "memberships", "pass",

        // [0.42] Words for Intern
        "localhost", "intern", "intranet", "hidden", "private",

        // [0.43] Site
        "sitemap", "site", "sites", "pages", "page", "paper", "papers",

        // [0.44] Book Entertainment
        "manga", "books", "book", "ebook", "ebooks", "art", "artist", "artwork",

        // [0.45] HTTPS
        "get", "404", "403", "0", "124", "16", "64", "8080", "80",

        // DUMMYS
        "test", "test1", "test2", "123", "1234", "abc", "abcd", "gay", "dumb", "idiot", "secret", "dummy", "dummy1", "spam0", "spam", "spam1",

        // Family
        "family", "child", "kids", "children",

        // Configuration
        "manager", "settings", "config", "manage", "managment", "my", "controller", "control",

        // Finance
        "finance", "wallet", "bank", "card",

        // Version
        "beta", "alpha", "classic", "ver", "version", "old", "new", "nightly", "stable", "unstable", "insiders",

        // Document based
        "copy", "paste", "cut", "office", "edit", "editing", "view",

        // Cores
        "home", "base", "start", "portal", "core", "kernel", "hub", 

        // Company
        "company", "staff", "employee", "press", "inpress", "invoices", "tech", "technology", "publishing", "publisher", "inventions", "investors", "projects",
        "enterprise", "buisness", "vision", "catalogue", "discovery", "service", "credit", "origin", "stocks", "history", "creative", "structure", "mission", "workplace",
        "workplaces", "workdesk", "readme",

        // Maps & GPS
        "navigation", "navi", "gps", "maps", "map", "places",

        // Metrics
        "metrics", "stats", "status", "analytics",

        // Socials
        "social", "socials", "youtube", "twitter", "github", "gitlab", "facebook", "linkedin", "xing", "maestroden", "discord",

        // File Managment
        "files", "file", "save", "publish", "update", "create", "install", "load", "loading", "planning", "plan", "download", "dnl", "list", "lists", "open", "close",

        // Companies
        "google", "hp", "microsoft", "adobe", "ibm", "apple", "netflix", "cisco", "mgsql", "htb", "ph", "amazon", "xbox", "playstation", "valve", "steam", "ubisoft", "nasa",
        "intel", "amd", "nvidia", "meta", "mg", "siemens", "phillips", "bosch", "unity", "nova", "bk", "kfc", "cinnabon", "nintendo", "unreal", "unreal-engine",
        "w3", "nfl", "nba", "sony", "nbc", "comcast", "wb", "sme", "wmg", "umg", "nbcuniversal", "bbc", "steampovered", "airlines", "auto", "automobility", "car", "transport",

        // Applications
        "todo", "calender", "calculator", "board", "weather", "task", "tasks", "date", "dates", "launch", "launcher", "time", "math", "powerpoint", "excel", "access", "word",
        "chrome",

        // Research
        "search", "lab", "labs", "research", "tests", "sample",

        // Internal
        "internal", "printer", "printers", "classified", "personal", "disclosed",

        // Music gernes
        "edm", "chill", "tropical", "hiphop", "trap", "bass", "house", "deephouse",

        // Places
        "event", "events", "hotel", "hotels", "vacation", "vacations", "museum",

        // Resources
        "resource", "repo", "lib", "content", "library", "data", "datacenter", "data-center",

        // Collaboration
        "collaboration", "collab", "anydesk", "teamviewer", "team-viewer", "rat",

        // AI / Mashine Learning
        "cuda", "ai", "deep", "robot", "robots", "mashine", "mashine-learning",

        // Colors
        "red", "blue", "yellow", "green", "white", "black", "orange", "pink", "purple", "cyan", "gold", "crimson",

        "extern", "vs", "preview", "link", "linked", "awp", "originals", "collections", 
        "local", "cats", "cat", "res", "mc", "now", "transfer", "rate", "rating", 
        "contest", "build", "this", "public", "host", "net", "online", "io", "your", "you", "box", "science", "chemie", "thanks", "ocean",
        "carrd", "sender", "direct", "directory", "fresh", "banner", "recieve", "hireme", "heaven", "kitchen", "recept", "cc",

        // Language subdomains
        "intertional", "de", "en", "nl", "jp", "gr", "es", "au", "fr", "us", "uk", "ca", "com", "it", "es", "gg", "at", "ch", "co", "mx", "bg",
    };

    const int arrc = sizeof(subdomains) / sizeof(subdomains[0]);
    int founddomains = 0;

    clock_t begin = clock();

    printf("Following subdomains has been found for %s\n", f);

#if __unix
    for (int i = 0; i < arrc; i++) {
        char cmd[0x080];
        strcpy(cmd, "ping -c 1");
        strcat(cmd, subdomains[i]);
        strcat(cmd, ".");
        strcat(cmd, f);
        strcat(cmd, " > /dev/null");

        if (system(cmd) == 0x00) {
            printf("%s.%s\n", subdomains[i], f);
            founddomains++;
        }
    }
#else
    for (int i = 0; i < arrc; i++) {
        char cmd[0x080];
        strcpy(cmd, "ping -n 1 ");
        strcat(cmd, subdomains[i]);
        strcat(cmd, ".");
        strcat(cmd, f);
        strcat(cmd, " > nul");

        if (system(cmd) == 0x00) {
            printf("%s.%s\n", subdomains[i], f);
            founddomains++;
        }
    }
#endif
    clock_t end = clock();
    printf("%d founded subdomains for %s [%fs]\n", founddomains, f, (double)(end - begin) / CLOCKS_PER_SEC);
}